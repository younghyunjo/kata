//
// Created by younghyun on 19. 2. 18.
//

#include "game.h"

void Game::roll(int pinfalls) {
    auto endOfFrame =frames[currentFrameIndex_]->roll(pinfalls);
    for (auto i = currentFrameIndex_-1; i >=0 && i >= currentFrameIndex_-2; i--)
        frames[i]->award(pinfalls);

    if (endOfFrame)
        currentFrameIndex_++;
}

int Game::score() {
    auto score = 0;
    for (int i=0; i<numberOfFrames_; i++) {
        score += frames[i]->getScore();
    }

    return score;
}

Game::Game(int nuberOfFrames) {
    numberOfFrames_ = nuberOfFrames;

    for (auto i=0; i<nuberOfFrames-1; i++)
        frames.push_back(std::make_unique<Frame>());
    frames.push_back(std::make_unique<Frame>(true));
}