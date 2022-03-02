cmake_minimum_required(VERSION 3.2)
project(MonotropicOptimization)

add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE Debug)

find_package(Boost 1.78.0 COMPONENTS log REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_definitions(-DHAVE_BOOST)
endif()


add_library(utils 
   src/utils/logger.h 
   src/utils/timer.h
   src/utils/utils.cc
)

add_executable(run-scenario src/main.cc)
target_link_libraries(run-scenario PRIVATE utils)

message(STATUS "foo include dir: ${Boost_LIBRARIES}")
target_link_libraries(run-scenario LINK_PUBLIC ${Boost_LIBRARIES} )