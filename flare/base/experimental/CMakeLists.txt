add_executable(bloom_filter_test bloom_filter_test.cc)
target_link_libraries(bloom_filter_test ${IN_LIBS} gtest_main)

add_executable(byte_set_test byte_set_test.cc)
target_link_libraries(byte_set_test ${IN_LIBS} gtest_main)

add_executable(flyweight_test flyweight_test.cc)
target_link_libraries(flyweight_test ${IN_LIBS} gtest_main)

add_executable(lazy_eval_test lazy_eval_test.cc)
target_link_libraries(lazy_eval_test ${IN_LIBS} gtest_main)

add_executable(seqlocked_test seqlocked_test.cc)
target_link_libraries(seqlocked_test ${IN_LIBS} gtest_main)

add_executable(seqlocked_benchmark seqlocked_benchmark.cc)
target_link_libraries(seqlocked_benchmark ${IN_LIBS} benchmark_main)

add_executable(uuid_test uuid_test.cc)
target_link_libraries(uuid_test ${IN_LIBS} gtest_main)
