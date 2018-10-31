# AutoLevel House

This project was started to try and make a house that will level itself using someform of technology to make this happen. The reason thisis needed is permafrost causes the house to become unlevel overtime. There seems to be nobody that I have found trying to level a house automaticly.

There is plenty of people testing the presision of tools and pushing them to the limit so I ended up reading a good amount of white papers on wifi, bt, and lasers trying to find the best way to find if the angle was off. After doing all that research I came to the conclusion that laser would work but there is a issue as having a lazer means people cant use there crawl space for storage. It ended up being a simple issue use a high precision inclinometer, done. 

There was also a choice for what type of jack to use and it comes done to either hydralic or motorized screw jack. Hydralic would be awesome but doesnt scale wear and causes the issues of having more pipes to manage and have many safety vaules to slam shut if pressure change. Not very managable in a commercial setting. So in the end a motorized screw jack is the best option.

## Hardware
* [Arduino Mega](https://store.arduino.cc/arduino-mega-2560-rev3)
* Laptop
* [SCA100T-D01](https://www.murata.com/en-us/products/sensor/guide/sensorguide3/sensorguide/sca100t-d01) - Tilt Sensor
* [Mortoized Screw Jack](https://www.alibaba.com/showroom/motorized-screw-jack.html)
* [Motor Controller](https://www.amazon.com/gp/product/B00PU1EUMI/ref=crt_ewc_title_huc_2?ie=UTF8&psc=1&smid=A10DEFS1051Y1M)

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

## Changes to be made

* Fix the Emu_Testing branch to include both jacks in angle calculization so we get accurate angles.
* Fix my arduino to use a packets system instead of just sending to chars and delaying before recieving.
* Put a pressure sensor on the jacks head so If the jack comes off the beam the program needs to know not to.

* Everything else as of 2018 I wouldnt change as the research I have done its the best option. 


## Built With

* Cmake
* C++
* Windows if using serial.

## Authors

* Tyler J Roberts

## Code sources
* Arduino website for serial is the bulk of my serial code.
