add_executable(http_engine_test http_engine_test.cc)
target_link_libraries(http_engine_test ${IN_LIBS})

add_executable(http_task_test http_task_test.cc)
target_link_libraries(http_task_test ${IN_LIBS})
