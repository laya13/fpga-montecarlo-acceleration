# Box-Muller Transform

## Goal

The Monte Carlo model requires samples from a standard normal distribution:

$$
Z\sim N(0,1)
$$

The CPU implementation generates these samples using the Box-Muller transform.

## Starting Point

Generate two independent uniform random variables:

$$
U_1,U_2\sim U(0,1)
$$

The Box-Muller transform produces:

$$
Z_0=
\sqrt{-2\ln(U_1)}
\cos(2\pi U_2)
$$

and:

$$
Z_1=
\sqrt{-2\ln(U_1)}
\sin(2\pi U_2)
$$

Both $Z_0$ and $Z_1$ are independent standard normal random variables.

## Why It Works

The transformation converts points uniformly distributed over the unit square into points distributed according to a two-dimensional Gaussian distribution.

The radial component is:

$$
R=\sqrt{-2\ln(U_1)}
$$

and the angular component is:

$$
\theta=2\pi U_2
$$

giving:

$$
Z_0=R\cos(\theta)
$$

$$
Z_1=R\sin(\theta)
$$

## FPGA Considerations

Box-Muller requires:

* logarithm
* square root
* sine
* cosine

These operations are relatively expensive in hardware.

Therefore, the FPGA implementation may use a different RNG strategy, such as an LFSR combined with lookup tables or another hardware-oriented approximation.

## Design Tradeoff

CPU:

$$
\text{Box-Muller} \rightarrow \text{higher statistical quality, higher computation cost}
$$

FPGA:

$$
\text{hardware RNG} \rightarrow \text{lower hardware cost, possible statistical/accuracy tradeoff}
$$
