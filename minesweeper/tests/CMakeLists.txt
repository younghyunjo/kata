link_libraries(gmock gmock_main)

add_executable(test_input test_input.cpp ${PROJECT_SOURCE_DIR}/src/Input.cpp)
add_executable(test_sweeper test_sweeper.cpp ${PROJECT_SOURCE_DIR}/src/Sweeper.cpp)
add_executable(test_output test_output.cpp ${PROJECT_SOURCE_DIR}/src/Output.cpp)

