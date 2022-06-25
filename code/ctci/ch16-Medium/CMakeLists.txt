project(ch16-Medium)

file(GLOB CPP_SOURCE 16.*.cpp)
foreach(SRC ${CPP_SOURCE})
  register_test(${SRC})
endforeach()
