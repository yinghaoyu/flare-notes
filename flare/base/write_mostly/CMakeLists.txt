add_executable(basic_ops_test basic_ops_test.cc)
target_link_libraries(basic_ops_test ${IN_LIBS} gtest_main)

add_executable(metrics_test metrics_test.cc)
target_link_libraries(metrics_test ${IN_LIBS}) # 不需要 gtest_main

add_executable(metrics_benchmark metrics_benchmark.cc)
target_link_libraries(metrics_benchmark ${IN_LIBS} benchmark_main)

add_executable(write_mostly_benchmark write_mostly_benchmark.cc)
target_link_libraries(write_mostly_benchmark ${IN_LIBS} benchmark_main)
