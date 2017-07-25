cmake_minimum_required(VERSION 3.7)
project(linearList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.h LinearList.h SimpleLinearList.h CommonFunc.cpp LinearListOperator.h LinearLab.cpp)
add_executable(linearList ${SOURCE_FILES})