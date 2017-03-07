#include <stdio.h>
#include "computepi.h"

int main(int argc, char const *argv[])
{
    __attribute__((unused)) int N = 400000000;
    double pi_real = 3.141592653589793238462643;
    double pi = 0.0;

#if defined(BASELINE)
    pi = compute_pi_baseline(N);
#endif

#if defined(OPENMP_2)
    pi = compute_pi_openmp(N, 2);
#endif

#if defined(OPENMP_4)
    pi = compute_pi_openmp(N, 4);
#endif

#if defined(AVX)
    pi = compute_pi_avx(N);
#endif

#if defined(AVXUNROLL)
    pi = compute_pi_avx_unroll(N);
#endif

#if defined(MONTE_CARLO)
    pi = compute_pi_monte_carlo(N);
#endif

#if defined(MONTE_OMP)
    pi = compute_pi_monte_omp(N, 2);
#endif

    printf("N = %d , pi = %.16lf\n", N, pi);
    printf("error = %.16lf\n", pi_real - pi);
    return 0;
}
