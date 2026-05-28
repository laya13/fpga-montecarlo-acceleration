# Engineering Notes

---

## May 14, 2026

- scoped project to European call options only  
- using Black-Scholes as baseline  
- start with 1-step GBM model (no multi-step paths)

- MC is parallel by design (independent paths)  
- Box-Muller might be too heavy for FPGA (log/sqrt/cos)

- questions:
  - LFSR vs Box-Muller?
  - how many lanes can 18-240 FPGA handle?

- TODO:
  - write Gaussian RNG in C  
  - set up timing/benchmark code  

---

## May 16, 2026

- set up CPU code structure  
- split into:
  - rng
  - gbm
  - payoff
  - accumulator  

- MC loop is straightforward now

- issues:
  - needed -lm for math
  - unclear where “final step” is (fixed: avg + discount)

- bottleneck likely exp / sqrt / log  

- TODO:
  - implement Box-Muller  
  - add Black-Scholes  
  - start benchmarking  

---

## May 18, 2026

- added Black-Scholes for comparison baseline  
- MC vs BS comparison will be main accuracy check  

- MC = simulation  
- BS = closed form  

- unsure about acceptable error range  

- TODO:
  - implement BS fully in C  
  - compare outputs vs MC  

---

## May 20, 2026

- Box-Muller chosen for CPU  
- probably not viable for FPGA (too many heavy ops)

- FPGA RNG likely:
  - LFSR
  - LUT approximations  

- tradeoff = accuracy vs speed  

- TODO:
  - benchmark Box-Muller cost  
  - look into LFSR quality  

---

## May 23, 2026

- started thinking about benchmarking  
- need:
  - runtime vs N
  - sims/sec
  - scaling curve  

- plan:
  - clock_gettime for timing  
  - dump to CSV  

- TODO:
  - CSV logging  
  - python plots  

---

## May 26, 2026

- pipeline idea is clean:
  - RNG → GBM → payoff → sum  

- MC is embarrassingly parallel  

- FPGA plan:
  - start 1 lane  
  - scale to 4–16 lanes  

- questions:
  - fixed-point format (Q format?)  
  - DSP / LUT limits  

- TODO:
  - draw FPGA pipeline  
  - define fixed-point scheme  