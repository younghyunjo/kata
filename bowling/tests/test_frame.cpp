#include "frame.h"

#include <gmock/gmock.h>

using namespace testing;

int makeSpareFrame(Frame& f) {
    f.roll(9);
    f.roll(1);
    return 10;
}

int makeOpenFrame(Frame& f) {
    f.roll(1);
    f.roll(2);
    return 3;
}

class Frame_F : public ::Test {
protected:
    void SetUp() override {
        
    }
    
    void TearDown() override {
        
    }

    int SetSpare() {
        f_.roll(9);
        f_.roll(1);
        return 10;
    }

    int SetOpen() {
        f_.roll(1);
        f_.roll(1);
        return 2;
    }

    int SetStrike() {
        f_.roll(10);
        return 10;
    }
    
    Frame f_;
};

TEST_F(Frame_F, HasZeroScoreAfterCreated) {
    //when
    auto score = f_.getScore();

    //then
    ASSERT_THAT(score, Eq(0));
}

TEST_F(Frame_F, RollCalculateScore) {
    //given
    int pinfalls = 9;

    //when
    f_.roll(pinfalls);

    //then
    ASSERT_THAT(f_.getScore(), pinfalls);
}

TEST_F(Frame_F, RollTwiceAddTotalScore) {
    //given
    int firstPinfalls = 1;
    int secondPinfalls = 1;

    //when
    f_.roll(firstPinfalls);
    f_.roll(secondPinfalls);

    //then
    ASSERT_THAT(f_.getScore(), Eq(firstPinfalls + secondPinfalls));
}

TEST_F(Frame_F, IfFirstRollIsStrikeSecondRollIsInvalid) {
    //given
    int firstPinfalls = 10;
    f_.roll(firstPinfalls);

    //when
    int secondPinfalls = 1;
    f_.roll(secondPinfalls);

    //then
    ASSERT_THAT(f_.getScore(), firstPinfalls);
}

TEST_F(Frame_F, RollingIsNotEffectToSpareFrame) {
    //given
    SetSpare();
    auto spareScore = f_.getScore();

    //when
    int additionalPinfalls = 9;
    f_.roll(additionalPinfalls);

    ASSERT_THAT(f_.getScore(), Eq(spareScore));
}

TEST_F(Frame_F, OpenFrameDoesNotGetAward) {
    //given
    SetOpen();
    auto openScore = f_.getScore();

    //when
    f_.award(10);

    ASSERT_THAT(f_.getScore(), Eq(openScore));
}

TEST_F(Frame_F, SpareFrameGetOneAward) {
    SetSpare();
    auto spareScore = f_.getScore();

    //when
    int awardPoint = 2;
    f_.award(awardPoint);

    ASSERT_THAT(f_.getScore(), Eq(spareScore + awardPoint));
}

TEST_F(Frame_F, SpareFrameDoesNotGetSecondAward) {
    //given
    SetSpare();
    auto spareScore = f_.getScore();
    int firstAwardPoint = 1;
    f_.award(firstAwardPoint);

    //when
    int secondAwardPoint = 1;
    f_.award(secondAwardPoint);

    //then
    ASSERT_THAT(f_.getScore(), spareScore + firstAwardPoint);
}

TEST_F(Frame_F, StrikeFrameGetsAward) {
    //given
    auto strikeScore = SetStrike();
    int awardPoint = 2;

    //when
    f_.award(awardPoint);

    //then
    ASSERT_THAT(f_.getScore(), Eq(strikeScore + awardPoint));
}

TEST_F(Frame_F, StrikeFrameGetAwardTwice) {
    //given
    auto strikeScore = SetStrike();
    int firstAward = 1;
    int secondAward = 1;
    f_.award(firstAward);

    //when
    f_.award(secondAward);

    //then
    ASSERT_THAT(f_.getScore(), Eq(strikeScore + firstAward + secondAward));
}

TEST_F(Frame_F, StrikeFrameDoesNotGetAwardMoreThanTwice) {
    //given
    auto strikeScore = SetStrike();
    int firstAward = 1;
    int secondAward = 1;
    int thirdAward = 1;
    f_.award(firstAward);
    f_.award(secondAward);

    //when
    f_.award(thirdAward);

    //then
    ASSERT_THAT(f_.getScore(), Eq(strikeScore + firstAward + secondAward));
}

TEST_F(Frame_F, RollingIsNotEffectToStrikeFrame) {
    //given
    auto strikeScore = SetStrike();
    int additionalRolling = 1;

    //when
    f_.roll(additionalRolling);

    //then
    ASSERT_THAT(f_.getScore(), Eq(strikeScore));
}

TEST_F(Frame_F, IsNotEndAfterRollingOnce) {
    //given
    int pinfalls = 1;

    //when
    auto endOfFrame = f_.roll(pinfalls);

    //then
    ASSERT_THAT(endOfFrame, Eq(false));
}

TEST_F(Frame_F, IsEndOfFrameAfterStrike) {
    //given
    int pinfalls = 10;

    //when
    auto endOfFrame = f_.roll(pinfalls);

    //then
    ASSERT_THAT(endOfFrame, Eq(true));
}

TEST_F(Frame_F, IsEndAfterSpare) {
    //given
    int firstPinfalls = 9;
    f_.roll(firstPinfalls);

    //when
    int secondPinfalls = 1;
    auto endOfFrame = f_.roll(secondPinfalls);

    //then
    ASSERT_THAT(endOfFrame, Eq(true));
}

TEST(Frame, CanSetLastFrame) {
    Frame f{true};
}

class LastFrame_F : public ::Test {
protected:
     void SetUp() override {

     }

     void TearDown() override {

     }

     Frame f_{true};
};

TEST_F(LastFrame_F, IsNotEnd_X) {
    //given

    //when
    auto endofFrame = f_.roll(10);


    //then
    ASSERT_THAT(endofFrame, Eq(false));
}

TEST_F(LastFrame_F, IsNotEnd_XX) {
    //given
    f_.roll(10);

    //when
    auto endofFrame = f_.roll(10);

    //then
    ASSERT_THAT(endofFrame, Eq(false));
}

TEST_F(LastFrame_F, IsEnd_XXX) {
    //given
    f_.roll(10);
    f_.roll(10);

    //when
    auto endofFrame = f_.roll(10);

    //then
    ASSERT_THAT(endofFrame, Eq(true));
}
