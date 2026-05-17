#include <math.h>
#include <stdlib.h>
#include <time.h>

/* Gaussian Random Number Generator (Box–Muller Transform)

   Converts uniformly distributed random numbers into normally
   distributed random variables Z ~ N(0,1).

   noise to simulate realistic stock price movements.

   Z = sqrt(-2 ln(U1)) * cos(2πU2)
   where U1, U2 ~ Uniform(0,1)

   This is computationally expensive (log, sqrt, trig),

 */

double gaussian_rand() {
    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    return sqrt(-2.0 * log(U1)) * cos(2.0 * M_PI * U2);
}