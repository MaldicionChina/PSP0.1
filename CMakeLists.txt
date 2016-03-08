cmake_minimum_required(VERSION 2.8)
project(PSP0_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

##########################################
######## Set Variables             #######
##########################################

set(INCLUDE ${CMAKE_SOURCE_DIR}/inc)
set(SOURCE ${CMAKE_SOURCE_DIR}/src)
set(TEST ${CMAKE_SOURCE_DIR}/test)

##########################################
####### Library's Header Included #######
##########################################
include_directories(${INCLUDE})

##########################################
######## Build libraries           #######
##########################################

set(processFile ${INCLUDE}/ProcessFile.hpp)
add_library(processFile SHARED ${SOURCE}/ProcessFile.cpp)

##########################################
############   Build test  ###############
##########################################
# Add and run CMakeLists.txt inside 'test' folder
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(PSP0_1 ${SOURCE_FILES})