# phaosfit
A CLI aspect ratio resolution fitter written in C.  

Based on this tutorial:
https://www.marcusfolkesson.se/blog/cmdline-parsing/

# Install & Build
This assumes that you run a Debian-based Linux distribution.

Make sure the right tools are installed:
```bash
sudo apt update && sudo apt install build-essential
```

Then clone the repo:
```bash
git clone https://github.com/AlexLandherr/phaosfit.git
```

Change directory to repo:
```bash
cd phaosfit/
```

Then build & compile using `make`:
```bash
make
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
- W can be either an integer or floating point value, the `.` (period) character shall always be used as the<br>
  decimal sign/decimal separator. A string like `1.:1` should be interpreted as `1.0:1`, i.e. W<br>
  is the IEEE 754 double representation of 1.
- W must be greater than or equal to 1.
- H must always be an integer.
- H must be greater than or equal to 1.
- The `:` (colon) character must always sit between W and H and be present in the string, e.g. `16:9` is valid but `169:` or `:169` or `169` etc. is invalid.
- Cases like `16:916:9`, `16:9 16:9` or ratio strings that have more than 1 valid match are to be considered invalid as the string should only ever hold/represent 1 aspect ratio.
- W cannot be less than H.
- Conditions like W == H (W is equal to H) are to be considered valid.

## Requirements of Output Results
- W and H given in pixles.
- All solutions must be for a raster of square pixels.
- W and H must be even positive integers.
- Deviation from target AR must be given as `±%` to 15 decimal places, e.g. `-0.000000000000012%` or `+0.000000000000012%`.

# Usage
Example entering aspect ratio and getting list of pixel resolutions (pixel list part far from fully implemented yet):
```bash
./phaosfit -r 16:9
./phaosfit -r "16:9"
./phaosfit --ratio 16:9
./phaosfit --ratio "16:9"
```

or

```bash
./phaosfit -r 1.85:1
./phaosfit -r "1.85:1"
./phaosfit --ratio 1.85:1
./phaosfit --ratio "1.85:1"
```

should for now just return the below, now it just calculates up to `W_MAX_RESOLUTION_PIXELS`.
Depending on your terminal settings all output may not be visible:
```bash
Passed value: '16:9'
W is an integer value!
------------------------------------------------------------------------------------------
|       Width (px) |      Height (px) |          Δ% from 16:9 | PLACEHOLDER_FIELD        |
------------------------------------------------------------------------------------------
|               32 |               18 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|               64 |               36 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|               96 |               54 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|              128 |               72 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
...
------------------------------------------------------------------------------------------
|            65408 |            36792 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65440 |            36810 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65472 |            36828 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65504 |            36846 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
|            65536 |            36864 |   +0.000000000000000% | EMPTY_PLACEHOLDER_STR    |
------------------------------------------------------------------------------------------
```

or

```bash
Passed value: '1.85:1'
W is a floating-point value!
W: 1.850000000000000, H: 1
```