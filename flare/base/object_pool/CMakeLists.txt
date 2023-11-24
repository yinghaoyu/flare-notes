add_executable(disabled_test disabled_test.cc)
target_link_libraries(disabled_test ${IN_LIBS} gtest_main)

# add_executable(global_test global_test.cc)
# target_link_libraries(global_test ${IN_LIBS} gtest_main)

add_executable(memory_node_shared_test memory_node_shared_test.cc)
target_link_libraries(memory_node_shared_test ${IN_LIBS} gtest_main)

add_executable(memory_node_shared_benchmark memory_node_shared_benchmark.cc)
target_link_libraries(memory_node_shared_benchmark ${IN_LIBS} benchmark_main)

add_executable(object_pool_ref_counted_test ref_counted_test.cc)
target_link_libraries(object_pool_ref_counted_test ${IN_LIBS}) # 不需要 gtest_main

add_executable(object_pool_thread_local_test thread_local_test.cc)
target_link_libraries(object_pool_thread_local_test ${IN_LIBS} gtest_main)
