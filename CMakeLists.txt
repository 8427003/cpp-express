cmake_minimum_required (VERSION 2.6)

project (cpp-express)

#SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14 -pthread")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

include_directories("/opt/local/include")
link_directories("/opt/local/lib")

add_subdirectory ("${PROJECT_SOURCE_DIR}/src/controllers")
add_subdirectory ("${PROJECT_SOURCE_DIR}/src/routers")
add_subdirectory ("${PROJECT_SOURCE_DIR}/src")
