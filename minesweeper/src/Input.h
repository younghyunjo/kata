//
// Created by younghyun on 19. 3. 15.
//

#ifndef MINESWEEPER_INPUT_H
#define MINESWEEPER_INPUT_H

#include <istream>

class Input {
public:
    Input(std::istream& istream);
    int parse();
    int getRow();
    int getColumn();
    std::vector<std::vector<int>> getBoard();

private:
    int parseBoard();
    int parseRowColumn();
    std::istream& stream_;
    int row_;
    int column_;
    std::vector<std::vector<int>> board_;
};


#endif //MINESWEEPER_INPUT_H
