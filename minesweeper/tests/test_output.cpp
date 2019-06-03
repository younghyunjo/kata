//
// Created by younghyun on 19. 5. 22.
//

#include <iostream>
#include <gmock/gmock.h>

using namespace testing;

#include "Output.h"

TEST(Output, print) {
  Output o;
  auto fieldNumber = 0;

  std::vector<std::vector<int>> board = {
      {-1, 1, 0, 0},
      {2, 2, 1, 0},
      {1, -1, 1, 0},
      {1, 1, 1, 0},
  };
  std::cout << std::endl;
  o.print(fieldNumber, board);
}
