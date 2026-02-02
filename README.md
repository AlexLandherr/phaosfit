# phaosfit
A CLI aspect ratio / resolution fitter written in C.  

Based on this tutorial:
https://www.marcusfolkesson.se/blog/cmdline-parsing/

# Install & Build
First clone the repo:
```
git clone https://github.com/AlexLandherr/phaosfit.git
```

Change directory to repo:
```
cd phaosfit/
```

Then build & compile using `make`:
```
make
```

# Usage
Example entering aspect ratio and getting list of pixel resolutions (pixel list part far from implemented yet):
```
./phaosfit -r 16:9
./phaosfit -r "16:9"
./phaosfit --ratio 16:9
./phaosfit --ratio "16:9"
```

should for now just return:
```
Passed value: '16:9'
W: 16.000000000000000, H: 9
```
