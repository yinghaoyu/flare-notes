
add_executable(logging_test logging_test.cc)
target_link_libraries(logging_test flare_base gtest gtest_main glog::glog fmt::fmt pthread)
