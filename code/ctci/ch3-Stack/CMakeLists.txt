project(ch3-Stack)

file(GLOB CPP_SOURCE *.cpp)
foreach(SRC ${CPP_SOURCE})
    build_singleton(${SRC})
endforeach()
