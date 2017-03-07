#include <stdio.h>
#include <time.h>   //  for clock_gettime()
#include <limits.h>  //  for RAND_MAX
#include <omp.h>    //  for OpenMP

double compute_pi_baseline(size_t N);
double compute_pi_openmp(size_t N, int threads);
double compute_pi_avx(size_t N);
double compute_pi_avx_unroll(size_t N);
double compute_pi_monte_carlo(size_t N);
double compute_pi_monte_omp(size_t N, int threads);
