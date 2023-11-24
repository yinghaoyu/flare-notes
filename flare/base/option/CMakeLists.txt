add_executable(json_parser_test json_parser_test.cc)
target_link_libraries(json_parser_test ${IN_LIBS} gtest_main)

add_executable(key_test key_test.cc)
target_link_libraries(key_test ${IN_LIBS} gtest_main)

add_executable(option_service_test option_service_test.cc)
target_link_libraries(option_service_test ${IN_LIBS} gtest_main)

add_executable(proto_parser_test proto_parser_test.cc)
target_link_libraries(proto_parser_test ${IN_LIBS} gtest_main)
