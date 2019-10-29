#include "board.h"
#include "interface.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  std::string player[] = {"white", "black"};
  Chess_board board = initialize_board();
  draw_board(board);

  std::string choice = new_game();
  int turn;

  if (choice == player[0]) {
    turn = 0;
  } else {
    turn = 1;
  }
  int winner = 0;
  bool can = true;
  std::string oldMove, newMove;
  while(winner == 0/* && choice != quit*/) {
    while (can) {
      oldMove = oturn(turn);
      newMove = nturn();
      if (turn) {
        can = canMove(board, oldMove, newMove, player[1]);
      } else {
        can = canMove(board,oldMove,newMove, player[0]);
      }

      if (can) {
        std::cout << "SORRY CANT DO THAT" << '\n';
      }
    }
    if (turn) {
      board = movePiece(board, oldMove, newMove, player[1]);
    } else {
      board = movePiece(board, oldMove, newMove, player[0]);
    }

    //turn = !turn;
    draw_board(board);
    winner = checkMate(board);

    can = true;

  }
  return 0;
}
