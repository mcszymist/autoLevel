/*#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "house.h"

TEST_CASE( "house basic test", "[baisc]" ) {

    House house;
    house.addJack(40.0);		// bottom right
    house.addJack(50.0);		// bottom left
	house.addJack(50.0);		// top left
	house.addJack(50.0);		// top right
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1]);
	saved[0]->addAdjJack(saved[3]);
	saved[1]->addAdjJack(saved[0]);
	saved[1]->addAdjJack(saved[2]);
	saved[2]->addAdjJack(saved[3]);
	saved[2]->addAdjJack(saved[1]);
	saved[3]->addAdjJack(saved[0]);
	saved[3]->addAdjJack(saved[2]);
	saved[3]->addAdjJack(saved[1]);
	REQUIRE(saved[3]->isAdjacent(saved[1]) == true);
	saved[3]->removeAdjJack(saved[1]);
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	REQUIRE(saved[3]->isAdjacent(saved[0])==true);
	REQUIRE(saved[3]->isAdjacent(saved[1]) == false);
    REQUIRE(house.bIsGood()==true);
	REQUIRE(house.greatestIncline() == nullptr);
	
	saved[0]->getSensor()->setAngles(20.0, 20.0);
	saved[1]->getSensor()->setAngles(10.0, 10.0);
	saved[2]->getSensor()->setAngles(0.0, 0.0);
	saved[3]->getSensor()->setAngles(10.0, 10.0);
	REQUIRE(house.greatestIncline() == saved[0]);
	REQUIRE(house.bIsGoesUpDownS(saved[0]) == true);
	REQUIRE(house.checkLevel() == false);
}
TEST_CASE("sensorCheck", "[basic]") {
	House house;
	house.addJack(40.0);		// bottom right
	auto saved = house.getJacks();
	saved[0]->makeSensor(10);
	saved[0]->getSensor()->setAngles(10,10);
	REQUIRE(saved[0]->getSensor()->getXAngle() == 10);
	REQUIRE(saved[0]->getSensor()->getYAngle() == 10);
	saved[0]->getSensor()->setAngles(-10, -10);
	REQUIRE(saved[0]->getSensor()->getXAngle() == -10);
	REQUIRE(saved[0]->getSensor()->getYAngle() == -10);

	
}
TEST_CASE("jackAdjustment", "[basic]") {
	House house;
	house.addJack(100.0);		// bottom right
	auto saved = house.getJacks();
	REQUIRE(saved[0]->raise() == false);
	REQUIRE(saved[0]->lower());
	REQUIRE(saved[0]->lower());
	REQUIRE(saved[0]->raise() == true);
	house.addJack(10.0);		// bottom right
	saved = house.getJacks();
	REQUIRE(saved[1]->lower() == false);
	REQUIRE(saved[1]->raise());
	REQUIRE(saved[1]->raise());
	REQUIRE(saved[1]->lower() == true);

}
TEST_CASE("checklevel test", "[basic]") {
	House house;
	house.addJack(40.0);		// bottom right
	house.addJack(50.0);		// bottom left
	house.addJack(50.0);		// top left
	house.addJack(50.0);		// top right
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1]);
	saved[0]->addAdjJack(saved[3]);
	saved[1]->addAdjJack(saved[0]);
	saved[1]->addAdjJack(saved[2]);
	saved[2]->addAdjJack(saved[3]);
	saved[2]->addAdjJack(saved[1]);
	saved[3]->addAdjJack(saved[0]);
	saved[3]->addAdjJack(saved[2]);

	saved[0]->getSensor()->setAngles(2.0, 2.0);
	saved[1]->getSensor()->setAngles(1.0, 1.0);
	saved[2]->getSensor()->setAngles(0.0, 0.0);
	saved[3]->getSensor()->setAngles(1.0, 1.0);

	REQUIRE(house.checkLevel() == false);
	saved[0]->getSensor()->setAngles(.3, .3);
	saved[1]->getSensor()->setAngles(.1, -0.2);
	saved[2]->getSensor()->setAngles(.2, .1);
	saved[3]->getSensor()->setAngles(.1, .1);
	REQUIRE(house.checkLevel() == true);
	saved[0]->getSensor()->setAngles(.3, .39);
	saved[1]->getSensor()->setAngles(0, 00);
	saved[2]->getSensor()->setAngles(0, 0.0);
	saved[3]->getSensor()->setAngles(0, 0);
	REQUIRE(house.checkLevel() == true);
	saved[0]->getSensor()->setAngles(-.6, .09);
	saved[1]->getSensor()->setAngles(0, 00);
	saved[2]->getSensor()->setAngles(0, 0.0);
	saved[3]->getSensor()->setAngles(0, 0);
	REQUIRE(house.checkLevel() == true);
	saved[0]->getSensor()->setAngles(-.7, .1);
	saved[1]->getSensor()->setAngles(0, 0.0);
	saved[2]->getSensor()->setAngles(0, 0.0);
	saved[3]->getSensor()->setAngles(0, 0.0);
	REQUIRE(house.checkLevel() == false);
	saved[0]->getSensor()->setAngles(.7, -.1);
	saved[1]->getSensor()->setAngles(0, 0.0);
	saved[2]->getSensor()->setAngles(0, 0.0);
	saved[3]->getSensor()->setAngles(0, 0.0);
	REQUIRE(house.checkLevel() == false);
	saved[0]->getSensor()->setAngles(1, 1);
	saved[1]->getSensor()->setAngles(1, 1);
	saved[2]->getSensor()->setAngles(1, 1);
	saved[3]->getSensor()->setAngles(1, 1);
	REQUIRE(house.checkLevel() == false);
}
*/