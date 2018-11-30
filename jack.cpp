#include "jack.h"

const bool Jack::raise() {
	if (bCanStep(true)) {
		serial->Write("<4," + pin + '>');
		if("1" == serial->recvWithStartEndMarkers()){
			height += stepSize;
			return true;
		}
	}
	return false;
}
const bool Jack::lower()
{
	if (bCanStep(false)) {
		serial->Write("<3," + pin + '>');
		if("1" == serial->recvWithStartEndMarkers()){
			height -= stepSize;
			return true;
		}
	}
	return false;
}

//Direction,	true = up
//				false = down
const bool Jack::bCanStep(const bool &direction) {
	if (direction == true) {
		if (height + stepSize >= maxHeight) {
			return false;
		}
	}
	else
	{
		if (height - stepSize <= minHeight) {
			return false;
		}
	}
	return true;
};
const bool Jack::bIsGood()
{
    return true;
};
const bool Jack::addAdjJack(shared_ptr<Jack> jack,const int &direction)
{
	for (auto i : adjacent) {
		if(i.first==jack)
			return true;
	}
	adjacent.push_back(make_pair(jack,direction));
	return true;
};
const bool Jack::removeAdjJack(shared_ptr<Jack> jack)
{
	for (size_t i = 0; i < adjacent.size();i++) {
		if (adjacent[i].first == jack) {
			adjacent.erase(adjacent.begin() + i);
			return true;
		}
	}
	return true;
};