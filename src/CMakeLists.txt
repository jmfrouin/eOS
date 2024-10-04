cmake_minimum_required(VERSION 3.29)
project(eOS)

set(CMAKE_CXX_STANDARD 20)

SET(folder core)
FOREACH(fold ${folder})
    ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

include_directories(.)

add_executable(eOS main.cpp
        core/def.h)
