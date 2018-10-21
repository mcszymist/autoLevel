#include "house.h"
#include <cmath>
using std::fabs;
//false is down, true is up
void House::findRelations(){
    for(auto jack : jacks) {
        auto list = jack->getList();
        jack->resetRelation();
        for (auto i : list) {
            if (i.first->getSensor()->getXAngle() < 0 && i.second == 1 ||
                i.first->getSensor()->getXAngle() > 0 && i.second == 0) {
                jack->increaseRelation();
            } else if (i.first->getSensor()->getXAngle() < 0 && i.second == 0 ||
                       i.first->getSensor()->getXAngle() > 0 && i.second == 1) {
                jack->decreaseRelation();
            } else if (i.first->getSensor()->getYAngle() < 0 && i.second == 11 ||
                       i.first->getSensor()->getYAngle() > 0 && i.second == 10) {
                jack->increaseRelation();
            } else if (i.first->getSensor()->getYAngle() < 0 && i.second == 10 ||
                       i.first->getSensor()->getYAngle() > 0 && i.second == 11) {
                jack->decreaseRelation();
            }
        }
    }
};
vector<shared_ptr<Jack>> House::greatestIncline(){
    int highest = 0;
    vector<shared_ptr<Jack>> work{};
    for(auto i : jacks){
        if(abs(i->getRelation())> highest){
            highest = abs(i->getRelation());
        }
    }
    if (highest == 0) {
        return work;
    }
    for(auto i : jacks){
        if(abs(i->getRelation()) == highest){
            work.push_back(i);
        }
    }
    return work;
}
void House::workJacks(vector<shared_ptr<Jack>> work) {
    for(auto i : work){
        if(i->getRelation() < 0){
            i->raise();
        }
        else{
            i->lower();
        }
    }
}
bool House::addJack(const double &h){
    shared_ptr<Jack> jack(new Jack(counterID++,h));
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
		if (hold > (i->getSensor()->getPrecision()*2.1)) {
			return false;
		}
	}
	return true;
}
void House::levelOnce(){
    if(checkLevel()){
        return;
    }
    findRelations();
    workJacks(greatestIncline());
    emuAngles();
    return;
}
void House::autoLevel(){
    while(!checkLevel()){
        levelOnce();
    }
}