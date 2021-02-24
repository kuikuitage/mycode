cmake_minimum_required(VERSION 3.10)

project(Aut)

add_executable(Aut
	Aut.cpp
	../src/A.cpp)

target_include_directories(Aut PUBLIC
	"../include"
    )

target_link_libraries(Aut PUBLIC gtest_main gtest pthread)
