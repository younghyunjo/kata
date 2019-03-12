//
// Created by younghyun on 19. 1. 30.
//

#include "open.h"

Open::Open(FrameStateMachine *fsm) : fsm_{fsm} {}
bool Open::pinfallsAddable(int score, int pinfalls) {
    return false;
}

bool Open::awardAddable(int awardPoints) {
    return false;
}

bool Open::endOfFrame() {
    return true;
}