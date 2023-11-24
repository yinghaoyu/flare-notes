add_executable(compression_compression_test compression_test.cc)
target_link_libraries(compression_compression_test ${IN_LIBS} gtest_main)

add_executable(util_test util_test.cc)
target_link_libraries(util_test ${IN_LIBS} gtest_main)
