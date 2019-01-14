//
// Created by younghyun on 19. 1. 9.
//

#include <gmock/gmock.h>
#include "potter.h"

using namespace testing;

TEST(Potter, BuySingleBook) {
    std::vector<int> buying = {0};
    auto ret = price(buying);

    ASSERT_THAT(ret, Eq(8));
}


