# Monte Carlo Option Pricing

## European Call Payoff

For a European call option, the payoff at maturity is:

$$
P(S_T)=\max(S_T-K,0)
$$

where $K$ is the strike price.

## Expected Payoff

Under risk-neutral pricing, the option value is the discounted expected payoff:

$$
C=e^{-rT}E[\max(S_T-K,0)]
$$

Monte Carlo estimates this expectation using $N$ independent simulations:

$$
C_N
===

e^{-rT}
\frac{1}{N}
\sum_{i=1}^{N}
\max(S_T^{(i)}-K,0)
$$

where each $S_T^{(i)}$ is generated using the GBM equation.

## Algorithm

For each simulation:

1. Generate $Z_i\sim N(0,1)$.
2. Calculate $S_T^{(i)}$ using GBM.
3. Calculate $\max(S_T^{(i)}-K,0)$.
4. Add the payoff to the accumulator.

After all simulations:

$$
C_N
===

e^{-rT}\frac{\text{total payoff}}{N}
$$

## FPGA Relevance

Each simulation is independent.

Therefore, multiple simulations can be assigned to separate hardware lanes:

```text
Lane 1 → Simulation 1
Lane 2 → Simulation 2
Lane 3 → Simulation 3
...
Lane N → Simulation N
```

This is the primary source of parallelism in the FPGA implementation.
