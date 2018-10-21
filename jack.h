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
//ScrewJack motorized

class Jack{
private:
	int currentRelation = 0;
	//height is in cm
    const int maxHeight = 100;
    const int minHeight = 10;
    const double stepSize = .05;
    double height;
    const bool bCanStep(const bool &direction);
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
    Jack(const int &id, const double &h):height(h),ID(id) {

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