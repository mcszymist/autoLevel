#ifndef EMU_H
#define EMU_H
#include <memory>
using std::shared_ptr;
#include "jack.h"

//The angle is calculated by taken the height of other jacks and using pathageoms theorem to estimate this wouldn't work
//in the real world but works for testing purpose.
//all math is in cm
class Emu{
    private:
        const double distance = 800;
        double tiltXAngle(shared_ptr<Jack> &jack);
        double tiltYAngle(shared_ptr<Jack> &jack);
        void setAngle(shared_ptr<Jack> &jack,const double &x,const double &y);

    public:
        void calculateAngles(shared_ptr<Jack> &jack);
        void calculateAllAngles(vector<shared_ptr<Jack>> &jack);
};

#endif