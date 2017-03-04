#include <stdio.h>
#include <time.h>
#include "computepi.h"

int main(int argc, char const *argv[])
{
    __attribute__((unused)) int N = 400000000;
    double pi = 0.0;
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    pi = compute_pi_openmp(N, 2);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("N = %d , pi = %lf\n", N, pi);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000000000.0);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    pi = compute_pi_openmp(N, 4);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("N = %d , pi = %lf\n", N, pi);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000000000.0);

    return 0;
}
