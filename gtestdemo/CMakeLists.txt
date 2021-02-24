cmake_minimum_required(VERSION 3.10)

project(test)

add_executable(test
	main.cpp
	src/A.cpp)

target_include_directories(test PUBLIC
	"include"
    )
