//
// Created by zym on 11/28/18.
//





#include "house.h"
#include "SerialPort.hpp"
using namespace mn::CppLinuxSerial;

int main(){
    House house;
    house.addJack(50.0,47);		// bottom right
    house.addJack(50.0,49);		// bottom left

    auto saved = house.getJacks();
    saved[0]->addAdjJack(saved[1],1);
    saved[1]->addAdjJack(saved[0],0);

    for (auto i : house.getJacks()) {
        i->makeSensor(1);
    }
    house.checkLevel();
    cout << house.getJacks()[0]->getSensor()->getXAngle();
    cout << house.getJacks()[0]->getSensor()->getYAngle();

}