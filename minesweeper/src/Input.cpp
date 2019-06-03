
//
// Created by younghyun on 19. 3. 15.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <cstring>
#include "Input.h"

Input::Input(std::istream& istream) : stream_{istream} {
}

int Input::parseRowColumn() {
    std::string s;
    std::getline(stream_, s, '\n');

    char *word, *brkt;
    char* sep = " \n";

    auto row = strtok_r((char*)s.c_str(), sep, &brkt);
    row_ = atoi(row);
    auto column = strtok_r(NULL, sep, &brkt);
    column_ = atoi(column);

    return 0;
}

int Input::parseBoard() {
  board_ = std::vector<std::vector<int>>(row_, std::vector<int>(column_, 0));

  std::string s;
  for (int i=0; i<row_; i++) {
    std::getline(stream_, s, '\n');
    for (int j=0; j<column_; j++) {
      if (s[j] == '*')
        board_[i][j] = -1;
    }
  }
  return 0;
}

int Input::parse() {
    if (parseRowColumn() < 0)
        return -1;

    if (row_ <= 0 || column_ <= 0)
      return -1;


    return parseBoard();
}

int Input::getRow() {
    return row_;
}

int Input::getColumn() {
    return column_;
}

std::vector<std::vector<int>> Input::getBoard() {
  return board_;
}
