set(testing_SRCS
  main.cc
  )

add_library(flare_testing ${testing_SRCS})
target_link_libraries(flare_testing flare_init flare_fiber flare_base)
