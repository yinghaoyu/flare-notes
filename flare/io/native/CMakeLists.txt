add_executable(acceptor_test acceptor_test.cc)
target_link_libraries(acceptor_test ${IN_LIBS})

add_executable(datagram_transceiver_test datagram_transceiver_test.cc)
target_link_libraries(datagram_transceiver_test ${IN_LIBS})

add_executable(stream_connection_test stream_connection_test.cc)
target_link_libraries(stream_connection_test ${IN_LIBS})
