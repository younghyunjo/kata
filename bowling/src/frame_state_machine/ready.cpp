#include "ready.h"

Ready::Ready(FrameStateMachine *fsm) : fsm_{fsm} {}

static bool isStrike(int pinfalls) {
    return pinfalls == 10;
}

bool Ready::awardAddable(int awardPoints) {
    return false;
}

bool Ready::pinfallsAddable(int score, int pinfalls) {
    auto transitionState = fsm_->once();

    if (isStrike(pinfalls)) {
        transitionState = fsm_->strike();
    }

    fsm_->set(transitionState);

    return true;
}

bool Ready::endOfFrame() {
    return false;
}