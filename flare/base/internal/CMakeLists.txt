add_executable(internal_logging_test logging_test.cc)
target_link_libraries(internal_logging_test flare_base gtest gtest_main glog::glog fmt::fmt pthread)

add_executable(early_init_test early_init_test.cc)
target_link_libraries(early_init_test flare_base gtest gtest_main pthread)

add_executable(memory_barrier_benchmark memory_barrier_benchmark.cc)
target_link_libraries(memory_barrier_benchmark flare_base benchmark benchmark_main pthread)

add_executable(biased_mutex_test biased_mutex_test.cc)
target_link_libraries(biased_mutex_test flare_base gtest gtest_main glog::glog fmt::fmt pthread)

add_executable(biased_mutex_benchmark biased_mutex_benchmark.cc)
target_link_libraries(biased_mutex_benchmark flare_base benchmark benchmark_main glog::glog fmt::fmt pthread)

add_executable(hash_map_test hash_map_test.cc)
target_link_libraries(hash_map_test flare_base gtest gtest_main glog::glog fmt::fmt pthread)

add_executable(hash_map_benchmark hash_map_benchmark.cc)
target_link_libraries(hash_map_benchmark flare_base benchmark benchmark_main glog::glog fmt::fmt pthread)
