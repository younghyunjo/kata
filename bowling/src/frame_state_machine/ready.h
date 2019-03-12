#ifndef STATE_READY
#define STATE_READY

#include "state_interface.h"
#include "frame_state_machine.h"

class Ready : public State {
public:
    Ready(FrameStateMachine* fsm);
    bool pinfallsAddable(int score, int pinfalls) override;
    bool awardAddable(int awardPoints) override;
    bool endOfFrame() override;

private:
    FrameStateMachine* fsm_;
};

#endif //STATE_READY
