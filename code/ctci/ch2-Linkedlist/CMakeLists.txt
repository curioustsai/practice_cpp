project(ch2-Linkedlist)

file(GLOB CPP_SOURCE *.cpp)
foreach(SRC ${CPP_SOURCE})
    build_singleton(${SRC})
endforeach()
