add_executable(reader_test reader_test.cc)
target_link_libraries(reader_test ${IN_LIBS})

add_executable(redis_command_test redis_command_test.cc)
target_link_libraries(redis_command_test ${IN_LIBS})

add_executable(redis_protocol_test redis_protocol_test.cc)
target_link_libraries(redis_protocol_test ${IN_LIBS})

add_executable(redis_test redis_test.cc)
target_link_libraries(redis_test ${IN_LIBS})
