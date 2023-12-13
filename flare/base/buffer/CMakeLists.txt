add_executable(compression_output_stream_test compression_output_stream_test.cc)
target_link_libraries(compression_output_stream_test ${IN_LIBS}  gtest_main)

add_executable(packing_test packing_test.cc)
target_link_libraries(packing_test ${IN_LIBS} gtest_main)

add_executable(buffer_view_test view_test.cc)
target_link_libraries(buffer_view_test ${IN_LIBS} gtest_main)

add_executable(zero_copy_stream_test zero_copy_stream_test.cc)
target_link_libraries(zero_copy_stream_test ${IN_LIBS} gtest_main)
