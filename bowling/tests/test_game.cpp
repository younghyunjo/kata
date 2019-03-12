//
// Created by younghyun on 19. 2. 18.
//


#include "game.h"

#include <gmock/gmock.h>

using namespace testing;

TEST(Game, canCreateWithNumberOfFrames) {
    //given
    int numberOfFrames = 3;

    //when
    Game g{numberOfFrames};

    //then
    //no compile error
}


int SetFirstFrameSpare(Game& g) {
    int firstPinfalls = 1;
    int secondPinfalls = 9;

    g.roll(firstPinfalls);
    g.roll(secondPinfalls);

    return firstPinfalls + secondPinfalls;
}

int SetFirstFrameStrike(Game& g) {
    g.roll(10);
    return 10;
}

class Game_F : public ::Test {
protected:
    void SetUp () override {

    }

    void TearDown() override {

    }

    int SetFirstFrameScore() {
        int firstPinfalls = 1;
        int secondPinfalls = 2;

        g.roll(firstPinfalls);
        g.roll(secondPinfalls);

        return firstPinfalls + secondPinfalls;
    }

    Game g;
};

TEST_F(Game_F, OneRollCalcScore) {
    //given

    //when
    g.roll(1);

    //then
    ASSERT_THAT(g.score(), Eq(1));
}

TEST_F(Game_F, TwoRollAccumateScore) {
    //given

    //when
    g.roll(1);
    g.roll(1);

    //then
    ASSERT_THAT(g.score(), Eq(2));
}

TEST_F(Game_F, AccumulateEveryFrame) {
    //given
    int firstFrameScore = SetFirstFrameScore();

    //when
    int secondFramePinfalls = 2;
    g.roll(secondFramePinfalls);

    //then
    ASSERT_THAT(g.score(), firstFrameScore + secondFramePinfalls);
}

TEST_F(Game_F, StrikeFrameGetAward) {
    //given
    int firstFrameScore = SetFirstFrameStrike(g);

    //when
    int pinfalls = 1;
    g.roll(pinfalls);

    //then
    ASSERT_THAT(g.score(), firstFrameScore + pinfalls + pinfalls);
}

TEST_F(Game_F, SpareFrameGetAward) {
    //given
    int firstFrameScore = SetFirstFrameSpare(g);

    //when
    int pinfalls = 1;
    g.roll(pinfalls);

    //then
    ASSERT_THAT(g.score(), firstFrameScore + pinfalls + pinfalls);
}

TEST_F(Game_F, StrikeFrameGetAwardTwice) {
    //given
    int firstFrameScore = SetFirstFrameStrike(g);
    int firstPinfallsAtSecodFrame = 8;
    int secondPinfallsAtSecondFrame = 1;

    //when
    g.roll(firstPinfallsAtSecodFrame);
    g.roll(secondPinfallsAtSecondFrame);

    //then
    ASSERT_THAT(g.score(), firstFrameScore + (firstPinfallsAtSecodFrame + secondPinfallsAtSecondFrame) * 2);
}

class GameLastFrame: public ::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }

    int numberOfFrames = 1;
    Game g{numberOfFrames};
};

TEST_F(GameLastFrame, IsNotGetAwardPointEvenThoughFirstRollIsStrike) {
    //given
    int firstPinfalls = 10;
    g.roll(10);

    //when
    g.roll(1);
    g.roll(2);

    //then
    ASSERT_THAT(g.score(), 10+1+2);
}

TEST_F(GameLastFrame, IsNotGetAwardPointEvenThoughSpare) {
    //given
    g.roll(9);
    g.roll(1);

    //when
    g.roll(2);

    //then
    ASSERT_THAT(g.score(), 9+1+2);
}

class Verification : public ::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }

    int nrFrame = 10;
    Game game;
};

TEST_F(Verification, ZerosAreZero) {
    //given

    //when
    for (int i=0; i<nrFrame * 2; i++)
        game.roll(0);

    //then
    ASSERT_THAT(game.score(), Eq(0));
}

TEST_F(Verification, PerfactIs300) {
    //given

    //when
    for (int i=0; i<nrFrame+2; i++)
        game.roll(10);
//
    //then
    ASSERT_THAT(game.score(), Eq(300));
}

TEST_F(Verification, Spare9And1Is191) {
    //when
    for (int i=0; i<nrFrame; i++) {
        game.roll(9);
        game.roll(1);
    }
    game.roll(10);

    //then
    ASSERT_THAT(game.score(), Eq(191));
}