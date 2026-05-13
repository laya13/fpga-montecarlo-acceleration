CC=gcc
CFLAGS=-O2 -lm

all:
	gcc cpu/montecarlo.c cpu/rng.c cpu/benchmark.c -o montecarlo -lm