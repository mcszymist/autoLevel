#ifndef SENSOR_H
#define SENSOR_H
#include <memory>
using std::shared_ptr;
#include "SerialPort.hpp"

#include "SerialPort.hpp"
using namespace mn::CppLinuxSerial;
//Sensor SCA100T-D02
class Sensor{
private:
    const double precision = .000038;
    shared_ptr<SerialPort> serial;
    //SCA100T-D01
    double xAngle = 0.0;
    double yAngle = 0.0;
    int pin;
public:

    Sensor(shared_ptr<SerialPort> s,const int &name): serial(s),pin(name){

    }
    const double getXAngle();
    const double getYAngle();
    void setAngles(const double &x,const double &y);
	const double getPrecision();
};
#endif