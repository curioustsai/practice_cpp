project(ch3-Stack)

file(GLOB CPP_SOURCE)
foreach(SRC ${CPP_SOURCE})
    build_singleton(SRC)
endforeach()
