//
// Created by younghyun on 19. 1. 9.
//

#include <string>

static char toChar(int number) {
    return (char)number + '0';
}

static bool isDivisible(int number, int divider) {
    return number % divider == 0;
}

static bool hasDigit(int number, int digit) {
    return std::to_string(number).find(toChar(digit)) != std::string::npos;
}

static bool isFizzOrBuzz(int number, int fizzbuzz) {
    return isDivisible(number, fizzbuzz) || hasDigit(number, fizzbuzz);
}

static bool isFizz(int number) {
    const int FIZZ= 3;

    return isFizzOrBuzz(number, FIZZ);
}

static bool isBuzz(int number) {
    const int BUZZ = 5;

    return isFizzOrBuzz(number, BUZZ);
}

std::string fizzbuzz(int number) {
    std::string ret;

    if (isFizz(number)) {
        ret += "Fizz";
    }
    if (isBuzz(number)) {
        ret += "Buzz";
    }

    if (ret.length() == 0)
        ret = std::to_string(number);

    return ret;
}