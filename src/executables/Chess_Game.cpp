#include "board.h"
#include "interface.h"
#include "ChessAI.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Chess_board board = initialize_board();
  draw_board(board);

  std::string choice = new_game();
  int turn;

  if (choice == players[0]) {
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
        can = isMovingKing(board, oldMove, newMove, players[turn]);
      } else {

        can = canMove(board, oldMove, newMove, players[turn]);
        if (!can) {
          can = putsInCheck(board, oldMove, newMove, players[turn]);
        }
      }

      if (can) {
        draw_board(board);
        std::cout << "SORRY CANT DO THAT" << '\n';
      }
    }
    std::string taken = searchPlayerType(board,newMove);
    if (taken != players[turn] && taken != "NULL")
      board = deletePiece(board, newMove, players[!turn]);

    board = movePiece(board, oldMove, newMove, players[turn]);
    check = false;
    if (inCheck(board, players[turn], newMove)) {
      check = true;
      winner = checkMate(board, players[!turn]);
    }



    draw_board(board);
    if (check && !winner) {
      std::cout << "Player: " << players[turn] << " is in check!" << '\n';
    }
    if (!winner) {
      turn = !turn;
    }
    can = true;

  }
  std::cout << "Congratulations players " << players[turn] << " you win!" << '\n';
  return 0;
}
