# Geometric Brownian Motion

## Model

The stock price is modeled using the stochastic differential equation:

$$
dS_t = \mu S_t,dt + \sigma S_t,dW_t
$$

where:

* $S_t$ = stock price at time $t$
* $\mu$ = drift
* $\sigma$ = volatility
* $W_t$ = Wiener process

For option pricing under the risk-neutral measure, $\mu$ is replaced by the risk-free rate $r$:

$$
dS_t = rS_t,dt + \sigma S_t,dW_t
$$

## Derivation

Applying Itô's lemma to $\ln(S_t)$:

$$
d\ln(S_t)
=========

\left(r-\frac{1}{2}\sigma^2\right)dt
+
\sigma dW_t
$$

Integrating from $0$ to $T$:

$$
\ln\left(\frac{S_T}{S_0}\right)
===============================

\left(r-\frac{1}{2}\sigma^2\right)T
+
\sigma W_T
$$

Since:

$$
W_T = \sqrt{T}Z
$$

where:

$$
Z\sim N(0,1)
$$

we obtain:

$$
S_T
===

S_0
\exp\left[
\left(r-\frac{1}{2}\sigma^2\right)T
+
\sigma\sqrt{T}Z
\right]
$$

## Implementation

This is the equation used by the one-step GBM implementation in the CPU baseline.

The random variable $Z$ is generated using the Box-Muller transform.

## Why It Matters

The GBM equation converts a normally distributed random variable into a simulated future stock price. Each independent value of $Z$ therefore produces an independent simulated price path.

This independence is what allows the simulations to be parallelized on the FPGA.
