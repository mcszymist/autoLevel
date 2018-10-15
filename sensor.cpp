//
// Created by zym on 10/15/18.
//
#include <string>
using std::string;
#include <cstdlib>
using std::strtod;
#include "sensor.h"

const double Sensor::getXAngle(){
    if(!port->IsConnected()){
        return 0;
    }
    char incomingData[256] = "";			// don't forget to pre-allocate memory

    int dataLength = 255;
    int readResult = 0;

    readResult = port->ReadData(incomingData, dataLength);

    incomingData[readResult] = 0;
    string str(incomingData);
    xAngle = arcsin((stod(str)-offset)/sensitivity);
    return xAngle;
};
const double Sensor::getYAngle(){
    if(!port->IsConnected()){
        return 0;
    }
    char incomingData[256] = "";			// don't forget to pre-allocate memory

    int dataLength = 255;
    int readResult = 0;

    readResult = port->ReadData(incomingData, dataLength);

    incomingData[readResult] = 0;
    string str(incomingData);
    yAngle = arcsin((stod(str)-offset)/sensitivity);
    return yAngle;
};
void Sensor::setAngles(const double &x,const double &y){
    xAngle = x;
    yAngle = y;
}
const double Sensor::getPrecision() {
    return precision;
}