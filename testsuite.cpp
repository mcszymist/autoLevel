#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "house.h"

TEST_CASE( "house basic creation", "[house]" ) {

    House house;
    house.addJack(1.0,10.0);
    house.addJack(1.0,9.0);
    
    REQUIRE(house.bIsGood()==true);
    REQUIRE(house.removeJack(1)==true);
    
}
