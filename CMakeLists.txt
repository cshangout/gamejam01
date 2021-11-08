cmake_minimum_required(VERSION 3.20)
project(gamejam01)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})




add_executable(gamejam01 main.cpp)
