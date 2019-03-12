//
// Created by younghyun on 19. 1. 30.
//

#include <gmock/gmock.h>
#include "frame_state_machine.h"
using namespace testing;

int SetStrike(FrameStateMachine& fsm) {
    int score = 0;
    score = fsm.pinfallsAddable(score, 10);

    return 10;
}

int SetSpare(FrameStateMachine& fsm) {
    int score = 0;
    score = fsm.pinfallsAddable(score, 1);
    fsm.pinfallsAddable(score, 9);

    return 10;
}

int SetOpen(FrameStateMachine& fsm) {
    int score = 0;
    score = fsm.pinfallsAddable(score, 1);
    fsm.pinfallsAddable(score, 1);

    return 2;
}

class FrameStateMachine_F: public ::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    FrameStateMachine fsm_;
};


TEST_F(FrameStateMachine_F, IsReadyAfterCreated) {
    ASSERT_THAT(fsm_.get(), fsm_.ready());
}

TEST_F(FrameStateMachine_F, IsStrikePinfallsIs10) {
    //given
    int score = 0;
    int pinfalls = 10;

    //when
    fsm_.pinfallsAddable(score, pinfalls);

    //then
    ASSERT_THAT(fsm_.get(), Eq(fsm_.strike()));
}

TEST_F(FrameStateMachine_F, IsOncePinfallsIsNot10) {
    //given
     int score = 0;
    int pinfalls = 9;

    //when
    fsm_.pinfallsAddable(score, pinfalls);

    //then
    ASSERT_THAT(fsm_.get(), Eq(fsm_.once()));
}

TEST_F(FrameStateMachine_F, IsOpenAfterEndOfFrameScoreIsLessThan10)
{
    int firstPinfalls = 1;
    int secondPinfalls = 2;

    fsm_.pinfallsAddable(0, firstPinfalls);
    fsm_.pinfallsAddable(firstPinfalls, secondPinfalls);

    ASSERT_THAT(fsm_.get(), Eq(fsm_.open()));
}

TEST_F(FrameStateMachine_F, IsSpareAfterEndOfFrameScoreIs10) {
    int firstPinfalls = 1;
    int secondPinfalls = 9;

    fsm_.pinfallsAddable(0, firstPinfalls);
    fsm_.pinfallsAddable(firstPinfalls, secondPinfalls);

    ASSERT_THAT(fsm_.get(), Eq(fsm_.spare()));
}

TEST_F(FrameStateMachine_F, RollReturnsSameAsFirstPinfalls) {
    int firstPinfalss = 1;
    int score = 0;

    auto ret = fsm_.pinfallsAddable(score, firstPinfalss);

    ASSERT_THAT(ret, Eq(firstPinfalss));
}

TEST_F(FrameStateMachine_F, RollReturnsTotalScoreEndOfFrame) {
    int score = 0;
    int firstPinfalls = 1;
    int secondPinfalls = 9;

    if (fsm_.pinfallsAddable(score, firstPinfalls))
        score += firstPinfalls;

    if (fsm_.pinfallsAddable(score, secondPinfalls))
        score += secondPinfalls;

    ASSERT_THAT(score, Eq(firstPinfalls + secondPinfalls));
}

TEST_F(FrameStateMachine_F, AwardReturnsAddedPointIfSpareState) {
    SetSpare(fsm_);
    auto award = 1;

    auto ret = fsm_.awardAddable(award);

    ASSERT_THAT(ret, Eq(true));
}

TEST_F(FrameStateMachine_F, AwardDoesNotAddAwardPointIfOpenState) {
    SetOpen(fsm_);

    auto ret = fsm_.awardAddable(1);

    ASSERT_THAT(ret, Eq(false));
}

TEST_F(FrameStateMachine_F, HasEndOfFrame) {
    //given

    //when
    fsm_.endOfFrame();

    //then
    //no compile error
}

TEST_F(FrameStateMachine_F, ReadyStateEndOfFrameIsFalse) {
    //given

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, false);
}

TEST_F(FrameStateMachine_F, OnceStateEndOfFrameIsFalse) {
    //given
    int score = 0;
    int pinfalls = 1;
    fsm_.pinfallsAddable(score, pinfalls);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, false);
}

TEST_F(FrameStateMachine_F, OpenStateEndOfFrameIsTrue) {
    //given
    SetOpen(fsm_);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, true);
}

TEST_F(FrameStateMachine_F, SpareStateEndOfFrameIsTrue) {
    //given
    SetSpare(fsm_);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, true);
}

TEST_F(FrameStateMachine_F, StrikeStateEndOfFrameIsTrue) {
    //given
    SetStrike(fsm_);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, true);
}

class FrameStateMachineLastFrame_F : public ::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }

    FrameStateMachine fsm_{true};
};

TEST_F(FrameStateMachineLastFrame_F, IsLastFrameReturnTrue) {
    ASSERT_THAT(fsm_.isLastFrame(), Eq(true));
}

TEST_F(FrameStateMachineLastFrame_F, CanGetOneRollAtSpareFrame) {
    auto score = SetSpare(fsm_);

    auto addable = fsm_.pinfallsAddable(score, 1);

    ASSERT_THAT(addable, Eq(true));
}

TEST_F(FrameStateMachineLastFrame_F, CanNotGetTwoMoreRollAtSpareFrame) {
    //given
    auto score = SetSpare(fsm_);
    fsm_.pinfallsAddable(score, 1);

    //when
    auto addable = fsm_.pinfallsAddable(score, 1);

    //then
    ASSERT_THAT(addable, Eq(false));
}

TEST_F(FrameStateMachineLastFrame_F, CanGetOneRollAtStrikeFrame) {
    //given
    auto score = SetStrike(fsm_);

    //when
    auto addable = fsm_.pinfallsAddable(score, 1);

    //then
    ASSERT_THAT(addable, Eq(true));
}

TEST_F(FrameStateMachineLastFrame_F, CanGetSecondRollAtStrikeFrame) {
    //given
    auto score = SetStrike(fsm_);
    fsm_.pinfallsAddable(score, 1);

    //when
    auto addable = fsm_.pinfallsAddable(score, 1);

    //then
    ASSERT_THAT(addable, Eq(true));
}

TEST_F(FrameStateMachineLastFrame_F, CanNotGetTreeMoreRollAtStrikeFrame) {
    //given
    auto score = SetStrike(fsm_);
    fsm_.pinfallsAddable(score, 1);
    fsm_.pinfallsAddable(score, 1);

    //when
    auto addable = fsm_.pinfallsAddable(score, 1);

    //then
    ASSERT_THAT(addable, Eq(false));
}

TEST_F(FrameStateMachineLastFrame_F, SpareStateEndOfFrameIsFalse) {
    //given
    SetSpare(fsm_);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, false);
}

TEST_F(FrameStateMachineLastFrame_F, SpareStateFrameAndRollOnce_EndOfFrameIsTrue) {
    //given
    auto score = SetSpare(fsm_);
    fsm_.pinfallsAddable(score, 1);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, Eq(true));
}

TEST_F(FrameStateMachineLastFrame_F, StrikeEndOfFrameIsFalse) {
    //given
    SetStrike(fsm_);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, false);
}

TEST_F(FrameStateMachineLastFrame_F, StrikeAndRollOnce_EndOfFrameIsFalse) {
    //given
    auto score = SetStrike(fsm_);
    fsm_.pinfallsAddable(score, 1);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, Eq(false));
}

TEST_F(FrameStateMachineLastFrame_F, StrikeAndRollTwice_EndOfFrameIsFalse) {
    //given
    auto score = SetStrike(fsm_);
    fsm_.pinfallsAddable(score, 1);
    fsm_.pinfallsAddable(score, 1);

    //when
    auto ret = fsm_.endOfFrame();

    //then
    ASSERT_THAT(ret, Eq(true));
}
