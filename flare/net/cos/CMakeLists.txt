add_executable(cos_client_test cos_client_test.cc)
target_link_libraries(cos_client_test ${IN_LIBS})

add_executable(cos_status_test cos_status_test.cc)
target_link_libraries(cos_status_test ${IN_LIBS})

add_executable(signature_test signature_test.cc)
target_link_libraries(signature_test ${IN_LIBS})

add_subdirectory(ops/bucket)
add_subdirectory(ops/object)
