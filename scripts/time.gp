reset
set xlabel 'N'
set ylabel 'time(sec)'
set style line 1 pt 0
set style line 2 pt 0
set style line 3 pt 0
set style line 4 pt 0
set style line 5 pt 0
set style line 6 pt 0
set style increment user
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'time.png'

plot "result_clock_gettime.csv" using 1:2 title 'baseline' with linespoints smooth cspline, \
"result_clock_gettime.csv" using 1:3 title 'openmp x2' with linespoints smooth cspline, \
"result_clock_gettime.csv" using 1:4 title 'openmp x4' with linespoints smooth cspline, \
"result_clock_gettime.csv" using 1:5 title 'avx' with linespoints smooth cspline, \
"result_clock_gettime.csv" using 1:6 title 'avx w/loop unrolling' with linespoints smooth cspline, \
"result_clock_gettime.csv" using 1:7 title 'monte carlo' with linespoints smooth cspline
