//
// Created by younghyun on 19. 1. 9.
//

#include <gmock/gmock.h>
#include "kata.h"

using namespace testing;

TEST(KataTest, DummyReturn0) {
    auto ret = dummy();
    ASSERT_THAT(ret, Eq(0));
}
