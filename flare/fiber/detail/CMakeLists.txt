add_executable(assembly_benchmark assembly_benchmark.cc)
target_link_libraries(assembly_benchmark ${IN_LIBS} benchmark_main)

add_executable(context_benchmark context_benchmark.cc)
target_link_libraries(context_benchmark ${IN_LIBS} benchmark_main)

add_executable(fiber_desc_test fiber_desc_test.cc)
target_link_libraries(fiber_desc_test ${IN_LIBS} gtest_main)

add_executable(fiber_entity_test fiber_entity_test.cc)
target_link_libraries(fiber_entity_test ${IN_LIBS} gtest_main)

add_executable(fiber_worker_test fiber_worker_test.cc)
target_link_libraries(fiber_worker_test ${IN_LIBS} gtest_main)

add_executable(run_queue_test run_queue_test.cc)
target_link_libraries(run_queue_test ${IN_LIBS} gtest_main)

add_executable(scheduling_group_test scheduling_group_test.cc)
target_link_libraries(scheduling_group_test ${IN_LIBS} gtest_main)

add_executable(scheduling_parameters_test scheduling_parameters_test.cc)
target_link_libraries(scheduling_parameters_test ${IN_LIBS} gtest_main)

add_executable(stack_allocator_test stack_allocator_test.cc)
target_link_libraries(stack_allocator_test ${IN_LIBS} gtest_main)

add_executable(timer_worker_test timer_worker_test.cc)
target_link_libraries(timer_worker_test ${IN_LIBS} gtest_main)

add_executable(waitable_test waitable_test.cc)
target_link_libraries(waitable_test ${IN_LIBS} gtest_main)
