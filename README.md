# AutoLevel House

This project was started to try and make a house that will level itself using someform of technology to make this happen. The reason thisis needed is permafrost causes the house to become unlevel overtime. There seems to be nobody that I have found trying to level a house automaticly.

There is plenty of people testing the presision of tools and pushing them to the limit so I ended up reading a good amount of white papers on wifi, bt, and lasers trying to find the best way to find if the angle was off. After doing all that research I came to the conclusion that laser would work but there is a issue as having a lazer means people cant use there crawl space for storage. It ended up being a simple issue use a high precision inclinometer, done. 

There was also a choice for what type of jack to use and it comes done to either hydralic or motorized screw jack. Hydralic would be awesome but doesnt scale wear and causes the issues of having more pipes to manage and have many safety vaules to slam shut if pressure change. Not very managable in a commercial setting. So in the end a motorized screw jack is the best option.

## Hardware
* [Arduino Mega](https://store.arduino.cc/arduino-mega-2560-rev3)
* Laptop
* [SCA100T-D01](https://www.murata.com/en-us/products/sensor/guide/sensorguide3/sensorguide/sca100t-d01) - Tilt Sensor
* [Mortoized Screw Jack](https://www.alibaba.com/showroom/motorized-screw-jack.html)
* [Relay Module](https://www.amazon.com/gp/product/B00PU1EUMI/ref=crt_ewc_title_huc_2?ie=UTF8&psc=1&smid=A10DEFS1051Y1M)

## How to Use

* Include the house class
* House house; 
* Create a Jack - house.addJack(double height,int pin);
* Add the jacks that are Adjacent and relative direction - addAdjJack(Jack,int Location); 0 = left, 1 = right, 10 = down, 11 = up;
* Add sensors to there respective jacks - makeSensor(int pin);
* autoLevel() will level your house.
* checklevel() will report if the house needs to be leveled.

## Comunication between arduino
* Packet system using < as start and > as end charicters.
* The packet system is a Blocking read/write.
TODO:
* To resend packets if the return packet was never recieved.
## Relay Wiring
IMAGE

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

## Emulating testing

All of my testing was using a emulation of real world angle using pathogeoms theorm and using catch 2.
There is a issue with how im emulating angles that cause condictions to endlessly loop since the angles are not calculated with both adjacent jacks in mind.

## Full Ciruitry
IMAGE
## log



## Changes to be made

* Put a pressure sensor on the jacks head so If the jack comes off the beam the program needs to know not to.
* add encoders to verify the amount of movement accuring.
* add code to stop system if jack is returning bad tilt data.

## Built With

* Cmake
* C++
* Linux for serial libaray

## Authors

* Tyler J Roberts

## Code sources
* Serial Libary from 

