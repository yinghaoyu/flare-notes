set(fiber_SRCS
  detail/fiber_desc.cc
  detail/fiber_entity.cc
  detail/fiber_worker.cc
  detail/run_queue.cc
  detail/scheduling_group.cc
  detail/scheduling_parameters.cc
  detail/stack_allocator.cc
  detail/timer_worker.cc
  detail/waitable.cc
  detail/x86_64/jump_context.S
  detail/x86_64/make_context.S
  alternatives.cc
  condition_variable.cc
  execution_context.cc
  fiber.cc
  fiber_local.cc
  latch.cc
  logging.cc
  mutex.cc
  runtime.cc
  shared_mutex.cc
  this_fiber.cc
  timer.cc
  work_queue.cc
  )

add_library(flare_fiber ${fiber_SRCS})
target_link_libraries(flare_fiber flare_base)

set(IN_LIBS
  flare_fiber
  flare_init
  flare_testing
  gtest
  gmock
  benchmark
  )

add_executable(alternatives_test alternatives_test.cc)
target_link_libraries(alternatives_test ${IN_LIBS} gtest_main)

add_executable(async_test async_test.cc)
target_link_libraries(async_test ${IN_LIBS} gtest_main)

add_executable(barrier_test barrier_test.cc)
target_link_libraries(barrier_test ${IN_LIBS} gtest_main)

add_executable(condition_variable_test condition_variable_test.cc)
target_link_libraries(condition_variable_test ${IN_LIBS} gtest_main)

add_executable(execution_context_test execution_context_test.cc)
target_link_libraries(execution_context_test ${IN_LIBS} gtest_main)

add_executable(execution_context_benchmark execution_context_benchmark.cc)
target_link_libraries(execution_context_benchmark ${IN_LIBS}) # 不需要 benchmark_main

add_executable(fiber_local_test fiber_local_test.cc)
target_link_libraries(fiber_local_test ${IN_LIBS} gtest_main)

add_executable(fiber_local_benchmark fiber_local_benchmark.cc)
target_link_libraries(fiber_local_benchmark ${IN_LIBS} benchmark_main)

add_executable(fiber_test fiber_test.cc)
target_link_libraries(fiber_test ${IN_LIBS} gtest_main)

add_executable(fiber_future_test future_test.cc)
target_link_libraries(fiber_future_test ${IN_LIBS} gtest_main)

add_executable(fiber_latch_test latch_test.cc)
target_link_libraries(fiber_latch_test ${IN_LIBS} gtest_main)

add_executable(fiber_logging_test logging_test.cc)
target_link_libraries(fiber_logging_test ${IN_LIBS}) # 不需要 gtest_main

add_executable(runtime_test runtime_test.cc)
target_link_libraries(runtime_test ${IN_LIBS} gtest_main)

add_executable(fiber_semaphore_test semaphore_test.cc)
target_link_libraries(fiber_semaphore_test ${IN_LIBS} gtest_main)

add_executable(shared_mutex_test shared_mutex_test.cc)
target_link_libraries(shared_mutex_test ${IN_LIBS} gtest_main)

add_executable(this_fiber_test this_fiber_test.cc)
target_link_libraries(this_fiber_test ${IN_LIBS} gtest_main)

add_executable(timer_test timer_test.cc)
target_link_libraries(timer_test ${IN_LIBS} gtest_main)

add_executable(work_queue_test work_queue_test.cc)
target_link_libraries(work_queue_test ${IN_LIBS} gtest_main)

add_subdirectory(detail)
