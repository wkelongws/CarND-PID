# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program term 2 project 4 - PID controller

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. run `./clean.sh`
2. run `./build.sh`
2. run `./run.sh`

## PID coefficients

* The propotional coefficient contributes to compensate the CTE. The larger the propotional coefficient, the quicker the car will return to the lane center but more overshoots and unstability will also be introducted.

* The integral coefficient contributes to compenstate the systematic bias for example a constant steering angle bias built in the vehicle. Since there are no systematic bias in this simulator, the integral coefficient is suppose to be close or equal to zero.

* The differential coefficient contributes to compenstate the overshots and stablize the vehicle.

## PID coefficients searching by twiddle

The throttle was set as a constant 0.5.

All the PID coefficients are selected based on the twiddle searching strategy (The twiddle strategy is coded in main.cpp, currently commented/disabled). During twiddling, each cylce runs 1000 time steps. The total accumulated squred cte error from time step 300 to time step 1000 was calcualted and compared to the best recorded error to determine whether the current coefficient setting is good or not and adjust the searching range accordingly. Eventally the seaching stopped when the sum of all three searching ranges is smaller than a small tolerance value. The selected three coefficents were: Kp = 0.183837, Ki = 0.000952203, Kd = 4.79995. Then Ki was manually set to zero since there is no systematic bias in this simulator.

The car runs decently with the three selected PID coefficients in the mac simulator with screen resolution = 640*480 and graphics quality = Fastest.

