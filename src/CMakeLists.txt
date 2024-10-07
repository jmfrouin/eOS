cmake_minimum_required(VERSION 3.29)
project(eOS)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(MACOS)

SET(folder Core)
FOREACH(fold ${folder})
    ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

# Add Google Test
add_subdirectory(exts/googletest)
include_directories(exts/googletest/googletest/include)
include_directories(/opt/homebrew/include)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(.)

add_executable(eOS EP.cpp)

target_link_libraries(eOS ${SDL2_LIBRARIES} Core)

# Unit tests
file(GLOB_RECURSE Test_src Tests/*.cpp)
add_executable(runTests ${Test_src})
if(APPLE)

    target_link_libraries(runTests /opt/homebrew/lib/libcairo.dylib)
endif(APPLE)
target_link_libraries(runTests gtest gtest_main Core)