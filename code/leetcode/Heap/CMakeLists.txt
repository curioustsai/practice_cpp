project(blind75_heap)

file(GLOB CPP_SOURCES *.cpp)
foreach(SRC ${CPP_SOURCES})
  register_test(${SRC})
endforeach()
