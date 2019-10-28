#include "board.h"
#include "interface.h"
#include <iostream>

int main(int argc, char const *argv[]) {

  Chess_board board = initialize_board();
  draw_board(board);
/*  std::cout << "PIECES::" << '\n';
  for (int i = 0; i < (int)board.piec.size(); i++) {

    std::cout << board.piec[i]->toString();

  }

  std::cout << "BOARD COORDINATES::" << '\n';
  for (int y = 0; y < 64; y++) {
    std::cout << board.toString(y) << '\n';
  }*/

  std::string choice = new_game();
  int winner = 0;
  bool can = true;
  std::string oldMove, newMove;
  while(winner == 0 && choice != quit) {
    while (can) {
      oldMove = oturn();
      newMove = nturn();
      can = canMove(board, oldMove, newMove);
    }

    draw_board(board);
    board = movePiece(board, oldMove, newMove);
    winner = checkMate();
  }
  return 0;
}
