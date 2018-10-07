#ifndef HOUSE_H
#define HOUSE_H

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
    bool bIsGoesUpDownS(shared_ptr<Jack> jack);
    shared_ptr<Jack> greatestIncline();
public:
    void buildList();
    bool addJack(const double &step,const double &h);
    bool addSensor(shared_ptr<Jack> jack,const int &id){
        jack->makeSensor(id);
    };
    bool removeJack(const int &id);
    bool bIsGood();
    void checkLevel();
    void buildFloor();
};
#endif