#HMC5883L Driver (3-Axis Magnetometer) #

This driver is for the Sparkfun HMC5883L Breakout.  This is modified from the origional version for simplictiy of use.

Usage:
//new instance of HMC5883L library
compass = HMC5883L();
//setup the HMC5883L
compass.initialize();
//call the following to get your heading
compass.getHeading();
