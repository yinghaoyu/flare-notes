add_executable(background_task_host_test background_task_host_test.cc)
target_link_libraries(background_task_host_test ${IN_LIBS} gtest_main)

add_executable(internal_logging_test logging_test.cc)
target_link_libraries(internal_logging_test ${IN_LIBS} gtest_main)

add_executable(early_init_test early_init_test.cc)
target_link_libraries(early_init_test ${IN_LIBS} gtest_main)

add_executable(memory_barrier_benchmark memory_barrier_benchmark.cc)
target_link_libraries(memory_barrier_benchmark ${IN_LIBS} benchmark_main)

add_executable(biased_mutex_test biased_mutex_test.cc)
target_link_libraries(biased_mutex_test ${IN_LIBS} gtest_main)

add_executable(biased_mutex_benchmark biased_mutex_benchmark.cc)
target_link_libraries(biased_mutex_benchmark ${IN_LIBS} benchmark_main)

add_executable(hash_map_test hash_map_test.cc)
target_link_libraries(hash_map_test ${IN_LIBS} gtest_main)

add_executable(hash_map_benchmark hash_map_benchmark.cc)
target_link_libraries(hash_map_benchmark ${IN_LIBS} benchmark_main)

add_executable(case_insensitive_hash_map_test case_insensitive_hash_map_test.cc)
target_link_libraries(case_insensitive_hash_map_test ${IN_LIBS} gtest_main)

add_executable(case_insensitive_hash_map_benchmark case_insensitive_hash_map_benchmark.cc)
target_link_libraries(case_insensitive_hash_map_benchmark ${IN_LIBS} benchmark_main)

add_executable(circular_buffer_test circular_buffer_test.cc)
target_link_libraries(circular_buffer_test ${IN_LIBS} gtest_main)

add_executable(circular_buffer_benchmark circular_buffer_benchmark.cc)
target_link_libraries(circular_buffer_benchmark ${IN_LIBS} benchmark_main)

add_executable(copyable_atomic_test copyable_atomic_test.cc)
target_link_libraries(copyable_atomic_test ${IN_LIBS} gtest_main)

add_executable(cpu_test cpu_test.cc)
target_link_libraries(cpu_test ${IN_LIBS} gtest_main)

add_executable(doubly_linked_list_test doubly_linked_list_test.cc)
target_link_libraries(doubly_linked_list_test ${IN_LIBS} gtest_main)

add_executable(index_alloc_test index_alloc_test.cc)
target_link_libraries(index_alloc_test ${IN_LIBS} gtest_main)

add_executable(lazy_init_test lazy_init_test.cc)
target_link_libraries(lazy_init_test ${IN_LIBS} gtest_main)

add_executable(singly_linked_list_test singly_linked_list_test.cc)
target_link_libraries(singly_linked_list_test ${IN_LIBS} gtest_main)

add_executable(thread_pool_test thread_pool_test.cc)
target_link_libraries(thread_pool_test ${IN_LIBS} gtest_main)

# add_executable(time_keeper_test time_keeper_test.cc)
# target_link_libraries(time_keeper_test ${LIBS} gtest_main)

# add_executable(time_view_test time_view_test.cc)
# target_link_libraries(time_view_test ${LIBS} gtest_main)
