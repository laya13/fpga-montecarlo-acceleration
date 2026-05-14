# Engineering Notes

---

## May 14, 2026

### Project Scope Decisions
- Focus on European call options only
- Use Black-Scholes as correctness baseline
- Start with one-step GBM model instead of multi-step paths

### Why
- Keeps FPGA arithmetic manageable
- Easier fixed-point implementation
- Easier benchmarking

### Research Notes
- Monte Carlo highly parallelizable because paths independent
- Box-Muller may be expensive on FPGA due to transcendental functions

### Questions
- Should FPGA RNG use LFSR?
- How many lanes feasible on 18-240 board?

### TODO
- Implement Gaussian RNG in C
- Build benchmark timing infrastructure