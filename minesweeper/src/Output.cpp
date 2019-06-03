//
// Created by younghyun on 19. 5. 22.
//
#include <iostream>

#include "Output.h"



void Output::print(int fieldNumber, std::vector<std::vector<int>>& board) {
  if (fieldNumber !=0)
    std::cout << "\n";

  std::cout << "Field #" << fieldNumber << ":" << std::endl;
  auto row = board.size();
  auto column = board[0].size();

  for (int i=0; i<row; i++) {
    for (int j=0; j<column; j++) {
      if (board[i][j] == -1)
        std::cout << "*";
      else
        std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}