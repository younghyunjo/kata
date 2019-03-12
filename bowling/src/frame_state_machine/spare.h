
#include "state_interface.h"
#include "frame_state_machine.h"

class Spare : public State {
public:
    Spare(FrameStateMachine* fsm);
    bool pinfallsAddable(int score, int pinfalls) override;
    bool awardAddable(int awardPoints) override;
    bool endOfFrame() override;

private:
    FrameStateMachine* fsm_;
    int lastFrameRemainedPinFalls = 1;
    int remainedAward = 1;
};