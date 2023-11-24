add_executable(blake3_test blake3_test.cc)
target_link_libraries(blake3_test ${IN_LIBS} gtest_main)

add_executable(md5_test md5_test.cc)
target_link_libraries(md5_test ${IN_LIBS} gtest_main)

add_executable(sha_test sha_test.cc)
target_link_libraries(sha_test ${IN_LIBS} gtest_main)
