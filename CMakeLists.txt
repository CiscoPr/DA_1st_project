cmake_minimum_required(VERSION 3.21)
project(DA_project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_project1 main.cpp FileReader.cpp FileReader.h Parcel.cpp Parcel.h Van.cpp Van.h Courier.cpp Courier.h Menu.cpp Menu.h)
