# Hawkeye

Hawkeye is SCR's GNC library. Eventual goals include:
- EKF for rocket position
- airbrake control??
- apogee detection??

## Building
1. Install GCC, Make, and CMake onto your machine
2. clone the project, I recommend using an SSH key:
    - `git clone --recurse-submodules git@github.com:UH-AIAA/scr_Hawkeye.git`
2. Run `make lib` in the root of the project. This will build a static (`.a) library for your project to link to
3. Run `make test_exec` to build the unit test executable for the project. Run with `./hawkeye_test`!
    - alternatively run `make all` to do both of these things!
