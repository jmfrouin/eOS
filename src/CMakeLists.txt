cmake_minimum_required(VERSION 3.28)
project(eOS)

set(CMAKE_CXX_STANDARD 20)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add Google Test
add_subdirectory(exts/googletest)
include_directories(exts/googletest/googletest/include)
include_directories(/opt/homebrew/include)

include_directories(.)
add_compile_definitions(MACOS)
add_compile_definitions(WITH_SDL2)
ADD_DEFINITIONS(-DEOS_ENABLE_LOG)

SET(folder Core Interface)
FOREACH(fold ${folder})
    ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

add_executable(eOS EP.cpp)

target_link_libraries(eOS ${SDL2_LIBRARIES} Core Interface)

# Unit tests
file(GLOB_RECURSE Test_src Tests/*.cpp)
add_executable(runTests ${Test_src}
        Tests/TestMemory.cpp
        Tests/TestLog.cpp)
target_link_libraries(runTests gtest gtest_main Core Interface)