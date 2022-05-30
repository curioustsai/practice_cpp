cmake_minimum_required(VERSION 3.16)

function(register_test SRC)
    get_filename_component(basename_cpp ${SRC} NAME)

    string(REPLACE ".cpp" "" testname ${basename_cpp})

    add_executable(${testname} ${SRC})

    target_link_libraries(${testname} gtest_main)

    gtest_discover_tests(${testname})
endfunction()

function(build_singleton SRC)
    get_filename_component(basename_cpp ${SRC} NAME)

    string(REPLACE ".cpp" "" testname ${basename_cpp})

    add_executable(${testname} ${SRC})
endfunction()
