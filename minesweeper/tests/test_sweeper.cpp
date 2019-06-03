//
// Created by younghyun on 19. 5. 15.
//
#include <gmock/gmock.h>

using namespace testing;

#include "Sweeper.h"

TEST(Sweeper, do) {
    Sweeper s;

    std::vector<std::vector<int>> board = {
        {-1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, -1, 0, 0},
        {0, 0, 0, 0},
    };

    s.sweep(board);

    ASSERT_THAT(board[0][1], Eq(1));
    ASSERT_THAT(board[0][0], Eq(-1));
    ASSERT_THAT(board[1][0], Eq(2));
    ASSERT_THAT(board[3][3], Eq(0));
    ASSERT_THAT(board[3][1], Eq(1));
}
