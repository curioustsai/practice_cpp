project(blind75_interval)

file(GLOB CPP_SOURCES *.cpp)
foreach(SRC ${CPP_SOURCES})
  register_test(${SRC})
endforeach()
