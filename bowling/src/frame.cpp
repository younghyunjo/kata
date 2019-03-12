#include "frame.h"

Frame::Frame(bool lastFrame) {
    fsm_ = std::make_unique<FrameStateMachine>(lastFrame);
}

bool Frame::isEndOfFrame() {
    return fsm_->endOfFrame();
//    auto currentState = fsm_->get();
//    if (currentState == fsm_->ready() || currentState == fsm_->once()) {
//        return false;
//    }
//
//    return true;
}

int Frame::getScore() {
    return score_;
}

bool Frame::roll(int pinfalls) {
    if (fsm_->pinfallsAddable(score_, pinfalls)) {
        score_ += pinfalls;
    }

    return isEndOfFrame();
}

int Frame::award(int points) {
    if (fsm_->awardAddable(points)) {
        score_ += points;
    }

    return score_;
}