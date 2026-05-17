#include <math.h>

/* European Call Option Payoff Function

   Computes profit from exercising a call option at maturity.

   payoff = max(S_T - K, 0)

   S_T = stock price at maturity
   K   = strike price

   If stock price exceeds strike price -> profit
   Otherwise -> option expires worthless
 */

double K = 100.0;

double compute_payoff(double ST) {
    return fmax(ST - K, 0.0);
}