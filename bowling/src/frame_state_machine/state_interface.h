//
// Created by younghyun on 19. 1. 28.
//

#ifndef STATE_INTERFACE_H
#define STATE_INTERFACE_H


class State {
public:
    virtual bool pinfallsAddable(int score, int pinfalls) = 0;
    virtual bool awardAddable(int awardPoints) = 0;
    virtual bool endOfFrame() = 0;

//    virtual ~State() = default;
};

#endif //STATE_INTERFACE_H
