project(ch17-Hard)

file(GLOB CPP_SOURCE 16.*.cpp)
foreach(SRC ${CPP_SOURCE})
  register_test(${SRC})
endforeach()
