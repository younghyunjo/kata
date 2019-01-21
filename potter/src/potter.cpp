//
// Created by younghyun on 19. 1. 9.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>

static const int BOOKPRICE = 8;


double getDiscountRate(int numberOfBooks) {
    static std::unordered_map<int, double> discountMap({
        {1, 1},
        {2, 0.95},
        {3, 0.90},
        {4, 0.80},
        {5, 0.75}});

    if (numberOfBooks > discountMap.size())
        return 0;

    return discountMap[numberOfBooks];
}


auto categorize(const std::vector<int>& buyingBooks) {

    std::vector<int> buyingBooksMap(5, 0);
    for (auto b : buyingBooks) {
        buyingBooksMap[b]++;
    }
    return buyingBooksMap;
}

double price2(std::vector<int> books) {
    if (*std::max_element(std::begin(books), std::end(books)) > 1) {
        auto price = 99999999999.0;

        for(auto i=0; i<5 ;i++) {
            if (books[i] - 1 < 0)
                continue;

            auto temporatyBooks = books;
            temporatyBooks[i] = books[i] -1;
            price = std::min(price, price2(temporatyBooks) + 8);
        }

        return price;
    }

    auto numberOfSigleBook = std::accumulate(std::begin(books), std::end(books), 0, [](int a, int b) {
        if ( b == 1)
            return a+b;
        return a;
    });

    auto discountRate = getDiscountRate(numberOfSigleBook);
    return BOOKPRICE * numberOfSigleBook * discountRate;
}

double price(std::vector<int> buyingBooks) {
    auto buyingBooksMap = categorize(buyingBooks);
    return price2(buyingBooksMap);
}
