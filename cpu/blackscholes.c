#include <math.h>
#include "blackscholes.h"

/*
 * Standard Normal CDF
 *
 * N(x) = probability that a standard normal
 * random variable is less than x.
 *
 * erf() is provided by math.h
 */

double normal_cdf(double x)
{
    return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

/*
 * Black-Scholes European Call Option
 *
 * C = S*N(d1) - K*e^(-rT)*N(d2)
 */

double black_scholes_call(
    double S,
    double K,
    double r,
    double sigma,
    double T)
{
    double d1 =
        (log(S / K)
        + (r + 0.5 * sigma * sigma) * T)
        / (sigma * sqrt(T));

    double d2 =
        d1 - sigma * sqrt(T);

    return
        S * normal_cdf(d1)
        - K * exp(-r * T) * normal_cdf(d2);
}
