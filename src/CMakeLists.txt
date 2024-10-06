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

include_directories(.)

add_executable(eOS EP.cpp)

TARGET_LINK_LIBRARIES(eOS Core)

# Unit tests
add_executable(runTests tests/TestFile.cpp tests/TestDir.cpp)
target_link_libraries(runTests gtest gtest_main Core)