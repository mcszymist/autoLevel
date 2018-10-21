//
// Created by zym on 10/15/18.
//
#include <string>
using std::string;
#include <cstdlib>
using std::strtod;
#include <cmath>
using std::asin;

#include "sensor.h"

const double Sensor::getXAngle(){
    return xAngle;
};
const double Sensor::getYAngle(){
    return yAngle;
};
void Sensor::setAngles(const double &x,const double &y){
    xAngle = x;
    yAngle = y;
}
const double Sensor::getPrecision() {
    return precision;
}