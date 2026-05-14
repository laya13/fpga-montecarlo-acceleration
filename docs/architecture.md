# FPGA Architecture

## Pipeline Structure

RNG
↓
GBM Stock Update
↓
Payoff Logic
↓
Accumulator

## Parallelism Strategy
- Start with 1 lane
- Scale to 4–16 lanes