set(io_SRCS
  detail/eintr_safe.cc
  detail/event_loop_notifier.cc
  detail/read_at_most.cc
  detail/timed_call.cc
  detail/watchdog.cc
  detail/writing_buffer_list.cc
  detail/writing_datagram_list.cc
  native/acceptor.cc
  native/datagram_transceiver.cc
  native/stream_connection.cc
  util/http_proxy_stream_io.cc
  util/openssl.cc
  util/rate_limiter.cc
  util/socket.cc
  util/ssl_stream_io.cc
  descriptor.cc
  event_loop.cc
  )

add_library(flare_io ${io_SRCS})
target_link_libraries(flare_io flare_base flare_fiber flare_testing flare_init)

set(IN_LIBS
  flare_init
  flare_io
  gtest
  gmock
  benchmark
  )

add_executable(descriptor_test descriptor_test.cc)
target_link_libraries(descriptor_test ${IN_LIBS})

add_executable(event_loop_test event_loop_test.cc)
target_link_libraries(event_loop_test ${IN_LIBS})

add_subdirectory(detail)
add_subdirectory(native)
add_subdirectory(util)
