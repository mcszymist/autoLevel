#ifndef SENSOR_H
#define SENSOR_H
#include <memory>
using std::shared_ptr;
//Sensor SCA100T-D02
#include "SerialClass.h"	// Library described above
class Sensor{
private:
    shared_ptr<Serial> port;
    const double precision = .1;
    //SCA100T-D01
    const double sensitivity = 4;
    const double offset = 2.5;
    double xAngle = 0.0;
    double yAngle = 0.0;
    int id;
public:

    Sensor(const int &name, shared_ptr<Serial> &p): id(name),port(p){

    }
    const double getXAngle();
    const double getYAngle();
    void setAngles(const double &x,const double &y);
	const double getPrecision();
};
#endif