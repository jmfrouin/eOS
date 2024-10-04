file(GLOB_RECURSE core_src *.cpp *.h)
ADD_LIBRARY(core ${core_src})
#TARGET_LINK_LIBRARIES(engine tools)