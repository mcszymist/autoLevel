#ifndef HOUSE_H
#define HOUSE_H

#include "SerialPort.hpp"
using namespace mn::CppLinuxSerial;

#include <vector>
using std::vector;
using std::size_t;
using std::pair;
#include <memory>
using std::shared_ptr;
#include <iostream>
using std::cout;
using std::endl;
#include "jack.h"
#include "sensor.h"
#include "emu.h"
//	 -> \ positive
//   -> / negative

class House{
private:


    bool workingOnPos = true;
	int counterID = 0;
    vector<shared_ptr<Jack>> jacks;
    Emu emulation{};
    shared_ptr<SerialPort> serial;
public:

    House(){
        serial = std::make_shared<SerialPort>("/dev/ttyACM0",BaudRate::B_115200);
        serial->Open();
    }
	//false is down, true is up
	void findRelations();
	vector<shared_ptr<Jack>> getJacks(){
		return jacks;
	};
	vector<shared_ptr<Jack>> greatestIncline();
	void workJacks(vector<shared_ptr<Jack>>);
    bool addJack(const double &h,const int &pin);
    bool addSensor(shared_ptr<Jack> jack,const int &id){
        jack->makeSensor(id);
    };
    bool removeJack(const int &id);
    bool bIsGood();
	//false = unlevel, true = level
    bool checkLevel();
    void emuAngles(){
    	emulation.calculateAllAngles(jacks);
    };
    void printAllInfo(){
		for(auto i : jacks){
			cout << "Jack: " << i->getID() << endl;
			cout << "Height: "<<i->getHeight() << endl;
			cout << "X: " << i->getSensor()->getXAngle() << ", Y: " << i->getSensor()->getYAngle() << endl;
		}
    }
	void levelOnce();
    void autoLevel();
};
#endif