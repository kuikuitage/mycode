project(QViewpad)
cmake_minimum_required(VERSION 3.6)

set(CMAKE_AUTOMOC ON)

set(SOURCES qtut.cpp ../PanelItem.cpp main.cpp)
set(HEADERS ../PanelItem.h)

find_package(Qt5 COMPONENTS Widgets Gui Core PrintSupport Test REQUIRED)

add_executable(viewpad ${SOURCES})
include_directories(../)


set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -fno-inline -fno-builtin -fprofile-arcs -ftest-coverage -O1")

target_link_libraries(viewpad gcov gtest gtest_main pthread Qt5::Widgets Qt5::Core Qt5::Test)
