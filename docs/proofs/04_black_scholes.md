# Black-Scholes European Call Pricing

## Purpose

Black-Scholes provides an analytical reference value for the Monte Carlo implementation.

The Monte Carlo simulation does not have an exact output because it estimates an expectation using random samples. Black-Scholes allows the simulated result to be checked against a known analytical solution.

## Formula

For a European call option:

$$
C=S_0N(d_1)-Ke^{-rT}N(d_2)
$$

where:

$$
d_1=
\frac{
\ln(S_0/K)+(r+\frac{1}{2}\sigma^2)T
}{
\sigma\sqrt{T}
}
$$

and:

$$
d_2=d_1-\sigma\sqrt{T}
$$

$N(x)$ is the cumulative distribution function of the standard normal distribution.

## Parameters

* $S_0$ = initial stock price
* $K$ = strike price
* $r$ = risk-free interest rate
* $\sigma$ = volatility
* $T$ = time to expiration

## Validation

The CPU Monte Carlo result will be compared against the Black-Scholes price.

Absolute error:

$$
E_{\text{abs}}=
|C_{MC}-C_{BS}|
$$

Relative error:

$$
E_{\text{rel}}=
\frac{|C_{MC}-C_{BS}|}{C_{BS}}
$$

The FPGA implementation will later be evaluated using the same comparison.

## Example Parameters

The initial implementation uses:

$$
S_0=100
$$

$$
K=100
$$

$$
r=0.05
$$

$$
\sigma=0.20
$$

$$
T=1
$$

The Black-Scholes result provides the reference value against which Monte Carlo convergence can be evaluated.
