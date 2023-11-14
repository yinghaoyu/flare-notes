add_executable(internal_logging_test logging_test.cc)
target_link_libraries(internal_logging_test flare_base gtest gtest_main glog::glog fmt::fmt pthread)
