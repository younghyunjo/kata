#ifndef FRAME_H
#define FRAME_H

#include "frame_state_machine/frame_state_machine.h"

class Frame {
public:
    Frame(bool lastFrame = false);
    int getScore();
    bool roll(int pinfalls);
    int award(int points);

private:
    int score_ = 0;
    std::unique_ptr<FrameStateMachine> fsm_;
    bool isEndOfFrame();
};


#endif //#ifdef FRAME_H