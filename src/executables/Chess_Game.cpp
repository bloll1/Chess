#include "board.h"
#include <iostream>

int main(int argc, char const *argv[]) {

  Chess_board board = initialize_board();

  for (int i = 0; i < (int)board.piec.size(); i++) {

    std::cout << board.piec[i]->toString();

  }


  return 0;
}
