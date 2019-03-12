#ifndef STATE_STRIKE_H
#define STATE_STRIKE_H

#include "state_interface.h"
#include "frame_state_machine.h"

class Strike : public State {
public:
    Strike(FrameStateMachine* fsm);
    bool pinfallsAddable(int score, int pinfalls) override;
    bool awardAddable(int awardPoints) override;
    bool endOfFrame() override;

private:
    FrameStateMachine* fsm_;
    int lastFrameRemainedPinfalls= 2;
    int remainedAward = 2;


};


#endif //#ifndef STATE_STRIKE_H