#ifndef JACK_H
#define JACK_H
#include "sensor.h"
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <utility>
using std::pair;

#if TESTING
#include "SerialPortDummy.h"
#else
#include "SerialPort.hpp"
#endif
using namespace mn::CppLinuxSerial;
//ScrewJack motorized

class Jack{
private:
    int pin;
	int currentRelation = 0;
	//height is in cm
    const int maxHeight = 100;
    const int minHeight = 10;
    const double stepSize = .01;
    double height;
    const bool bCanStep(const bool &direction);
    shared_ptr<SerialPort> serial;
	shared_ptr<Sensor> sense;
    vector<pair<shared_ptr<Jack>,int>> adjacent;
    const long ID;
	bool isGood = true;
public:
	void resetRelation(){
		currentRelation =0;
	}
	int getRelation(){
		return currentRelation;
	}
	void increaseRelation(){
		currentRelation++;
	}
	void decreaseRelation(){
		currentRelation--;
	}
	const double getHeight(){
		return height;
	}
	const bool isAdjacent(const shared_ptr<Jack> &jack) {
		for (auto i : adjacent) {
			if (i.first == jack) {
				return true;
			}
		}
		return false;
	}
    Jack(shared_ptr<SerialPort> s,const int &id,const int &p, const double &h):serial(s),height(h),ID(id),pin(p) {

    };
	shared_ptr<Sensor> getSensor(){
        return sense;
    }
    void makeSensor(const int &pin){
		sense = make_shared<Sensor>(serial,pin);
    }
	const bool raise();
	const bool lower();
    const bool bIsGood();
    //direction +X = 0, -X = 1,+Y = 10,-Y = 11
    const bool addAdjJack(shared_ptr<Jack> jack,const int &direction);
    const bool removeAdjJack(shared_ptr<Jack> jack);
    const vector<pair<shared_ptr<Jack>,int>> getList(){
        return adjacent;
    }
	const double getStepsize() {
		return stepSize;
	};

    const int getID(){
        return ID;
    };
};



#endif