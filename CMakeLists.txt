cmake_minimum_required(VERSION 3.12)
project(autoLevel)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(
        autoLevelMain
        catch.hpp
        house.cpp
        house.h
        jack.cpp
        jack.h
        sensor.h
        emu.cpp
        emu.h
        sensor.cpp
        SerialPort.cpp
        SerialPort.hpp
        Exception.hpp
        main.cpp
        sqlite3.c
        sqlite3.h
        sqlInterface.h
        sqlite3ext.h
)
add_executable(
        autoLevelTest
        catch.hpp
        house.cpp
        house.h
        jack.cpp
        jack.h
        sensor.h
        emu.cpp
        emu.h
        sensor.cpp
        Exception.hpp
        sqlite3.c
        sqlite3.h
        sqlInterface.h
        sqlite3ext.h
        testsuite.cpp
        SerialPortDummy.cpp SerialPortDummy.h)

target_compile_definitions(autoLevelMain PRIVATE TESTING=0)
target_compile_definitions(autoLevelTest PRIVATE TESTING=1)

target_link_libraries(autoLevelMain ${CMAKE_DL_LIBS})
target_link_libraries(autoLevelTest ${CMAKE_DL_LIBS})
