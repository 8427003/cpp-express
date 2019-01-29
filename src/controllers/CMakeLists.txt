cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") 

aux_source_directory(. ALL_CONTROLLERS)

add_library (controllers ${ALL_CONTROLLERS})

target_link_libraries(controllers -lcrypto)
target_link_libraries(controllers -lboost_system)
target_link_libraries(controllers -lssl)
target_link_libraries(controllers -lproxygenhttpserver)
target_link_libraries(controllers -lfolly)
target_link_libraries(controllers -ldouble-conversion)
target_link_libraries(controllers -lglog)
target_link_libraries(controllers -lgflags)
