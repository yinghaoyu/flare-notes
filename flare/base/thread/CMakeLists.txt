add_executable(attribute_test attribute_test.cc)
target_link_libraries(attribute_test ${IN_LIBS} gtest_main)

add_executable(latch_test latch_test.cc)
target_link_libraries(latch_test ${IN_LIBS} gtest_main)

add_executable(semaphore_test semaphore_test.cc)
target_link_libraries(semaphore_test ${IN_LIBS} gtest_main)

add_executable(spinlock_test spinlock_test.cc)
target_link_libraries(spinlock_test ${IN_LIBS} gtest_main)

add_executable(thread_cached_test thread_cached_test.cc)
target_link_libraries(thread_cached_test ${IN_LIBS} gtest_main)

add_executable(thread_cached_benchmark thread_cached_benchmark.cc)
target_link_libraries(thread_cached_benchmark ${IN_LIBS} benchmark_main)

add_executable(thread_local_test thread_local_test.cc)
target_link_libraries(thread_local_test ${IN_LIBS} gtest_main)

add_executable(thread_local_benchmark thread_local_benchmark.cc)
target_link_libraries(thread_local_benchmark ${IN_LIBS} benchmark_main)

add_executable(out_of_duty_callback_test out_of_duty_callback_test.cc)
target_link_libraries(out_of_duty_callback_test ${IN_LIBS} gtest_main)

add_executable(out_of_duty_callback_benchmark out_of_duty_callback_benchmark.cc)
target_link_libraries(out_of_duty_callback_benchmark ${IN_LIBS} benchmark_main)

add_subdirectory(thread_local)
