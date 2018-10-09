#include "house.h"
#include <cmath>
using std::fabs;
//false is down, true is up
bool House::bIsGoesUpDownS(shared_ptr<Jack> jack){
    auto list = jack->getList();
    int downCounter = 0;
    int upCounter = 0;
    for(auto i : list){
        if(i->getSensor()->getXAngle() < 0 && i->getSensor()->getYAngle() < 0){
            downCounter++;
        }
        if(i->getSensor()->getXAngle() > 0 && i->getSensor()->getYAngle() > 0){
            upCounter++;
        }
    }
    if(upCounter == downCounter){
        //ERROR
    }

    if((downCounter < upCounter )&&( jack->getSensor()->getXAngle() > 0.0 )&&( jack->getSensor()->getYAngle() > 0.0)){
        return true;
    }
    if((upCounter < downCounter) && (jack->getSensor()->getXAngle() > 0.0) && (jack->getSensor()->getYAngle() > 0.0)){
        return false;
    }
    return true;
    //ERROR
};
shared_ptr<Jack> House::greatestIncline(){
    int highest = -1;
    double max = 0;
    for(size_t i = 0; i < jacks.size();i++){
        double hold = fabs(jacks[i]->getSensor()->getXAngle())+fabs(jacks[i]->getSensor()->getYAngle());
        if(hold > max){
            max = hold;
            highest = i;
        }
    }
	if (highest == -1) {
		return nullptr;
	}
    return jacks[highest];
}
bool House::addJack(const double &h){
    shared_ptr<Jack> jack(new Jack(h));
    jacks.push_back(jack);
    return true;
}

bool House::removeJack(const int &id){
    for(size_t i = 0; i < jacks.size();i++){
        if(jacks[i]->getID()==id){
            jacks.erase(jacks.begin() + i);
            return true;
        }
    }
    return false;
};

bool House::bIsGood(){
    for(auto i : jacks){
        if(!i->bIsGood()){
            return false;
        };
    }
    return true;
}
//false = unlevel, true = level
bool House::checkLevel(){
	for (auto i : jacks) {
		const double hold = fabs(i->getSensor()->getXAngle()) + fabs(i->getSensor()->getYAngle());
		if (hold > (i->getSensor()->getPrecision()*2.5 + i->getStepsize())) {
			return false;
		}
	}
	return true;
}
