#include <stdio.h>
#include <time.h>
#include "montecarlo.c"

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

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("%d,%f,%f,%f\n",
       N,
       time_taken,
       price,
       N / time_taken);

    return 0;
}