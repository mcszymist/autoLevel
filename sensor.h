#ifndef SENSOR_H
#define SENSOR_H
//Sensor SCA100T-D02

class Sensor{
private:
    const double presision = 1;
    double xAngle = 0.0;
    double yAngle = 0.0;
    int id;
public:

    Sensor(const Sensor &p2) {id = p2.id;} 
    Sensor(const int &name): id(name){

    }
    const double getXAngle(){
        return xAngle;
    };
    const double getYAngle(){
        return yAngle;
    };
    void setAngles(const double &x,const double &y){
        xAngle = x;
        yAngle = y;
    }
};
#endif