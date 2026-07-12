# phaosfit
A CLI aspect ratio resolution fitter written in C.

Based on this tutorial:
https://www.marcusfolkesson.se/blog/cmdline-parsing/

# Install & Build
This assumes that you run a Debian-based Linux distribution.

Make sure the right tools are installed:
```bash
sudo apt update && sudo apt install build-essential cmake
```

Then clone the repo:
```bash
git clone https://github.com/AlexLandherr/phaosfit.git
```

Change directory to the repo:
```bash
cd phaosfit/
```

Then configure and build using `CMake`:
```bash
cmake -S . -B build
cmake --build build
```

## Why the name *phaosfit*?
The **phaos** in **phaosfit** comes from the Ancient Greek word **φάος** (*pháos*), meaning **“light”** or **“daylight”**. The related Attic form is **φῶς** (*phôs*), a contracted form of **φάος**. In that sense, the name is meant to evoke **light**, optics and image-making, while **fit** reflects the program’s purpose of fitting or calculating resolutions against a target aspect ratio (Logeion, n.d.; Wiktionary, n.d.-a; Wiktionary, n.d.-b).

### References
Logeion (n.d.) *φάος*. University of Chicago. Available at: https://logeion.uchicago.edu/%CF%86%CE%AC%CE%BF%CF%82 (Accessed: 2026-03-10).

Wiktionary (n.d.-a) *φάος*. Available at: https://en.wiktionary.org/wiki/%CF%86%CE%AC%CE%BF%CF%82 (Accessed: 2026-03-10).

Wiktionary (n.d.-b) *φῶς*. Available at: https://en.wiktionary.org/wiki/%CF%86%E1%BF%B6%CF%82 (Accessed: 2026-03-10).

# Algorithm (Core Requirements)
## Terminology
- W refers to frame/image width; can be given as a dimensionless quantity or with a unit of mm (millimeters), inches or pixels.
- H refers to frame/image height; can be given as a dimensionless quantity or with a unit of mm (millimeters), inches or pixels.
- AR refers to the aspect ratio; defined as the ratio of an image's width to its height in the form `W:H`.

## Requirement of Input Aspect Ratio
- The string must always follow the general form `W:H`.
- W can be either an integer or floating point value; the `.` (period) character shall always be used as the decimal sign/decimal separator. A string like `1.:1` should be interpreted as `1.0:1`, i.e. W is the IEEE 754 double representation of 1.
- W must be greater than or equal to 1.
- H must always be an integer.
- H must be greater than or equal to 1.
- The `:` (colon) character must always sit between W and H and be present in the string, e.g. `16:9` is valid but `169:`, `:169` or `169` etc. are invalid.
- Cases like `16:916:9`, `16:9 16:9` or ratio strings that have more than 1 valid match are to be considered invalid, as the string should only ever hold/represent 1 aspect ratio.
- W cannot be less than H.
- Conditions like W == H (W is equal to H) are to be considered valid.

## Requirements of Output Results
- W and H are given in pixels.
- All solutions must be for a raster of square pixels.
- W and H must be even positive integers.
- Deviation from target AR is given as `±%` to available floating-point significant digits available on the target platform.

# Usage
Example entering aspect ratio and getting list of pixel resolutions (pixel list part far from fully implemented yet):
```bash
./build/phaosfit -r 16:9
./build/phaosfit -r "16:9"
./build/phaosfit --ratio 16:9
./build/phaosfit --ratio "16:9"
```

or

```bash
./build/phaosfit -r 1.85:1
./build/phaosfit -r "1.85:1"
./build/phaosfit --ratio 1.85:1
./build/phaosfit --ratio "1.85:1"
```

The program currently calculates up to `W_MAX_RESOLUTION_PIXELS`.
Depending on your terminal settings, all output may not be visible. Examples shown below
are only showing the ver start and end of the complete printouts.

Example `16:9` output:
```text
Passed value: '16:9'
W is an integer value!
W: 16, H: 9
------------------------------------------------------------------------------------------
|       Width (px) |      Height (px) |           Δ% from 16:9 | PLACEHOLDER_FIELD        |
------------------------------------------------------------------------------------------
|               32 |               18 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|               64 |               36 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|               96 |               54 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|              128 |               72 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
...
------------------------------------------------------------------------------------------
|            65408 |            36792 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65440 |            36810 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65472 |            36828 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65504 |            36846 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65536 |            36864 |                    +0% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
```

Example `1.85:1` output:
```text
Passed value: '1.85:1'
W is a floating-point value!
W: 1.850000000000000, H: 1
------------------------------------------------------------------------------------------
|       Width (px) |      Height (px) |         Δ% from 1.85:1 | PLACEHOLDER_FIELD        |
------------------------------------------------------------------------------------------
|                4 |                2 |     +8.10810810810809% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|                8 |                4 |     +8.10810810810809% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|               12 |                6 |     +8.10810810810809% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|               14 |                8 |     -5.40540540540541% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
...
------------------------------------------------------------------------------------------
|            65516 |            35414 | +0.000152634703942667% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65520 |            35416 | +0.000610504337639206% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65524 |            35418 |  +0.00106832226092202% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65530 |            35422 |  -0.00106820162153465% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65534 |            35424 | -0.000610366464026679% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
```
