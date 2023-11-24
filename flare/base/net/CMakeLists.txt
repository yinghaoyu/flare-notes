add_executable(endpoint_test endpoint_test.cc)
target_link_libraries(endpoint_test ${IN_LIBS} gtest_main)

add_executable(endpoint_benchmark endpoint_benchmark.cc)
target_link_libraries(endpoint_benchmark ${IN_LIBS} benchmark_main)

add_executable(uri_test uri_test.cc)
target_link_libraries(uri_test ${IN_LIBS} gtest_main)

add_executable(uri_extension_test uri_extension_test.cc)
target_link_libraries(uri_extension_test ${IN_LIBS}) # 不需要 gtest_main
