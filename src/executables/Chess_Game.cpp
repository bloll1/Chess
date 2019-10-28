#include "board.h"
#include "interface.h"
#include <iostream>

int main(int argc, char const *argv[]) {

  Chess_board board = initialize_board();
/*  std::cout << "PIECES::" << '\n';
  for (int i = 0; i < (int)board.piec.size(); i++) {

    std::cout << board.piec[i]->toString();

  }

  std::cout << "BOARD COORDINATES::" << '\n';
  for (int y = 0; y < 64; y++) {
    std::cout << board.toString(y) << '\n';
  }*/
  std::string choice = new_game();

  return 0;
}
