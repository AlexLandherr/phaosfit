# phaosfit
A CLI aspect ratio / resolution fitter written in C.

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
16:9
```
