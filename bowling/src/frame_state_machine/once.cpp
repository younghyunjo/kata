#include "once.h"

Once::Once(FrameStateMachine *fsm) : fsm_{fsm} {}

static bool isSpare(int score, int pinfalls) {
    return (score+pinfalls) == 10;
}

bool Once::awardAddable(int awardPoints) {
    return false;
}

bool Once::pinfallsAddable(int score, int pinfalls) {
    auto transitionState = fsm_->open();

    if (isSpare(score, pinfalls)) {
        transitionState = fsm_->spare();
    }
    fsm_->set(transitionState);

    return true;
}

bool Once::endOfFrame() {
    return false;
}