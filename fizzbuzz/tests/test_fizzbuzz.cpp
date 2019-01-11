//
// Created by younghyun on 19. 1. 9.
//

#include <gmock/gmock.h>

#include "fizzbuzz.h"

using namespace testing;

TEST(FizzBuzz, ReturnsPlainNumber) {
    auto ret = fizzbuzz(1);

    ASSERT_THAT(ret, Eq("1"));
}

TEST(FizzBuzz, ReturnFizzWhenGiveMultiplyOf3) {
    auto ret = fizzbuzz(3);

    ASSERT_THAT(ret, Eq("Fizz"));
}

TEST(FizzBuzz, ReturnBuzzWhenGiveMultiplyOf5) {
    auto ret = fizzbuzz(25);

    ASSERT_THAT(ret, Eq("Buzz"));
}

TEST(FizzBuzz, ReturnFizzBuzzWhenGiveMultiplyOf15) {
    auto ret = fizzbuzz(15);

    ASSERT_THAT(ret, Eq("FizzBuzz"));
}

TEST(FizzBuzz, ReturnFizzWhenGiveContain3) {
    auto ret = fizzbuzz(31);

    ASSERT_THAT(ret, Eq("Fizz"));
}

TEST(FizzBuzz, ReturnBuzzWhenGiveContain5) {
    auto ret = fizzbuzz(55);

    ASSERT_THAT(ret, Eq("Buzz"));
}
