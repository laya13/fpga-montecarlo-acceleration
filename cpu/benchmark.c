#include <stdio.h>
#include <time.h>
#include "montecarlo.c"
#include "blackscholes.c"

/* Measures runtime and throughput of Monte Carlo simulation.
   METRICS:
   - execution time
   - simulations per second
 */

int main(int argc, char *argv[]) {

    int N = 1000000; // default

    if (argc > 1) {
        N = atoi(argv[1]);
    }

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    double price = monte_carlo_price(N);
    double bs_price =
    black_scholes_call(
        100.0,
        100.0,
        0.05,
        0.2,
        1.0
    );

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    double abs_error = fabs(price - bs_price);
    double rel_error = abs_error / bs_price;

    printf("%d,%f,%f,%f,%f,%f,%f\n",
       N,
       price,
       bs_price,
       abs_error,
       rel_error,
       time_taken,
       N / time_taken);

    return 0;
}