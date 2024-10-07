SET(folder Base)
FOREACH(fold ${folder})
    ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

file(GLOB_RECURSE Interface_src *.cpp *.h)
ADD_LIBRARY(Interface ${Interface_src} Base)
