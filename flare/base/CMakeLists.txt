set(base_SRCS
  buffer/builtin_buffer_block.cc
  buffer/compression_output_stream.cc
  buffer/packing.cc
  buffer/packing.pb.cc
  buffer/view.cc
  buffer/zero_copy_stream.cc
  compression/compression.cc
  compression/gzip.cc
  compression/lz4.cc
  compression/snappy.cc
  compression/util.cc
  compression/zstd.cc
  crypto/blake3.cc
  crypto/md5.cc
  crypto/sha.cc
  encoding/base64.cc
  encoding/hex.cc
  encoding/percent.cc
  experimental/bloom_filter.cc
  experimental/byte_set.cc
  experimental/uuid.cc
  hazptr/entry_cache.cc
  hazptr/hazptr_domain.cc
  hazptr/hazptr_object.cc
  internal/background_task_host.cc
  internal/logging.cc
  internal/cpu.cc
  internal/dpc.cc
  internal/memory_barrier.cc
  internal/thread_pool.cc
  internal/time_keeper.cc
  internal/index_alloc.cc
  monitoring/common.cc
  monitoring/dispatcher.cc
  monitoring/event.cc
  monitoring/init.cc
  monitoring/monitoring_system.cc
  net/endpoint.cc
  net/uri.cc
  object_pool/disabled.cc
  object_pool/global.cc
  object_pool/memory_node_shared.cc
  object_pool/thread_local.cc
  thread/latch.cc
  thread/attribute.cc
  thread/spinlock.cc
  thread/out_of_duty_callback.cc
  write_mostly/metrics.cc
  buffer.cc
  demangle.cc
  compression.cc
  chrono.cc
  logging.cc
  status.cc
  string.cc
  tsc.cc
  object_pool.cc
  exposed_var.cc
  monitoring.cc
  erased_ptr.cc
  )

set(IN_LIBS
  flare_base
  flare_init
  flare_testing
  gtest
  gmock
  benchmark
  )

add_library(flare_base ${base_SRCS})
target_link_libraries(flare_base
                      glog::glog
                      fmt::fmt
                      jsoncpp_lib
                      xxhash
                      yaml-cpp
                      z #zlib
                      ssl
                      crypto
                      blake3
                      protobuf
                      pthread
                      dl)

set(BLOCK_SIZES "4K" "64K" "1M")
foreach(block_size ${BLOCK_SIZES})
  set(TEST_NAME "buffer_test_${block_size}")
  add_executable(${TEST_NAME} buffer_test.cc)
  target_compile_definitions(${TEST_NAME} PRIVATE BUFFER_BLOCK_SIZE="${block_size}")
  target_link_libraries(${TEST_NAME} ${IN_LIBS}) # 不需要 gtest_main
 endforeach()

add_executable(compression_test compression_test.cc)
target_link_libraries(compression_test ${IN_LIBS} gtest_main)

add_executable(casting_test casting_test.cc)
target_link_libraries(casting_test ${IN_LIBS} gtest_main)

add_executable(casting_benchmark casting_benchmark.cc)
target_link_libraries(casting_benchmark ${IN_LIBS} benchmark_main)

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

add_executable(hazptr_test hazptr_test.cc)
target_link_libraries(hazptr_test ${IN_LIBS}) # 不需要 gtest_main

add_executable(hazptr_benchmark hazptr_benchmark.cc)
target_link_libraries(hazptr_benchmark ${IN_LIBS} benchmark_main)

add_executable(exposed_var_test exposed_var_test.cc)
target_link_libraries(exposed_var_test ${IN_LIBS}) # 不需要 gtest_main

add_executable(dependency_registry_test dependency_registry_test.cc)
target_link_libraries(dependency_registry_test ${IN_LIBS} gtest_main)

# add_executable(monitoring_test monitoring_test.cc)
# target_link_libraries(dependency_registry_test ${IN_LIBS}) # 不需要 gtest_main

add_executable(monitoring_benchmark monitoring_benchmark.cc)
target_link_libraries(monitoring_benchmark ${IN_LIBS} benchmark_main)

add_executable(monitoring_with_global_tags_test monitoring_with_global_tags_test.cc)
target_link_libraries(monitoring_with_global_tags_test ${IN_LIBS}) # 不需要 gtest_main

add_subdirectory(buffer)
add_subdirectory(compression)
add_subdirectory(crypto)
add_subdirectory(encoding)
add_subdirectory(experimental)
add_subdirectory(internal)
add_subdirectory(monitoring)
add_subdirectory(net)
add_subdirectory(object_pool)
add_subdirectory(thread)
add_subdirectory(write_mostly)
