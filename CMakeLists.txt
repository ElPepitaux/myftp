cmake_minimum_required(VERSION 3.10)

project(myftp)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES asio system)

include(FetchContent)

FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
    URL_MD5 893b5203b862eb9bbd08553e24ff146a # Replace with the correct MD5 for your chosen version
    DOWNLOAD_NO_EXTRACT FALSE
)

FetchContent_MakeAvailable(Boost)

include_directories(headers)

file(GLOB SOURCES "sources/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::asio Boost::system)


