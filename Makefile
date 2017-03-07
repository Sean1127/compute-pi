CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall -fopenmp -mavx -g
EXECUTABLE = \
	time_test_baseline time_test_openmp_2 time_test_openmp_4 \
	time_test_avx time_test_avxunroll time_test_monte_carlo \
	benchmark_clock_gettime clock_test benchmark_error

GIT_HOOKS := .git/hooks/pre-commit

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

default: $(GIT_HOOKS) computepi.o
	$(CC) $(CFLAGS) computepi.o time_test.c -DBASELINE -o time_test_baseline
	$(CC) $(CFLAGS) computepi.o time_test.c -DOPENMP_2 -o time_test_openmp_2
	$(CC) $(CFLAGS) computepi.o time_test.c -DOPENMP_4 -o time_test_openmp_4
	$(CC) $(CFLAGS) computepi.o time_test.c -DAVX -o time_test_avx
	$(CC) $(CFLAGS) computepi.o time_test.c -DAVXUNROLL -o time_test_avxunroll
	$(CC) $(CFLAGS) computepi.o time_test.c -DMONTE_CARLO -o time_test_monte_carlo
	$(CC) $(CFLAGS) computepi.o benchmark_clock_gettime.c -o benchmark_clock_gettime
	$(CC) $(CFLAGS) computepi.o benchmark_error.c -o benchmark_error

.PHONY: clean default

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@ 

check: default
	time ./time_test_baseline
	time ./time_test_openmp_2
	time ./time_test_openmp_4
	time ./time_test_avx
	time ./time_test_avxunroll
	time ./time_test_monte_carlo

gencsv: default
	for i in `seq 5000 5000 1000000`; do \
		printf "%d " $$i;\
		./benchmark_clock_gettime $$i; \
	done > result_clock_gettime.csv
	for i in `seq 5000 5000 1000000`; do \
		printf "%d " $$i;\
		./benchmark_error $$i; \
	done > result_error.csv

plot: gencsv
	gnuplot scripts/time.gp
	gnuplot scripts/error.gp

clean:
	rm -f $(EXECUTABLE) *.o *.s *.csv *.png benchmark_error
