#include <math.h>
#include <stdio.h>
#include "rng.c"
#include "gbm.c"
#include "payoff.c"

/* Estimates European call option price using random simulation.
 
   IDEA:
   1. Simulate many possible future stock prices
   2. Compute payoff for each simulation
   3. Average results
   4. Discount back to present value
  
   Price = e^(-rT) * (1/N) Σ max(S_T(i) - K, 0)

   This is the CPU baseline that FPGA implementation will accelerate.
 */

double monte_carlo_price(int N) {
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        double Z = gaussian_rand();           // RNG stage
        double ST = compute_stock_price(Z);   // GBM stage
        double payoff = compute_payoff(ST);   // payoff stage

        sum += payoff;
    }
    double avg_payoff = sum / N;
    return exp(-r * T) * avg_payoff;
}