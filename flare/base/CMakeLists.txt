set(base_SRCS
  demangle.cc
  chrono.cc
  experimental/bloom_filter.cc
  experimental/byte_set.cc
  experimental/uuid.cc
  internal/background_task_host.cc
  internal/logging.cc
  internal/cpu.cc
  internal/memory_barrier.cc
  internal/thread_pool.cc
  internal/time_keeper.cc
  internal/index_alloc.cc
  thread/latch.cc
  thread/attribute.cc
  logging.cc
  status.cc
  string.cc
  tsc.cc
  )

set(IN_LIBS
  flare_base
  flare_init
  flare_testing
  gtest
  gmock
  benchmark
  glog::glog
  fmt::fmt
  xxhash
  pthread
  dl
  )

add_library(flare_base ${base_SRCS})

add_executable(deferred_test deferred_test.cc)
target_link_libraries(deferred_test ${IN_LIBS} gtest_main)

add_executable(function_test function_test.cc)
target_link_libraries(function_test ${IN_LIBS} gtest_main)

add_executable(function_benchmark function_benchmark.cc)
target_link_libraries(function_benchmark ${IN_LIBS} benchmark_main)

add_executable(erased_ptr_test erased_ptr_test.cc)
target_link_libraries(erased_ptr_test ${IN_LIBS} gtest_main)

add_executable(chrono_test chrono_test.cc)
target_link_libraries(chrono_test ${IN_LIBS} gtest_main)

add_executable(function_view_test function_view_test.cc)
target_link_libraries(function_view_test ${IN_LIBS} gtest_main)

add_executable(delayed_init_test delayed_init_test.cc)
target_link_libraries(delayed_init_test ${IN_LIBS} gtest_main)

add_executable(down_cast_test down_cast_test.cc)
target_link_libraries(down_cast_test ${IN_LIBS} gtest_main)

add_executable(endian_test endian_test.cc)
target_link_libraries(endian_test ${IN_LIBS} gtest_main)

add_executable(enum_test enum_test.cc)
target_link_libraries(enum_test ${IN_LIBS} gtest_main)

add_executable(expected_test expected_test.cc)
target_link_libraries(expected_test ${IN_LIBS} gtest_main)

add_executable(handle_test handle_test.cc)
target_link_libraries(handle_test ${IN_LIBS} gtest_main)

add_executable(logging_test logging_test.cc)
target_link_libraries(logging_test ${IN_LIBS} gtest_main)

add_executable(logging_benchmark logging_benchmark.cc)
target_link_libraries(logging_benchmark ${IN_LIBS} benchmark_main)

add_executable(id_alloc_test id_alloc_test.cc)
target_link_libraries(id_alloc_test ${IN_LIBS} gtest_main)

add_executable(id_alloc_benchmark id_alloc_benchmark.cc)
target_link_libraries(id_alloc_benchmark ${IN_LIBS} benchmark_main)

add_executable(maybe_owning_test maybe_owning_test.cc)
target_link_libraries(maybe_owning_test ${IN_LIBS} gtest_main)

add_executable(never_destroyed_test never_destroyed_test.cc)
target_link_libraries(never_destroyed_test ${IN_LIBS} gtest_main)

add_executable(overloaded_test overloaded_test.cc)
target_link_libraries(overloaded_test ${IN_LIBS} gtest_main)

add_executable(ref_ptr_test ref_ptr_test.cc)
target_link_libraries(ref_ptr_test ${IN_LIBS} gtest_main)

add_executable(status_test status_test.cc)
target_link_libraries(status_test ${IN_LIBS} gtest_main)

add_executable(string_test string_test.cc)
target_link_libraries(string_test ${IN_LIBS} gtest_main)

add_executable(tsc_test tsc_test.cc)
target_link_libraries(tsc_test ${IN_LIBS} gtest_main)

add_executable(tsc_benchmark tsc_benchmark.cc)
target_link_libraries(tsc_benchmark ${IN_LIBS} benchmark_main)

add_executable(type_index_test type_index_test.cc)
target_link_libraries(type_index_test ${IN_LIBS} gtest_main)

add_subdirectory(experimental)
add_subdirectory(internal)
add_subdirectory(thread)
