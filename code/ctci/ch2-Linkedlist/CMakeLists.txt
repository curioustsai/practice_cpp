project(ch2-Linkedlist)

file(GLOB CPP_SOURCE)
foreach(SRC ${CPP_SOURCE})
    build_singleton(SRC)
endforeach()
