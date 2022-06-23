project(ch5-Bit-Manipulation)

file(GLOB CPP_SOURCE 5.*.cpp)
foreach(SRC ${CPP_SOURCE})
    build_singleton(${SRC})
endforeach()

register_test(BitManipulate.cpp)
