#include "board.h"
#include "interface.h"
#include <iostream>

int main(int argc, char const *argv[]) {

  Chess_board board = initialize_board();
  draw_board(board);

  std::string choice = new_game();
  int winner = 0;
  bool can = true;
  std::string oldMove, newMove;
  while(winner == 0/* && choice != quit*/) {
    while (can) {
      oldMove = oturn();
      newMove = nturn();
      can = canMove(board, oldMove, newMove);
      if (can) {
        std::cout << "SORRY CANT MOVE THERE" << '\n';
      }
    }

    board = movePiece(board, oldMove, newMove);
    draw_board(board);
    winner = checkMate(board);

    can = true;

  }
  return 0;
}
