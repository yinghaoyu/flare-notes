set(init_SRCS
  ../init.cc
  on_init.cc
  # openssl_initializer.cc
  override_flag.cc
  override_rlimit.cc
  )

add_library(flare_init ${init_SRCS})
target_link_libraries(flare_init flare_testing flare_fiber flare_io)

set(IN_LIBS
  flare_init
  gtest
  gmock
  benchmark
  )

add_executable(on_init_test on_init_test.cc)
target_link_libraries(on_init_test ${IN_LIBS})

add_executable(override_flag_test override_flag_test.cc)
target_link_libraries(override_flag_test ${IN_LIBS})

add_executable(override_rlimit_test override_rlimit_test.cc)
target_link_libraries(override_rlimit_test ${IN_LIBS})
