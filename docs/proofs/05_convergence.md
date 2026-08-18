# Monte Carlo Convergence

## Estimator

The Monte Carlo estimator is:

$$
C_N
===

e^{-rT}
\frac{1}{N}
\sum_{i=1}^{N}
P_i
$$

where:

$$
P_i=\max(S_T^{(i)}-K,0)
$$

## Law of Large Numbers

As the number of independent simulations increases:

$$
\frac{1}{N}\sum_{i=1}^{N}P_i
\rightarrow
E[P]
$$

Therefore:

$$
C_N\rightarrow C
$$

where $C$ is the true option value.

For this project, the Black-Scholes price is used as the analytical reference.

## Expected Behavior

Increasing $N$ should generally reduce Monte Carlo estimation error.

The standard Monte Carlo error decreases approximately as:

$$
O\left(\frac{1}{\sqrt{N}}\right)
$$

This means increasing the number of simulations by a factor of 100 only improves the statistical error by approximately a factor of 10.

## Engineering Implication

More simulations improve accuracy but increase computation time.

The FPGA accelerator attempts to reduce this cost by executing simulations in parallel.

Therefore, the important tradeoff is:

$$
\text{accuracy}
\leftrightarrow
\text{simulation count}
\leftrightarrow
\text{computational cost}
$$

The benchmark results will measure this tradeoff for both the CPU and FPGA implementations.
