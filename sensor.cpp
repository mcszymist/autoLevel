//
// Created by zym on 10/15/18.
//
#include <string>
using std::string;
#include <cstdlib>
using std::strtod;
#include <cmath>
using std::atan;
using std::pow;
#include <iostream>
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include "sensor.h"

void Sensor::getAngles(){
    serial->Write("<0,0>");
    auto allStr = serial->recvWithStartEndMarkers();
    auto vec = parseRawData(allStr);

    auto xRaw = vec[0];
    auto yRaw = vec[1];
    auto zRaw = vec[2];
    const double xA = (180/3.141592) * atan(xRaw/(sqrt(pow(yRaw,2)+pow(zRaw,2))));
    const double yA = (180/3.141592) * atan(yRaw/(sqrt(pow(xRaw,2)+pow(zRaw,2))));
    xAngle = xA;
    yAngle = yA;
};
const double Sensor::getXAngle(){
    return xAngle;
}
const double Sensor::getYAngle(){
    return yAngle;
}

void Sensor::setAngles(const double &x,const double &y){
    xAngle = x;
    yAngle = y;
}
const double Sensor::getPrecision() {
    return precision;
}
vector<int> Sensor::parseRawData(const string &data){
    std::vector<int> vect;

    std::stringstream ss(data);

    int i;

    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    for (i=0; i< vect.size(); i++)
        std::cout << vect.at(i)<<std::endl;
    return vect;
}