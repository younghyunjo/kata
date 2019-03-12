//
// Created by younghyun on 19. 2. 18.
//

#ifndef KATA_GAME_H
#define KATA_GAME_H

#include <vector>

#include "frame.h"

class Game {
public:
    Game(int numberOfFrames = 10);

    void roll(int pinfalls);
    int score();

private:
    int numberOfFrames_ = 0;
    int currentFrameIndex_ = 0;
    std::vector<std::unique_ptr<Frame>> frames;
};


#endif //KATA_GAME_H
