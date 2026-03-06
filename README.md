# phaosfit
A CLI aspect ratio / resolution fitter written in C.  

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
- The `:` (colon) character must always sit between W and H and be present in the string, e.g. `16:9` is valid but<br>
  `169:` or `:169` or `169` etc. is invalid. Cases like `16:916:9`, `16:9 16:9` or ratio strings that have more<br>
  than 1 valid match are to be considered invalid as the string should only ever hold/represent 1 aspect ratio.
- W cannot be less than H.
- Conditions like W == H (W is equal to H) are to be considered valid.

## Requirements of Output Results
- W and H given in pixles.
- All solutions must be for a raster of square pixels.
- W and H must be even positive integers.
- Deviation from target AR must be given as `±%` to 15 decimal places, e.g. `-0.000000000000012%` or `+0.000000000000012%`.

# Usage
Example entering aspect ratio and getting list of pixel resolutions (pixel list part far from implemented yet):
```bash
./phaosfit -r 16:9
./phaosfit -r "16:9"
./phaosfit --ratio 16:9
./phaosfit --ratio "16:9"
```

should for now just return:
```bash
Passed value: '16:9'
W: 16.000000000000000, H: 9
```
