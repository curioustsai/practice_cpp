project(dynamic_program)

file(GLOB CPP_SOURCE *.cpp)
foreach(SRC ${CPP_SOURCE})
  register_test(${SRC})
endforeach()
