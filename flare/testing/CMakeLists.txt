set(testing_SRCS
  endpoint.cc
  main.cc
  message.pb.cc
  )

add_library(flare_testing ${testing_SRCS})
target_link_libraries(flare_testing flare_init flare_fiber flare_base)
