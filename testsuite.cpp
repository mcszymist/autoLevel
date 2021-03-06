#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "house.h"
#if TESTING
#include "SerialPortDummy.h"
#else
#include "SerialPort.hpp"
#endif


using namespace mn::CppLinuxSerial;

TEST_CASE("Serial Testing", "[Serial]"){
    SerialPort serial("/dev/ttyACM0",BaudRate::B_115200);
    serial.Open();
    std::string readData;
    readData = serial.recvWithStartEndMarkers();
    REQUIRE(readData == "Arduino is ready");
    serial.Write("<5,1>");
	readData = serial.recvWithStartEndMarkers();
    REQUIRE(readData == "0");
	serial.Write("<1,1>");
	readData = serial.recvWithStartEndMarkers();
	REQUIRE(stoi(readData) < 1000);
}

TEST_CASE( "house basic test", "[baisc]" ) {

    House house;
    house.addJack(40.0,1);		// bottom right
    house.addJack(50.0,2);		// bottom left
	house.addJack(50.0,3);		// top left
	house.addJack(50.0,4);		// top right
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],1);
	saved[0]->addAdjJack(saved[3],10);
	saved[1]->addAdjJack(saved[0],0);
	saved[1]->addAdjJack(saved[2],10);
	saved[2]->addAdjJack(saved[3],0);
	saved[2]->addAdjJack(saved[1],11);
	saved[3]->addAdjJack(saved[0],11);
	saved[3]->addAdjJack(saved[2],1);
	saved[3]->addAdjJack(saved[1],11);
	REQUIRE(saved[3]->isAdjacent(saved[1]) == true);
	saved[3]->removeAdjJack(saved[1]);
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	REQUIRE(saved[3]->isAdjacent(saved[0])==true);
	REQUIRE(saved[3]->isAdjacent(saved[1]) == false);
    REQUIRE(house.bIsGood()==true);
	
	saved[0]->getSensor()->setAngles(20.0, 20.0);
	saved[1]->getSensor()->setAngles(15.0, 11.0);
	saved[2]->getSensor()->setAngles(0.0, 0.0);
	saved[3]->getSensor()->setAngles(15.0, 11.0);
	REQUIRE(house.checkLevel() == false);
}
TEST_CASE("sensorCheck", "[basic]") {
	House house;
	house.addJack(40.0,1);		// bottom right
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
	house.addJack(100.0,5);		// bottom right
	auto saved = house.getJacks();
	REQUIRE(saved[0]->raise() == false);
	REQUIRE(saved[0]->lower());
	REQUIRE(saved[0]->lower());
	REQUIRE(saved[0]->raise() == true);
	house.addJack(10.0,6);		// bottom right
	saved = house.getJacks();
	REQUIRE(saved[1]->lower() == false);
	REQUIRE(saved[1]->raise());
	REQUIRE(saved[1]->raise());
	REQUIRE(saved[1]->lower() == true);

}
TEST_CASE("checklevel test", "[basic]") {
	House house;
	house.addJack(40.0,7);		// bottom right
	house.addJack(50.0,8);		// bottom left
	house.addJack(50.0,9);		// top left
	house.addJack(50.0,1);		// top right
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],1);
	saved[0]->addAdjJack(saved[3],10);
	saved[1]->addAdjJack(saved[0],0);
	saved[1]->addAdjJack(saved[2],10);
	saved[2]->addAdjJack(saved[3],0);
	saved[2]->addAdjJack(saved[1],11);
	saved[3]->addAdjJack(saved[0],11);
	saved[3]->addAdjJack(saved[2],1);

	saved[0]->getSensor()->setAngles(2.0, 2.0);
	saved[1]->getSensor()->setAngles(1.0, 1.0);
	saved[2]->getSensor()->setAngles(0.0, 0.0);
	saved[3]->getSensor()->setAngles(1.0, 1.0);

	REQUIRE(house.checkLevel() == false);
	saved[0]->getSensor()->setAngles(.3, .3);
	saved[1]->getSensor()->setAngles(.1, -0.2);
	saved[2]->getSensor()->setAngles(.2, .1);
	saved[3]->getSensor()->setAngles(.1, .1);
	REQUIRE(house.checkLevel() == false);
	saved[0]->getSensor()->setAngles(.3, .39);
	saved[1]->getSensor()->setAngles(0, 00);
	saved[2]->getSensor()->setAngles(0, 0.0);
	saved[3]->getSensor()->setAngles(0, 0);
	REQUIRE(house.checkLevel() == false);
	saved[0]->getSensor()->setAngles(-.6, .09);
	saved[1]->getSensor()->setAngles(0, 00);
	saved[2]->getSensor()->setAngles(0, 0.0);
	saved[3]->getSensor()->setAngles(0, 0);
	REQUIRE(house.checkLevel() == false);
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
TEST_CASE("checklevel Emu_Test", "[Tester]") {
	House house;
	house.addJack(40.0,1);		// bottom right
	house.addJack(50.0,2);		// bottom left
	house.addJack(70.0,3);		// top left
	house.addJack(20.0,4);		// top right
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],1);
	saved[0]->addAdjJack(saved[3],10);
	saved[1]->addAdjJack(saved[0],0);
	saved[1]->addAdjJack(saved[2],10);
	saved[2]->addAdjJack(saved[3],0);
	saved[2]->addAdjJack(saved[1],11);
	saved[3]->addAdjJack(saved[0],11);
	saved[3]->addAdjJack(saved[2],1);
	house.emuAngles();
	REQUIRE(house.checkLevel()==false);
	house.printAllInfo();

}
TEST_CASE("checklevel Emu_Test2", "[Tester]") {
	House house;
	house.addJack(50.0,1);		// bottom right
	house.addJack(50.0,2);		// bottom left
	house.addJack(50.0,3);		// top left
	house.addJack(50.0,4);		// top right
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],1);
	saved[0]->addAdjJack(saved[3],10);
	saved[1]->addAdjJack(saved[0],0);
	saved[1]->addAdjJack(saved[2],10);
	saved[2]->addAdjJack(saved[3],0);
	saved[2]->addAdjJack(saved[1],11);
	saved[3]->addAdjJack(saved[0],11);
	saved[3]->addAdjJack(saved[2],1);
	house.emuAngles();
	house.levelOnce();
	REQUIRE(house.checkLevel()==true);
	REQUIRE(saved[0]->getSensor()->getXAngle() == 0.0);
	REQUIRE(saved[0]->getSensor()->getYAngle() == 0.0);
	REQUIRE(saved[1]->getSensor()->getXAngle() == 0.0);
	REQUIRE(saved[1]->getSensor()->getYAngle() == 0.0);
	REQUIRE(saved[2]->getSensor()->getXAngle() == 0.0);
	REQUIRE(saved[2]->getSensor()->getYAngle() == 0.0);
	REQUIRE(saved[3]->getSensor()->getXAngle() == 0.0);
	REQUIRE(saved[3]->getSensor()->getYAngle() == 0.0);

}
TEST_CASE("Emu_Test leveling four jack", "[Tester]") {
	House house;
	house.addJack(40.0,1);		// bottom right
	house.addJack(45.0,2);		// bottom left
	house.addJack(45.0,3);		// top left
	house.addJack(50.0,4);		// top right
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],1);
	saved[0]->addAdjJack(saved[3],10);
	saved[1]->addAdjJack(saved[0],0);
	saved[1]->addAdjJack(saved[2],10);
	saved[2]->addAdjJack(saved[3],0);
	saved[2]->addAdjJack(saved[1],11);
	saved[3]->addAdjJack(saved[0],11);
	saved[3]->addAdjJack(saved[2],1);
	house.emuAngles();
	house.printAllInfo();
	house.autoLevel();
	house.printAllInfo();
	REQUIRE(house.checkLevel()==true);
}
TEST_CASE("Emu_Test nine jack", "[Tester]") {
	House house;
	house.addJack(50.0,1);		// top left	0
	house.addJack(50.0,2);		// mid left	1
	house.addJack(50.0,3);		// bot left	2
	house.addJack(50.0,4);		// top mid	3
	house.addJack(50.0,5);		// mid mid	4
	house.addJack(50.0,6);		// bot mid	5
	house.addJack(50.0,7);		// top right6
	house.addJack(50.0,8);		// mid right7
	house.addJack(50.0,9);		// bot right8
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],11);
	saved[0]->addAdjJack(saved[3],0);

	saved[1]->addAdjJack(saved[0],10);
	saved[1]->addAdjJack(saved[4],0);
	saved[1]->addAdjJack(saved[2],11);

	saved[2]->addAdjJack(saved[5],0);
	saved[2]->addAdjJack(saved[1],10);

	saved[3]->addAdjJack(saved[0],1);
	saved[3]->addAdjJack(saved[6],0);
	saved[3]->addAdjJack(saved[4],11);

	saved[4]->addAdjJack(saved[1],1);
	saved[4]->addAdjJack(saved[5],11);
	saved[4]->addAdjJack(saved[7],0);
	saved[4]->addAdjJack(saved[3],10);

	saved[5]->addAdjJack(saved[2],1);
	saved[5]->addAdjJack(saved[8],0);
	saved[5]->addAdjJack(saved[4],10);

	saved[6]->addAdjJack(saved[3],1);
	saved[6]->addAdjJack(saved[7],11);

	saved[7]->addAdjJack(saved[4],1);
	saved[7]->addAdjJack(saved[8],11);
	saved[7]->addAdjJack(saved[6],10);

	saved[8]->addAdjJack(saved[5],1);
	saved[8]->addAdjJack(saved[7],10);
	house.emuAngles();
	REQUIRE(house.checkLevel()==true);
	house.autoLevel();
	house.printAllInfo();
	REQUIRE(house.checkLevel()==true);
}
TEST_CASE("Emu_Test leveling nine jack", "[Tester]") {
	House house;
	house.addJack(30.0,1);		// top left	0
	house.addJack(40.0,2);		// mid left	1
	house.addJack(50.0,3);		// bot left	2
	house.addJack(40.0,4);		// top mid	3
	house.addJack(50.0,5);		// mid mid	4
	house.addJack(60.0,6);		// bot mid	5
	house.addJack(50.0,7);		// top right6
	house.addJack(60.0,8);		// mid right7
	house.addJack(70.0,9);		// bot right8
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],11);
	saved[0]->addAdjJack(saved[3],0);

	saved[1]->addAdjJack(saved[0],10);
	saved[1]->addAdjJack(saved[4],0);
	saved[1]->addAdjJack(saved[2],11);

	saved[2]->addAdjJack(saved[5],0);
	saved[2]->addAdjJack(saved[1],10);

	saved[3]->addAdjJack(saved[0],1);
	saved[3]->addAdjJack(saved[6],0);
	saved[3]->addAdjJack(saved[4],11);

	saved[4]->addAdjJack(saved[1],1);
	saved[4]->addAdjJack(saved[5],11);
	saved[4]->addAdjJack(saved[7],0);
	saved[4]->addAdjJack(saved[3],10);

	saved[5]->addAdjJack(saved[2],1);
	saved[5]->addAdjJack(saved[8],0);
	saved[5]->addAdjJack(saved[4],10);

	saved[6]->addAdjJack(saved[3],1);
	saved[6]->addAdjJack(saved[7],11);

	saved[7]->addAdjJack(saved[4],1);
	saved[7]->addAdjJack(saved[8],11);
	saved[7]->addAdjJack(saved[6],10);

	saved[8]->addAdjJack(saved[5],1);
	saved[8]->addAdjJack(saved[7],10);
	house.emuAngles();
	REQUIRE(house.checkLevel()==false);
	house.autoLevel();
	house.printAllInfo();
	REQUIRE(house.checkLevel()==true);
}
TEST_CASE("Emu_Test leveling nine jack min-max", "[Tester]") {
	House house;
	house.addJack(10.0,1);		// top left	0
	house.addJack(10.0,2);		// mid left	1
	house.addJack(10.0,3);		// bot left	2
	house.addJack(10.0,4);		// top mid	3
	house.addJack(10.0,5);		// mid mid	4
	house.addJack(100.0,6);		// bot mid	5
	house.addJack(100.0,7);		// top right6
	house.addJack(100.0,8);		// mid right7
	house.addJack(100.0,9);		// bot right8
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],11);
	saved[0]->addAdjJack(saved[3],0);

	saved[1]->addAdjJack(saved[0],10);
	saved[1]->addAdjJack(saved[4],0);
	saved[1]->addAdjJack(saved[2],11);

	saved[2]->addAdjJack(saved[5],0);
	saved[2]->addAdjJack(saved[1],10);

	saved[3]->addAdjJack(saved[0],1);
	saved[3]->addAdjJack(saved[6],0);
	saved[3]->addAdjJack(saved[4],11);

	saved[4]->addAdjJack(saved[1],1);
	saved[4]->addAdjJack(saved[5],11);
	saved[4]->addAdjJack(saved[7],0);
	saved[4]->addAdjJack(saved[3],10);

	saved[5]->addAdjJack(saved[2],1);
	saved[5]->addAdjJack(saved[8],0);
	saved[5]->addAdjJack(saved[4],10);

	saved[6]->addAdjJack(saved[3],1);
	saved[6]->addAdjJack(saved[7],11);

	saved[7]->addAdjJack(saved[4],1);
	saved[7]->addAdjJack(saved[8],11);
	saved[7]->addAdjJack(saved[6],10);

	saved[8]->addAdjJack(saved[5],1);
	saved[8]->addAdjJack(saved[7],10);
	house.emuAngles();
	REQUIRE(house.checkLevel()==false);
	house.autoLevel();
	house.printAllInfo();
	REQUIRE(house.checkLevel()==true);
}
TEST_CASE("Emu_Test leveling six jack", "[Tester]") {
	House house;
	house.addJack(10.0,1);		// top left	0
	house.addJack(10.0,2);		// bot left	1
	house.addJack(10.0,3);		// top mid	2
	house.addJack(100.0,4);		// bot mid	3
	house.addJack(100.0,5);		// top right4
	house.addJack(100.0,6);		// bot right5
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],11);
	saved[0]->addAdjJack(saved[2],0);

	saved[1]->addAdjJack(saved[0],10);
	saved[1]->addAdjJack(saved[3],0);

	saved[2]->addAdjJack(saved[0],1);
	saved[2]->addAdjJack(saved[3],11);
	saved[2]->addAdjJack(saved[4],0);

	saved[3]->addAdjJack(saved[1],1);
	saved[3]->addAdjJack(saved[2],10);
	saved[3]->addAdjJack(saved[5],0);

	saved[4]->addAdjJack(saved[2],1);
	saved[4]->addAdjJack(saved[5],11);

	saved[5]->addAdjJack(saved[4],10);
	saved[5]->addAdjJack(saved[3],1);

	house.emuAngles();
	REQUIRE(house.checkLevel()==false);
	house.autoLevel();
	house.printAllInfo();
	REQUIRE(house.checkLevel()==true);
}

TEST_CASE("Emu_Test leveling six jack alternating", "[Tester]") {
    House house;
    house.addJack(20.0,1);		// top left	0
    house.addJack(70.0,2);		// bot left	1
    house.addJack(20.0,3);		// top mid	2
    house.addJack(70.0,4);		// bot mid	3
    house.addJack(20.0,5);		// top right4
    house.addJack(70.0,6);		// bot right5
    for (auto i : house.getJacks()) {
        i->makeSensor(10);
    }
    auto saved = house.getJacks();
    saved[0]->addAdjJack(saved[1],11);
    saved[0]->addAdjJack(saved[2],0);

    saved[1]->addAdjJack(saved[0],10);
    saved[1]->addAdjJack(saved[3],0);

    saved[2]->addAdjJack(saved[0],1);
    saved[2]->addAdjJack(saved[3],11);
    saved[2]->addAdjJack(saved[4],0);

    saved[3]->addAdjJack(saved[1],1);
    saved[3]->addAdjJack(saved[2],10);
    saved[3]->addAdjJack(saved[5],0);

    saved[4]->addAdjJack(saved[2],1);
    saved[4]->addAdjJack(saved[5],11);

    saved[5]->addAdjJack(saved[4],10);
    saved[5]->addAdjJack(saved[3],1);

    house.emuAngles();
    REQUIRE(house.checkLevel()==false);
    house.autoLevel();
    house.printAllInfo();
    REQUIRE(house.checkLevel()==true);
}
TEST_CASE("Emu_Test leveling nine jack alternating", "[Tester]") {
	House house;
	house.addJack(50.0,1);		// top left	0
	house.addJack(70.0,2);		// mid left	1
	house.addJack(50.0,3);		// bot left	2
	house.addJack(70.0,4);		// top mid	3
	house.addJack(50.0,5);		// mid mid	4
	house.addJack(70.0,6);		// bot mid	5
	house.addJack(50.0,7);		// top right6
	house.addJack(70.0,8);		// mid right7
	house.addJack(50.0,9);		// bot right8
	for (auto i : house.getJacks()) {
		i->makeSensor(10);
	}
	auto saved = house.getJacks();
	saved[0]->addAdjJack(saved[1],11);
	saved[0]->addAdjJack(saved[3],0);

	saved[1]->addAdjJack(saved[0],10);
	saved[1]->addAdjJack(saved[4],0);
	saved[1]->addAdjJack(saved[2],11);

	saved[2]->addAdjJack(saved[5],0);
	saved[2]->addAdjJack(saved[1],10);

	saved[3]->addAdjJack(saved[0],1);
	saved[3]->addAdjJack(saved[6],0);
	saved[3]->addAdjJack(saved[4],11);

	saved[4]->addAdjJack(saved[1],1);
	saved[4]->addAdjJack(saved[5],11);
	saved[4]->addAdjJack(saved[7],0);
	saved[4]->addAdjJack(saved[3],10);

	saved[5]->addAdjJack(saved[2],1);
	saved[5]->addAdjJack(saved[8],0);
	saved[5]->addAdjJack(saved[4],10);

	saved[6]->addAdjJack(saved[3],1);
	saved[6]->addAdjJack(saved[7],11);

	saved[7]->addAdjJack(saved[4],1);
	saved[7]->addAdjJack(saved[8],11);
	saved[7]->addAdjJack(saved[6],10);

	saved[8]->addAdjJack(saved[5],1);
	saved[8]->addAdjJack(saved[7],10);
	house.emuAngles();
	REQUIRE(house.checkLevel()==false);
	house.autoLevel();
	house.printAllInfo();
	REQUIRE(house.checkLevel()==true);
}