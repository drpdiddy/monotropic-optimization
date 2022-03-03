cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)

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

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(test_graph tests/test_graph.cc)
target_link_libraries(test_graph gtest_main)
target_include_directories(test_graph PUBLIC src/)

gtest_discover_tests(test_graph)