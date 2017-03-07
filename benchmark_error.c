#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "computepi.h"

#define CLOCK_ID CLOCK_PROCESS_CPUTIME_ID
#define ONE_SEC 1000000000.0
#define loop 25

int main(int argc, char const *argv[])
{
    if (argc < 2) return -1;

    int N = atoi(argv[1]);
    double pi = 3.141592653589793238462643;
    double estimate;

    // Baseline
    estimate = compute_pi_baseline(N);
    printf("%lf ", (pi - estimate) / estimate);

    // OpenMP with 2 threads
    estimate =  compute_pi_openmp(N, 2);
    printf("%lf ", (pi - estimate) / estimate);

    // OpenMP with 4 threads
    estimate = compute_pi_openmp(N, 4);
    printf("%lf ", (pi - estimate) / estimate);

    // AVX SIMD
    estimate = compute_pi_avx(N);
    printf("%lf ", (pi - estimate) / estimate);

    // AVX SIMD + Loop unrolling
    estimate = compute_pi_avx_unroll(N);
    printf("%lf ", (pi - estimate) / estimate);

    // Monte Carlo
    estimate = compute_pi_monte_carlo(N);
    printf("%lf\n", (pi - estimate) / estimate);

    return 0;
}
