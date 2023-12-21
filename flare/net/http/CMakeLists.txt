add_executable(binlog_dry_runner_integration_test binlog_dry_runner_integration_test.cc)
target_link_libraries(binlog_dry_runner_integration_test ${IN_LIBS})

add_executable(binlog_dumper_integration_test binlog_dumper_integration_test.cc)
target_link_libraries(binlog_dumper_integration_test ${IN_LIBS})

add_executable(http_client_test http_client_test.cc)
target_link_libraries(http_client_test ${IN_LIBS})

add_executable(http_headers_test http_headers_test.cc)
target_link_libraries(http_headers_test ${IN_LIBS})

add_executable(http_message_test http_message_test.cc)
target_link_libraries(http_message_test ${IN_LIBS})

add_executable(http_request_test http_request_test.cc)
target_link_libraries(http_request_test ${IN_LIBS})

add_executable(http_response_test http_response_test.cc)
target_link_libraries(http_response_test ${IN_LIBS})

add_executable(query_string_test query_string_test.cc)
target_link_libraries(query_string_test ${IN_LIBS})

add_executable(utility_test utility_test.cc)
target_link_libraries(utility_test ${IN_LIBS})
