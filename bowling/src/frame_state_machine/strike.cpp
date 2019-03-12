#include "strike.h"

Strike::Strike(FrameStateMachine *fsm) : fsm_{fsm} {}

bool Strike::pinfallsAddable(int score, int pinfalls) {
    if (fsm_->isLastFrame() && lastFrameRemainedPinfalls) {
        lastFrameRemainedPinfalls--;
        return true;
    }

    return false;
}

bool Strike::awardAddable(int awardPoints) {
    if (remainedAward) {
        remainedAward--;
        return true;
    }

    return false;
}

bool Strike::endOfFrame() {
    return !(fsm_->isLastFrame() && lastFrameRemainedPinfalls);
}
