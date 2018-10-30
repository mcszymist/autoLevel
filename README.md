# AutoLevel House

This project was started to try and make a house that will level itself using someform of technology to make this happen.

## Hardware
* [Arduino Mega](https://store.arduino.cc/arduino-mega-2560-rev3)
* Laptop
* [SCA100T-D01](https://www.murata.com/en-us/products/sensor/guide/sensorguide3/sensorguide/sca100t-d01) - Tilt Sensor
* [Mortoized Screw Jack](https://www.alibaba.com/showroom/motorized-screw-jack.html)
* [Motor Controller](https://www.amazon.com/gp/product/B00PU1EUMI/ref=crt_ewc_title_huc_2?ie=UTF8&psc=1&smid=A10DEFS1051Y1M)


Motor Controller

## Prerequisites

The serial libaray im using is windows only.

## Algorithm

This is where most of my time was held as there is so many cases to test.

I started out with a simple buteforce algorithm find the greatest angle, then check to see whihc direction it should go by locating the object around it.
This works ish as you can get into a posistion where you can create a greater angle when moving the angle up causing a bounce back and forth between two jacks.
So I had to figure out a better way to do this algorithm.
So the second algorithm look at everything and found the greatest relationship between all jacks.
relationship is if the jack is higher or lower then surounding jecks. This creates a number that represents if they are high or low and to what degree.
I would then raise and lower all at the same level, this step right here introduced a bug.
You cant raise and lower at the same time as you can step pass eachother which is a infinite loop.

That is where im at today.

## Running the tests

All of my testing was using a emulation of real world angle using pathogeoms theorm and using catch 2.
There is a issue with how im emulating angles that cause condictions to endlessly loop since the angles are not calculated with both adjacent jacks in mind.

## Branch Emu_Testing and master

The Emu_Testing branch has the new algorithm and the test code so it should be the master at this point.
Master just has the serial code for comunication.

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* Cmake
* C++
* Windows if using serial.

## Authors

* Tyler J Roberts

## Code sources
* Arduino website for serial is the bulk of my serial code.
