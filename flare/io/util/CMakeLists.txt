# add_executable(rate_limiter_integration_test rate_limiter_integration_test.cc)
# target_link_libraries(rate_limiter_integration_test ${IN_LIBS})

add_executable(rate_limiter_test rate_limiter_test.cc)
target_link_libraries(rate_limiter_test ${IN_LIBS} gtest_main)

add_executable(socket_test socket_test.cc)
target_link_libraries(socket_test ${IN_LIBS})
