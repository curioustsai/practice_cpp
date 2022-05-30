project(ch1-Array-Strings)

file(GLOB CPP_SOURCE *.cpp)
foreach(SRC ${CPP_SOURCE})
    build_singleton(${SRC})
endforeach()
