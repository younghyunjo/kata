//
// Created by younghyun on 19. 1. 30.
//

#ifndef STATE_FRAME_STATE_MACHINE_H
#define STATE_FRAME_STATE_MACHINE_H

#include <memory>
#include "state_interface.h"

class FrameStateMachine {
public:
    FrameStateMachine(bool lastFrame =  false);
    bool pinfallsAddable(int score, int pinfalls);
    bool awardAddable(int awardPoints);
    bool endOfFrame(void);
    bool isLastFrame(void);

    std::shared_ptr<State> get();
    void set(std::shared_ptr<State>);

    std::shared_ptr<State> ready();
    std::shared_ptr<State> once();
    std::shared_ptr<State> open();
    std::shared_ptr<State> spare();
    std::shared_ptr<State> strike();

private:
    std::shared_ptr<State> current_;
    std::shared_ptr<State> ready_;
    std::shared_ptr<State> once_;
    std::shared_ptr<State> open_;
    std::shared_ptr<State> spare_;
    std::shared_ptr<State> strike_;

    bool lastFrame_;
};

#endif //STATE_FRAME_STATE_MACHINE_H
