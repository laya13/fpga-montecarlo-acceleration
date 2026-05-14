# Investigating FPGA Acceleration of Monte Carlo Financial Simulations
 
**Submitted by:** Laya Satish

---

# Summary

Monte Carlo simulations are widely used in finance for pricing derivatives and modeling risks. However, these simulations require thousands of computations to achieve accurate results, making CPU-based implementations slow and expensive due to floating-point arithmetic. This introduces an issue of variability in latency and performance.

This proposal explores whether Field Programmable Gate Arrays (FPGAs) can accelerate Monte Carlo simulations for European option pricing. I propose to implement both a software baseline and an FPGA implementation in order to compare latency, throughput, and precision. In addition, the Monte Carlo results will be compared against the analytical Black-Scholes model to validate numerical accuracy.

This project will systematically compare performance and precision, and the results will provide further insights into hardware acceleration strategies in high-performance financial computing environments. This work explores the tradeoff between computational efficiency and numerical precision in hardware acceleration.

---

# Objectives

In order to address the gap of comparisons between CPU and FPGA performance, I will use the Monte Carlo algorithm for financial simulations on both a CPU and FPGA in order to compare the performance. The simulations will focus specifically on European option pricing, where the Monte Carlo estimates can also be compared against the analytical Black-Scholes solution for correctness and precision analysis.

However, since this can be computationally expensive, I will implement the algorithm in hardware on an FPGA by using parallel processing to accelerate the simulations.

## Objectives

- Compare CPU vs FPGA performance
- Measure latency, throughput, and precision
- Evaluate scalability
- Compare Monte Carlo outputs against the Black-Scholes model

The performance of the implementations will be evaluated with two criteria: latency and throughput. Latency refers to the amount of time required for a single simulation to start and end. This is an important criterion because the finance industry needs results quickly due to constantly changing market conditions.

Throughput refers to the number of simulations that can be completed in a certain time frame. This is important because the higher the throughput, the better the accuracy can be achieved.

The Black-Scholes equation will also be used as a mathematical baseline to compare the Monte Carlo outputs and evaluate the numerical accuracy of both the CPU floating-point implementation and the FPGA fixed-point implementation.

Through this research I aim to reduce computational cost by replacing repeated CPU execution with parallel hardware pipelines. This would allow faster simulation times and lower runtime costs. The fixed-point arithmetic on FPGA can also reduce resource consumption while maintaining acceptable precision, since the higher throughput allows more simulations per time unit, improving the cost-to-accuracy ratio.

In the long run, this could help the finance industry because faster simulations would enable more responsive derivative pricing in rapidly changing markets. Higher simulation capacities could also improve risk estimation in high-frequency or latency-sensitive environments.

From a hardware perspective, this project explores the tradeoffs between precision, throughput, and customizable data paths. Overall, it will provide a strong foundation for future software and hardware integration in financial computing.

---

# Methodology

Monte Carlo parallelization on FPGA leverages the independence of simulation paths by mapping them to different hardware pipelines, allowing many simulations to be executed simultaneously with minimal control overhead.

Instead of running simulations sequentially like a CPU, the FPGA runs many simulations simultaneously using separate hardware pipelines. Each pipeline functions like an assembly line, handling stages such as generating random inputs, updating the simulation, and computing results in parallel. Because the simulations do not depend on each other, this structure allows the FPGA to achieve much higher throughput and efficiency.

First, the Monte Carlo simulation will be implemented using the C programming language to establish a baseline for performance. VS Code will be used for development.

The algorithm will generate random samples to simulate possible stock price paths and estimate the expected payoff of a European call option. These Monte Carlo estimates will then be compared against the analytical Black-Scholes equation in order to evaluate correctness and numerical precision.

For random number generation in the CPU implementation, I will use the Box-Muller transform to generate normally distributed random variables, which will be used to simulate stochastic price paths.

The stock price evolution will follow a simplified stochastic model based on geometric Brownian motion, which is commonly used in financial modeling and also forms the basis of the Black-Scholes framework.

Next, the same algorithm will be implemented on an AMD FPGA using the hardware description language SystemVerilog, along with VS Code for simulation and Vivado for synthesis.

The FPGA implementation will execute simulations through parallel hardware pipelines. The FPGA will use a hardware-optimized random number generation approach and lookup tables due to the complexity of the arithmetic operations.

Finally, I will compare the CPU and FPGA implementations by evaluating latency and throughput across different numbers of simulations. I will begin with smaller simulation counts such as 10, then gradually scale to larger workloads such as 50, 100, and beyond.

---

# Background

The Black-Scholes model is one of the most widely used mathematical models in quantitative finance for pricing European-style options. It provides a closed-form analytical equation that estimates the fair value of an option based on factors such as stock price, volatility, strike price, interest rate, and time to expiration. Because the Black-Scholes model produces a direct theoretical price, it can be used as a baseline for validating the Monte Carlo simulation results.

The Monte Carlo algorithm is a computational technique used to estimate numerical results through random sampling. A simple way to think about this is with the classic example of approximating the area of a circle using random points.

Imagine a square plot of land enclosing a circular lake. To estimate the area of the lake without measuring tools, you randomly toss pebbles into the square plot. By counting the pebbles that land inside the circle versus the total number of pebbles, you can derive the probability that a pebble lands inside the lake. This can then be used to approximate the area of the circle.

Obviously, for precision, this method would require a very large number of pebbles, making it computationally expensive. Similarly, in finance, Monte Carlo simulations require many repeated calculations, making them expensive and slow on CPUs.

In finance, Monte Carlo simulations are used to model uncertainty and estimate the value of complex financial instruments. One common application is derivative pricing, where the future payoff of options depends on uncertain asset prices.

In many cases, analytical solutions become difficult or impossible to compute directly, so simulation methods such as Monte Carlo are used to approximate expected outcomes. By simulating thousands of possible stock price paths, the Monte Carlo algorithm can approximate the expected payoff of an option.

Monte Carlo simulations are also used in risk management, where simulations estimate the probability of extreme portfolio losses or analyze the outcomes of different asset allocations over time.

The Monte Carlo simulation is especially useful because each simulation path is independent, making it highly suitable for parallel FPGA architectures.

However, without faster implementations, Monte Carlo methods are limited in scalability. This reduces the ability to model more complex derivatives and perform large-scale risk analysis efficiently.

By using FPGA acceleration with fixed-point arithmetic, latency can potentially be reduced while throughput increases significantly. However, detailed comparisons between CPU and FPGA implementations are still limited, which this project seeks to address.

---

# Tools

- AMD FPGA
- AMD Vivado
- VS Code
- SystemVerilog
- C Programming Language

The FPGA platform selected is sufficient for this project because it supports the implementation of parallel hardware pipelines required for Monte Carlo simulations at a prototype scale.

Since Monte Carlo methods are highly parallelizable, even a mid-scale FPGA can effectively demonstrate improvements in throughput by executing multiple simulation paths concurrently.

The goal of this project is to compare CPU and FPGA performance rather than maximize hardware utilization, making this platform appropriate for experimental evaluation.

---

# Timeline

## Phase 1: Foundation & Baseline

- Develop the Monte Carlo option pricing algorithm in C using VS Code
- Implement the Box-Muller transform
- Validate Monte Carlo outputs against the Black-Scholes equation

## Phase 2: Hardware Design

- Translate the simulation logic into SystemVerilog
- Design a hardware-optimized random number generator
- Design a single-lane processing pipeline

## Phase 3: Parallelization & Synthesis

- Scale the design to multiple parallel lanes to maximize FPGA throughput
- Synthesize the design using AMD Vivado

## Phase 4: Analysis & Comparison

- Compare CPU vs FPGA latency and throughput
- Evaluate scalability across different simulation counts
- Analyze the tradeoff between computational speed and numerical precision

---

# References

Barbone, Marco, et al. “Demonstration of FPGA Acceleration of Monte Carlo Simulation.” *Journal of Physics: Conference Series*, vol. 2438, no. 1, 2023, p. 012023.

Meng, Yuan, Rajgopal Kannan, and Viktor Prasanna. “Accelerating Monte-Carlo Tree Search on CPU-FPGA Heterogeneous Platform.” *Proceedings of the 32nd International Conference on Field-Programmable Logic and Applications (FPL)*, 2022.

TEJ. “Options Pricing with Monte Carlo Simulation.” *TEJ Taiwan Economic Journal*, 4 July 2023.  
https://www.tejwin.com/en/insight/options-pricing-with-monte-carlo-simulation/

Cely Toro, Iván Mauricio. “Estimating π Using the Monte Carlo Method.” *World Science Discover*, 5 Aug. 2020.  
https://mauriciocely.github.io/blog/2020/08/05/estimating-pi-using-the-monte-carlo-method/