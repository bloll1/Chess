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
  bool winner = false;
  bool check = false;
  bool can = true;
  std::string oldMove, newMove;
  while(!winner && oldMove != "quit"  && newMove != "quit") {
    while (can && oldMove != "quit"  && newMove != "quit") {

      oldMove = oturn(turn);


      newMove = nturn();

      if (check) {
        can = isMovingKing(board, oldMove, newMove, player[turn]);
      } else {

        can = canMove(board, oldMove, newMove, player[turn]);
        if (!can) {
          can = putsInCheck(board, oldMove, newMove, player[turn]);
        }
      }

      if (can) {
        std::cout << "SORRY CANT DO THAT" << '\n';
      }
    }
    std::cout << "MOVING THE PIECE (44)" << '\n';
    std::string taken = searchPlayerType(board,newMove);
    if (taken != player[turn] && taken != "NULL")
      board = deletePiece(board, newMove, player[!turn]);

    board = movePiece(board, oldMove, newMove, player[turn]);
    check = false;
    if (inCheck(board, player[turn], newMove)) {
      check = true;
      winner = checkMate(board, player[!turn]);
    }



    draw_board(board);
    if (check && !winner) {
      std::cout << "Player: " << player[turn] << " is in check!" << '\n';
    }
    if (!winner) {
      turn = !turn;
    }
    can = true;

  }
  std::cout << "Congratulations player " << player[turn] << " you win!" << '\n';
  return 0;
}
