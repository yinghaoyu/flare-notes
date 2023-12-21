add_executable(delete_multiple_objects_test delete_multiple_objects_test.cc)
target_link_libraries(delete_multiple_objects_test ${IN_LIBS})

add_executable(delete_object_test delete_object_test.cc)
target_link_libraries(delete_object_test ${IN_LIBS})

add_executable(get_object_test get_object_test.cc)
target_link_libraries(get_object_test ${IN_LIBS})

add_executable(put_object_test put_object_test.cc)
target_link_libraries(put_object_test ${IN_LIBS})
