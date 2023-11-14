add_executable(latch_test latch_test.cc)
target_link_libraries(latch_test flare_base gtest gtest_main glog::glog fmt::fmt pthread)
