project(ch4-Tree-Graph)

file(GLOB CPP_SOURCE)
foreach(SRC ${CPP_SOURCE})
    build_singleton(SRC)
endforeach()
