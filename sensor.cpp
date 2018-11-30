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
    serial->Write("<1," + pin + '>');
    auto angle = stoi(serial->recvWithStartEndMarkers());
    double fAngle = asin(angle * (5.0/1024.0));
    xAngle = fAngle;
    return fAngle;
};
const double Sensor::getYAngle(){
    serial->Write("<2," + pin + '>');
    auto angle = stoi(serial->recvWithStartEndMarkers());
    double fAngle = asin(angle * (5.0/1024.0));
    yAngle = fAngle;
    return fAngle;
};
void Sensor::setAngles(const double &x,const double &y){
    xAngle = x;
    yAngle = y;
}
const double Sensor::getPrecision() {
    return precision;
}