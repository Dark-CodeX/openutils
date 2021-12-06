cmake_minimum_required(VERSION 3.0.0)
project (sstring_test1)
add_executable(sstring_test1 "samples/test.c")
target_link_libraries(sstring_test1 m)