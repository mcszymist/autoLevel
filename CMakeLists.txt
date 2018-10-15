cmake_minimum_required(VERSION 3.12)
project(autoLevel)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(autoLevel
        ardiuno.cpp
        catch.hpp
        house.cpp
        house.h
        jack.cpp
        jack.h
        sensor.h
        Serial.cpp
        SerialClass.h
        testsuite.cpp sensor.cpp)
