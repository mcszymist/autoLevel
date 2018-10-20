#ifndef EMU_H
#define EMU_H
#include <map>
#include "jack.h"


class Emu{
    private:
        map<int,Emu_Sensor> sensors;
        map<int,Emu_Sensor> jackToSensor;
        vector<Jack> allJacks;
    public:
        Emu(const vector<Jack> &j): allJacks(j){

        };
        void calculateAngles(const int );
        double tiltXAngle(const int &pin);
        double tiltYAngle(const int &pin);
        void setXAngle(const int &pin,const double &angle);
        void setYAngle(const int &pin,const double &angle);
        bool stepMotor(const int &pin);
};
class Emu_Sensor{
    private:
        double xAngle;
        double yAngle;
    public:
        double getXAngle(){ return xAngle; };
        double getYAngle(){ return yAngle; };
        void setXAngle(const double &angle) : xAngle(angle);
        void setYAngle(const double &angle) : yAngle(angle);
}
#endif