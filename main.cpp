//
// Created by zym on 11/28/18.
//





#include "house.h"
#include "SerialPort.hpp"
using namespace mn::CppLinuxSerial;

int main(){
    House house;
    house.addJack(40.0,50);		// bottom right
    house.addJack(50.0,48);		// bottom left
    house.addJack(50.0,46);		// top left
    house.addJack(50.0,44);		// top right
    auto saved = house.getJacks();
    saved[0]->addAdjJack(saved[1],1);
    saved[0]->addAdjJack(saved[3],10);
    saved[1]->addAdjJack(saved[0],0);
    saved[1]->addAdjJack(saved[2],10);
    saved[2]->addAdjJack(saved[3],0);
    saved[2]->addAdjJack(saved[1],11);
    saved[3]->addAdjJack(saved[0],11);
    saved[3]->addAdjJack(saved[2],1);
    for (auto i : house.getJacks()) {
        i->makeSensor(10);
    }

}