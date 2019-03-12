#include "spare.h"

Spare::Spare(FrameStateMachine *fsm) : fsm_{fsm} {}

bool Spare::pinfallsAddable(int score, int pinfalls) {
    if (fsm_->isLastFrame() && lastFrameRemainedPinFalls) {
        lastFrameRemainedPinFalls--;
        return true;
    }

    return false;
}

bool Spare::awardAddable(int awardPoints) {
    if (remainedAward) {
        remainedAward--;
        return true;
    }

    return false;
}

bool Spare::endOfFrame() {
    return !(fsm_->isLastFrame() && lastFrameRemainedPinFalls);
}
