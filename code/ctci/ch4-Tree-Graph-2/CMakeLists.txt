project(ch4-Tree-Graph-2)

file(GLOB CPP_SOURCES *.cpp)
foreach(SRC ${CPP_SOURCES})
    register_test(${SRC})
endforeach()
