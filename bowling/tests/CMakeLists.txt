set(SRC_PATH ${${PROJECT_NAME}_SOURCE_DIR})


# Test Frame
set(src_frame test_frame.cpp ${SRC_PATH}/frame.cpp)
set(lib_frame FrameStateMachine gmock gmock_main)

add_executable(test_frame ${src_frame})
target_link_libraries(test_frame PRIVATE ${lib_frame})
target_link_directories(test_frame PRIVATE ${SRC_PATH} ${SRC_PATH}/frame_state_machine)
target_include_directories(test_frame PRIVATE ${SRC_PATH} ${SRC_PATH}/frame_state_machine)


#Test Game
set(src_game test_game.cpp ${SRC_PATH}/game.cpp ${SRC_PATH}/frame.cpp)
set(lib_game gmock gmock_main)

add_executable(test_game ${src_game} ${SRC_PATH}/frame.cpp)
target_link_libraries(test_game PRIVATE ${lib_game} ${lib_frame})
target_link_directories(test_game PRIVATE ${SRC_PATH} ${SRC_PATH}/frame_state_machine)
target_include_directories(test_game PRIVATE ${SRC_PATH} ${SRC_PATH}/frame_state_machine)

# Test FrameStateMachine
add_subdirectory(frame_state_machine)
