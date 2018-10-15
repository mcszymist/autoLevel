#ifndef JACK_H
#define JACK_H
#include "sensor.h"
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include "SerialClass.h"	// Library described above
//ScrewJack motorized

class Jack{
private:
	shared_ptr<Serial> port;
    const int maxHeight = 100;
    const int minHeight = 10;
    const double stepSize = .5;
    double height;
    const bool bCanStep(const bool &direction);
	shared_ptr<Sensor> sense;
    vector<shared_ptr<Jack>> adjacencent;
    static long ID;
    const long currentID;
	bool isGood = true;
public:
	const bool isAdjacent(const shared_ptr<Jack> &jack) {
		for (auto i : adjacencent) {
			if (i == jack) {
				return true;
			}
		}
		return false;
	}
    Jack(const double &h,shared_ptr<Serial> &p):height(h),port(p),currentID(ID++) {

    };
	shared_ptr<Sensor> getSensor(){
        return sense;
    }
    void makeSensor(const int &id){
		sense = make_shared<Sensor>(id);
    }
	const bool raise();
	const bool lower();
    const bool bIsGood();
    const bool addAdjJack(shared_ptr<Jack> jack);
    const bool removeAdjJack(shared_ptr<Jack> jack);
    const vector<shared_ptr<Jack>> getList(){
        return adjacencent;
    }
	const double getStepsize() {
		return stepSize;
	};
    const int getID(){
        return currentID;
    };
	friend static bool operator== (const Jack &a, const Jack &b);
};
long Jack::ID = 0;
static bool operator== (const Jack &a, const Jack &b) {
	if (a.currentID == b.currentID) {
		return true;
	}
	return false;
};

#endif