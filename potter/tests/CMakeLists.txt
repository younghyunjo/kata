add_executable(test_kata test_potter.cpp ${${PROJECT_NAME}_SOURCE_DIR}/potter.cpp)
target_include_directories(test_kata PRIVATE ${${PROJECT_NAME}_SOURCE_DIR}/)
target_link_libraries(test_kata gmock gmock_main)
