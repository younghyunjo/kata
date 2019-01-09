//
// Created by younghyun on 19. 1. 9.
//

#include <gtest/gtest.h>
#include "kata.h"

TEST(KataTest, DummyReturn0) {
    auto ret = dummy();
    EXPECT_EQ(ret, 0);
}