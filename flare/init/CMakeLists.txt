set(init_SRCS
  on_init.cc
  # openssl_initializer.cc
  override_flag.cc
  override_rlimit.cc
  )

add_library(flare_init ${init_SRCS})

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

# add_library(override_flag override_flag.cc)
# add_library(on_init on_init.cc)
# add_library(openssl_initializer openssl_initializer.cc)
# add_library(override_rlimit override_rlimit.cc)

# add_executable(on_init_test on_init_test.cc)
# target_link_libraries(on_init_test ${IN_LIBS})

# add_executable(override_flag_test override_flag_test.cc)
# target_link_libraries(override_flag_test ${IN_LIBS})

# add_executable(override_rlimit_test override_rlimit_test.cc)
# target_link_libraries(override_rlimit_test ${IN_LIBS})
