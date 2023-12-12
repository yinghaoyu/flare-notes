add_executable(read_at_most_test read_at_most_test.cc)
target_link_libraries(read_at_most_test ${IN_LIBS})

add_executable(watchdog_test watchdog_test.cc)
target_link_libraries(watchdog_test ${IN_LIBS})

add_executable(writing_buffer_list_test writing_buffer_list_test.cc)
target_link_libraries(writing_buffer_list_test ${IN_LIBS})

add_executable(writing_datagram_list_test writing_datagram_list_test.cc)
target_link_libraries(writing_datagram_list_test ${IN_LIBS})
