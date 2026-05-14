# Research Notes

---

# Black-Scholes Model

## Purpose
- Analytical mathematical model for pricing European-style options
- Used as a correctness baseline for Monte Carlo simulations
- Provides a direct closed-form solution instead of simulation

## Inputs
- Current stock price (\(S_0\))
- Strike price (\(K\))
- Volatility (\(\sigma\))
- Risk-free interest rate (\(r\))
- Time to expiration (\(T\))

## Key Idea
- Assumes stock prices follow geometric Brownian motion
- Models future stock price uncertainty continuously over time
- Computes theoretical “fair” option value

## Why Important for Project
- Used to validate Monte Carlo outputs
- Allows numerical error comparison
- Helps evaluate FPGA fixed-point precision loss

## Limitations
- Assumes constant volatility
- Assumes normally distributed returns
- Only directly applies to European-style options

---

# Monte Carlo Simulation

## Purpose
- Numerical method for approximating solutions through repeated random sampling
- Used for option pricing and risk analysis

## Core Idea
- Simulate many possible future stock prices
- Compute payoff for each simulation
- Average all outcomes

## Workflow
1. Generate random value
2. Simulate future stock price
3. Compute option payoff
4. Repeat many times
5. Average results

## Why Important for FPGA
- Each simulation path is independent
- Highly parallelizable
- Maps well to replicated FPGA pipelines

## Tradeoffs
Advantages:
- Flexible
- Handles complex derivatives
- Naturally parallel

Disadvantages:
- Computationally expensive
- Requires many simulations for accuracy
- CPU implementations can have high latency

---

# Geometric Brownian Motion (GBM)

## Purpose
- Mathematical model for stock price evolution
- Forms basis of Black-Scholes and Monte Carlo simulation

## Key Equation
Future stock price depends on:
- drift
- volatility
- randomness

## Components
- Drift term:
  - expected average growth
- Volatility term:
  - randomness/uncertainty
- Gaussian random variable:
  - market randomness

## Why Important
- Used to generate simulated stock price paths
- Standard financial modeling assumption

---

# Box-Muller Transform

## Purpose
- Converts uniformly distributed random numbers into normally distributed random numbers

## Why Needed
- Monte Carlo stock simulations require Gaussian random variables
- Standard `rand()` only produces uniform random numbers

## Inputs
- Two uniform random variables:
  - \(U_1\)
  - \(U_2\)

## Outputs
- Normally distributed random variable:
  - \(Z \sim N(0,1)\)

## Why Useful
- Relatively simple mathematically
- Easy to implement in C
- Common in simulation systems

## Drawbacks for FPGA
- Requires:
  - logarithms
  - square roots
  - trigonometric functions
- Expensive in hardware

## FPGA Consideration
- FPGA version may replace Box-Muller with:
  - LFSR-based approximation
  - lookup tables
  - simplified RNG hardware

---

# Linear Feedback Shift Register (LFSR)

## Purpose
- Lightweight hardware-oriented pseudo-random number generator

## Why Useful for FPGA
- Very resource efficient
- Simple hardware implementation
- Fast generation speed

## Core Idea
- Uses shift registers and XOR feedback
- Produces pseudo-random binary sequences

## Advantages
- Small hardware footprint
- High throughput
- Easy to pipeline

## Disadvantages
- Lower statistical quality than software RNGs
- Not truly random
- May reduce simulation accuracy

## Project Relevance
- Likely RNG candidate for FPGA implementation

---

# Fixed-Point Arithmetic

## Purpose
- Hardware-efficient alternative to floating-point arithmetic

## Core Idea
- Store numbers as scaled integers
- Example:
  - Q16.16 format
  - 16 integer bits
  - 16 fractional bits

## Why FPGA Uses It
- Floating point consumes significant hardware resources
- Fixed point is:
  - smaller
  - faster
  - more power efficient

## Advantages
- Lower resource usage
- Faster arithmetic
- Easier hardware design

## Disadvantages
- Quantization error
- Reduced precision
- Possible overflow/underflow

## Project Importance
- Major hardware/software tradeoff study
- Compare FPGA fixed-point results vs CPU floating-point results

---

# FPGA Parallel Pipelines

## Purpose
- Execute multiple Monte Carlo simulations simultaneously

## Core Idea
- Replicate hardware lanes spatially
- Each lane independently computes simulations

## Pipeline Stages
1. RNG generation
2. Stock price update
3. Payoff computation
4. Result accumulation

## Advantages
- Massive throughput increase
- Low latency
- Exploits simulation independence

## Tradeoffs
- Increased FPGA resource usage
- Scaling limited by:
  - LUTs
  - DSP blocks
  - BRAM
  - routing complexity

---

# Throughput

## Definition
- Number of simulations completed per unit time

## Why Important
- Measures computational efficiency
- Main expected FPGA advantage

## Goal
- Demonstrate FPGA scaling as lanes increase

---

# Latency

## Definition
- Time required for a simulation run to complete

## Why Important
- Critical in financial systems
- Lower latency improves responsiveness

## Goal
- Compare CPU sequential execution vs FPGA pipelines

---

# Numerical Precision

## Purpose
- Measure accuracy differences between implementations

## Comparisons
- CPU floating point
vs
- FPGA fixed point

## Metrics
- Absolute error
- Percent error
- Difference from Black-Scholes analytical price

---

# FPGA Resource Constraints

## Important Resources
- LUTs
- Flip-flops
- DSP slices
- BRAM

## Why Important
- Limits number of parallel lanes
- Affects scalability

## Tradeoff
More lanes:
- higher throughput
but:
- higher resource usage

---

# Vivado

## Purpose
- AMD FPGA synthesis and implementation tool

## Used For
- Synthesis
- Timing analysis
- Bitstream generation
- Resource utilization reports

---

# SystemVerilog

## Purpose
- Hardware description language for FPGA implementation

## Used For
- Pipeline design
- RNG hardware
- Arithmetic modules
- Simulation lane replication

---

# Monte Carlo vs Black-Scholes

## Black-Scholes
- Analytical
- Direct formula
- Fast
- Limited flexibility

## Monte Carlo
- Simulation-based
- Computationally expensive
- Flexible
- Parallelizable

## Project Relationship
- Black-Scholes used as correctness baseline
- Monte Carlo used for FPGA acceleration study