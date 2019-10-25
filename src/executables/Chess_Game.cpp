#include "board.h"
#include <iostream>

int main(int argc, char const *argv[]) {

  Chess_board board = initialize_board();

  for (int i = 0; i < 32; i++) {
    std::cout << board.piec[i]->toString();

  }
  delete &board;

  return 0;
}
