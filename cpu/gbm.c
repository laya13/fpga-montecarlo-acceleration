#include <math.h>

/* Geometric Brownian Motion (GBM) Stock Price Model

   Models future stock price evolution under randomness.
  
   S_T = S_0 * exp((r - 0.5(sigma)^2)T + sigma√T * Z)

   S_T = future stock price
   S_0 = current stock price
   r   = risk-free rate
   sigma   = volatility
   T   = time to maturity
   Z   = standard normal random variable
 */

double S0 = 100.0;
double r = 0.05;
double sigma = 0.2;
double T = 1.0;

double compute_stock_price(double Z) {
    double drift = (r - 0.5 * sigma * sigma) * T;
    double diffusion = sigma * sqrt(T) * Z;

    return S0 * exp(drift + diffusion);
}