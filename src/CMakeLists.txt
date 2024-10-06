cmake_minimum_required(VERSION 3.29)
project(eOS)

set(CMAKE_CXX_STANDARD 20)

SET(folder Core)
FOREACH(fold ${folder})
    ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

# Add Google Test
add_subdirectory(exts/googletest)
include_directories(exts/googletest/googletest/include)
include_directories(/opt/homebrew/include)

include_directories(.)

add_executable(eOS EP.cpp)

target_link_libraries(eOS Core /opt/homebrew/lib/libcairo.dylib)

# Unit tests
file(GLOB_RECURSE Test_src Tests/*.cpp)
add_executable(runTests ${Test_src})
target_link_libraries(runTests gtest gtest_main Core /opt/homebrew/lib/libcairo.dylib)