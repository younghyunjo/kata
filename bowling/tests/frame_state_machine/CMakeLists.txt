set(SRC test_frame_state_machine.cpp)
set(LIBS FrameStateMachine gmock gmock_main)
set(FrameStateMachinePath ${${PROJECT_NAME}_SOURCE_DIR}/frame_state_machine)


add_executable(test_frame_state_machine ${SRC})
target_link_libraries(test_frame_state_machine PRIVATE ${LIBS})
target_link_directories(test_frame_state_machine PRIVATE ${FrameStateMachinePath})
target_include_directories(test_frame_state_machine PRIVATE ${FrameStateMachinePath})
