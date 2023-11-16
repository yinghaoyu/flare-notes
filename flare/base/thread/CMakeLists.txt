add_executable(latch_test latch_test.cc)
target_link_libraries(latch_test ${IN_LIBS} gtest_main)

add_executable(attribute_test attribute_test.cc)
target_link_libraries(attribute_test ${IN_LIBS} gtest_main)
