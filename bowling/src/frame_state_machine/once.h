#ifndef STATE_ONCE_H
#define STATE_ONCE_H

#include "state_interface.h"
#include "frame_state_machine.h"

class Once : public State {
public:
    Once(FrameStateMachine* fsm);
    bool pinfallsAddable(int score, int pinfalls) override;
    bool awardAddable(int awardPoints) override;
    bool endOfFrame() override;

private:
    FrameStateMachine* fsm_;
};
#endif //#ifndef STATE_ONCE_H