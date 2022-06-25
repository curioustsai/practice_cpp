project(ch4-Tree-Graph)

file(GLOB CPP_SOURCE 4.*.cpp)
foreach(SRC ${CPP_SOURCE})
    build_singleton(${SRC})
endforeach()

register_test(Graph.cpp)
register_test(DistantGraph.cpp)
register_test(Tree.cpp)
register_test(Tries.cpp)
