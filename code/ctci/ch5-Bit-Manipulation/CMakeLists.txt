project(ch5-Bit-Manipulation)

file(GLOB CPP_SOURCE)
foreach(SRC ${CPP_SOURCE})
    build_singleton(SRC)
endforeach()
