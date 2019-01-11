//
// Created by younghyun on 19. 1. 9.
//

#include <iostream>
#include "fizzbuzz.h"

int main(void) {
    for (auto i=1; i<=100; i++) {
        std::cout << fizzbuzz(i) << std::endl;
    }

    return 0;
}
