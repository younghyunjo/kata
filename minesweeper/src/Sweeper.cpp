//
// Created by younghyun on 19. 5. 15.
//

#include "Sweeper.h"

void sweepMine(std::vector<std::vector<int>>& board, int i, int j) {
  auto row = board.size();
  auto column = board[0].size();

  for (int a=-1; a<=1; a++) {
    for (int b = -1; b<=1; b++) {
      int x = i+a;
      int y = j+b;
      if (x >=0 && j >= 0 && x < row && y < column && board[x][y] != -1) {
        board[x][y]++;
      }
    }
  }
}

void Sweeper::sweep(std::vector<std::vector<int>>& board) {
  auto row = board.size();
  auto column = board[0].size();

  for (int i=0; i<row; i++) {
    for (int j=0; j<column; j++) {
      if (board[i][j] == -1) {
        sweepMine(board, i, j);
      }
    }
  }
}