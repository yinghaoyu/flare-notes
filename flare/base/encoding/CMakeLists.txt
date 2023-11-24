add_executable(base64_test base64_test.cc)
target_link_libraries(base64_test ${IN_LIBS} gtest_main)

add_executable(hex_test hex_test.cc)
target_link_libraries(hex_test ${IN_LIBS} gtest_main)

add_executable(percent_test percent_test.cc)
target_link_libraries(percent_test ${IN_LIBS} gtest_main)
