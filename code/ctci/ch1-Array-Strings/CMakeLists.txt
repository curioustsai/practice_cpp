project(ch1-Array-Strings)

file(GLOB CPP_SOURCE 1.*.cpp)
foreach(SRC ${CPP_SOURCE})
    build_singleton(${SRC})
endforeach()

register_test(String.cpp)
