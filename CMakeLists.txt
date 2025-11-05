cmake_minimum_required(VERSION 3.10)

project(myftp)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)

file(GLOB SOURCES "sources/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
