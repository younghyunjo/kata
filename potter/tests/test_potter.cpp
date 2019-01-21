//
// Created by younghyun on 19. 1. 9.
//

#include <gmock/gmock.h>
#include <unordered_map>
#include "potter.h"

using namespace testing;

const int BOOKPRICE = 8;
static std::unordered_map<int, double> discountMap({
    {1, 1},
    {2, 0.95},
    {3, 0.90},
    {4, 0.80},
    {5, 0.75}});


static double calcBuyOneEachBookExpectPrice(int numberOfDifferentBooks) {
    return  numberOfDifferentBooks * discountMap[numberOfDifferentBooks] * BOOKPRICE;
}

void TestBuyOneEachBook(int numberOfDifferentBooks) {
    std::vector<int> books(numberOfDifferentBooks);
    for (int i=0; i<numberOfDifferentBooks; i++)
        books[i] = i;

    auto expectPrice = calcBuyOneEachBookExpectPrice(numberOfDifferentBooks);
    double actualPrice = price(books);

    ASSERT_THAT(expectPrice, DoubleEq(actualPrice));
}

TEST(Potter, BuyOneBook) {
    TestBuyOneEachBook(1);
}

TEST(Potter,BuyTwoBooksEach) {
    TestBuyOneEachBook(2);
}

TEST(Potter, BuyThreeBooksEach) {
    TestBuyOneEachBook(3);
}

TEST(Potter, BuyFiveBooksEach) {
    TestBuyOneEachBook(5);
}


TEST(Potter, BuyTwoSameBooks) {
    std::vector<int> books = {0 , 0};

    auto ret = price(books);

    ASSERT_THAT(ret, Eq(2 * BOOKPRICE));
}

TEST(Potter, BuyTwoSameBooksAndOneOtherBook) {
    std::vector<int> books = {0, 0, 1};

    auto expectPrice = calcBuyOneEachBookExpectPrice(2) + BOOKPRICE;
    auto ret = price(books);

    ASSERT_THAT(ret, DoubleEq(expectPrice));
}

