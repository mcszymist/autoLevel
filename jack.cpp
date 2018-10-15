#include "jack.h"

const bool Jack::raise() {
	if (bCanStep(true)) {
		height += stepSize;
		return true;
	}
	return false;
}
const bool Jack::lower()
{
	if (bCanStep(false)) {
		height -= stepSize;
		return true;
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
	return isGood;
};
const bool Jack::addAdjJack(shared_ptr<Jack> jack)
{
	for (auto i : adjacencent) {
		if(i==jack)
			return true;
	}
	adjacencent.push_back(jack);
	return true;
};
const bool Jack::removeAdjJack(shared_ptr<Jack> jack)
{
	for (size_t i = 0; i < adjacencent.size();i++) {
		if (adjacencent[i] == jack) {
			adjacencent.erase(adjacencent.begin() + i);
			return true;
		}
	}
	return true;
};