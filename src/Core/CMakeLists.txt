file(GLOB_RECURSE Core_src *.cpp *.h)
ADD_LIBRARY(Core ${Core_src}
        Log.h
        Log.cpp)
#TARGET_LINK_LIBRARIES(engine tools)