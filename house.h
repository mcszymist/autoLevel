#ifndef HOUSE_H
#define HOUSE_H
//	 -> \ positive
//   -> / negative
#include "jack.h"
#include "sensor.h"
#include <vector>
using std::vector;
using std::size_t;
using std::pair;
#include <memory>
using std::shared_ptr;
class House{
private:
    vector<shared_ptr<Jack>> jacks;
    
public:
	//false is down, true is up
	bool bIsGoesUpDownS(shared_ptr<Jack> jack);
	vector<shared_ptr<Jack>> getJacks(){
		return jacks;
	};
	shared_ptr<Jack> greatestIncline();
    bool addJack(const double &h);
    bool addSensor(shared_ptr<Jack> jack,const int &id){
        jack->makeSensor(id);
    };
    bool removeJack(const int &id);
    bool bIsGood();
	//false = unlevel, true = level
    bool checkLevel();
	
};
#endif