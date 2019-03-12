//
// Created by younghyun on 19. 1. 30.
//

#ifndef STATE_OPEN_H
#define STATE_OPEN_H

#include "state_interface.h"
#include "frame_state_machine.h"

class Open : public State {
public:
    Open(FrameStateMachine* fsm);
    bool pinfallsAddable(int score, int pinfalls) override;
    bool awardAddable(int awardPoints) override;
    bool endOfFrame() override;

private:
    FrameStateMachine* fsm_;
};


#endif //STATE_OPEN_H
