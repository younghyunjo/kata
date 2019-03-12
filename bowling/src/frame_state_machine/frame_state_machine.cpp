//
// Created by younghyun on 19. 1. 30.
//

#include "frame_state_machine.h"

#include "ready.h"
#include "once.h"
#include "open.h"
#include "strike.h"
#include "spare.h"

FrameStateMachine::FrameStateMachine(bool lastFrame) {
    ready_ = std::make_shared<Ready>(this);
    strike_ = std::make_shared<Strike>(this);
    once_ = std::make_shared<Once>(this);
    open_= std::make_shared<Open>(this);
    spare_= std::make_shared<Spare>(this);

    current_ = ready_;
    lastFrame_ = lastFrame;
}

bool FrameStateMachine::pinfallsAddable(int score, int pinfalls) {
    return current_->pinfallsAddable(score, pinfalls);
}

bool FrameStateMachine::awardAddable(int awardPoints) {
    return current_->awardAddable(awardPoints);
}

bool FrameStateMachine::endOfFrame() {
    return current_->endOfFrame();
}

bool FrameStateMachine::isLastFrame() {
    return lastFrame_;
}

void FrameStateMachine::set(std::shared_ptr<State> state) {
    current_ = state;
}

std::shared_ptr<State> FrameStateMachine::get() {
    return current_;
}

std::shared_ptr<State> FrameStateMachine::ready() {
    return ready_;
}

std::shared_ptr<State> FrameStateMachine::strike() {
    return strike_;
}

std::shared_ptr<State> FrameStateMachine::once() {
    return once_;
}

std::shared_ptr<State> FrameStateMachine::open() {
    return open_;
}

std::shared_ptr<State> FrameStateMachine::spare() {
    return spare_;
}
