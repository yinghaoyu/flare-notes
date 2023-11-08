set(base_SRCS
  demangle.cc
  chrono.cc
  )

add_library(flare_base ${base_SRCS})

add_executable(deferred_test deferred_test.cc)
target_link_libraries(deferred_test flare_base gtest gtest_main pthread)

add_executable(function_test function_test.cc)
target_link_libraries(function_test flare_base gtest gtest_main pthread)

add_executable(erased_ptr_test erased_ptr_test.cc)
target_link_libraries(erased_ptr_test flare_base gtest gtest_main pthread)

add_executable(chrono_test chrono_test.cc)
target_link_libraries(chrono_test flare_base gtest gtest_main pthread)
