#ifndef JACK_H
#define JACK_H
#include "sensor.h"
//ScrewJack motorized

class Jack{
private:
    const int maxHeigh = 100;
    const int minHeight = 10;
    double stepSize;
    double height;
    const int bCanStep();
    Sensor *sense;
    vector<shared_ptr<Jack>> adjacencent;
    static int ID;
    const int currentID;
public:
    Jack(const double &step,const double &h):stepSize(step),height(h),currentID(ID++) {

    };
    Sensor getSensor(){
        return *(sense);
    }
    void makeSensor(const int &id){
        sense = new Sensor(id);
    }
    const bool stepHeight(const int &h);
    const bool bIsGood();
    const bool addAdjJack(shared_ptr<Jack> jack);
    const bool removeAdjJack(shared_ptr<Jack> jack);
    const vector<shared_ptr<Jack>> getList(){
        return adjacencent;
    }
    const int getID(){
        return currentID;
    };

};
#endif