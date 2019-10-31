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
      can = canMove(board, oldMove, newMove, player[turn]);

      if (can) {
        std::cout << "SORRY CANT DO THAT" << '\n';
      }
    }

    board = movePiece(board, oldMove, newMove, player[turn]);
    winner = checkMate(board, player[!turn], newMove);

    if (winner == 0) {
      turn = !turn;
    }

    draw_board(board);

    can = true;

  }
  std::cout << "Congratulations player " << player[turn] << " you win!" << '\n';
  return 0;
}
