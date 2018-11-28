#include <cmath>
using std::atan;
#include <memory>
using std::shared_ptr;

#include "emu.h"

//The angle is calculated by taken the height of other jacks and using pathageoms theorem to estimate this wouldn't work
//in the real world but works for testing purpose.
//	 -> \ positive
//   -> / negative

double Emu::tiltXAngle(shared_ptr<Jack> &jack){

    for(auto i : jack->getList()){
        if(i.second == 1) {
            return -atan((jack->getHeight() - i.first->getHeight())/distance);
        }
        else if(i.second == 0){
            return atan((jack->getHeight() - i.first->getHeight())/distance);
        }
    }
    return 0.0;
}
double Emu::tiltYAngle(shared_ptr<Jack> &jack){
    for(auto i : jack->getList()){
        if(i.second == 11) {
            return -atan((jack->getHeight() - i.first->getHeight())/distance);
        }
        else if(i.second == 10){
            return atan((jack->getHeight() - i.first->getHeight())/distance);
        }
    }
    return 0.0;
}
void Emu::setAngle(shared_ptr<Jack> &jack,const double &x,const double &y){
    jack->getSensor()->setAngles(x,y);
}
void Emu::calculateAngles(shared_ptr<Jack> &jack){
    setAngle(jack,tiltXAngle(jack),tiltYAngle(jack));
}
void Emu::calculateAllAngles(vector<shared_ptr<Jack>> &jacks){
    for(auto i : jacks){
        calculateAngles(i);
    }
}