//
// Created by younghyun on 19. 3. 15.
//

#include <gmock/gmock.h>

#include <sstream>
#include <iostream>
#include "Input.h"

using namespace testing;

TEST(Input, hasClassNamedInput) {
    //given
    std::stringstream ss("23 345\n");

    //when
    class Input i{ss};

    //then
    //no compile error
}

static void initInput(std::stringstream& istream, int row = 1, int column = 1) {
    istream << row << " " << column << std::endl;
}

static void appendBoard(std::stringstream& istream, std::vector<std::string>& board) {
  for(auto b : board) {
    istream << b << std::endl;
  }
}

class Input_Parse_F : public ::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }

    std::stringstream inputStream;
    Input i{inputStream};
};

TEST_F(Input_Parse_F, returnsSuccess) {
    //given
    initInput(inputStream);

    //when
    auto ret = i.parse();

    //then
    ASSERT_THAT(ret, Eq(0));
}

TEST_F(Input_Parse_F, parseRowAndColumn) {
    //given
    auto row = 2;
    auto column = 2;
    initInput(inputStream, row, column);

    //when
    i.parse();

    //then
    ASSERT_THAT(i.getRow(), Eq(row));
    ASSERT_THAT(i.getColumn(), Eq(column));
}

TEST_F(Input_Parse_F, parseErroredRow) {
  //given
  auto row = -1;
  auto column = 2;
  initInput(inputStream, row, column);

  //when
  auto ret = i.parse();

  //then
  ASSERT_THAT(ret, Eq(-1));
}

TEST_F(Input_Parse_F, parseBoard) {
  auto row = 4;
  auto column = 4;
  std::vector<std::string> board = {"*...", "....", ".*..", "...."};

  initInput(inputStream, row, column);
  appendBoard(inputStream, board);

  //when
  i.parse();
  auto b = i.getBoard();

  ASSERT_THAT(b[0][0], Eq(-1));

}

