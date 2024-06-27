cmake_minimum_required(VERSION 3.10)
project(show-weather)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(show-weather src/main.cpp src/weather.cpp)

find_package(CURL REQUIRED)
target_link_libraries(show-weather CURL::libcurl)
