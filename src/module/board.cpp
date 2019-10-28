
#include "board.h"

#include <string>

Chess_board initialize_board() {
    Chess_board *new_board = new Chess_board();
    std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
    std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
    std::string chess_pieces[8] = {"rook","knight","bishop","king","queen",
                                    "bishop", "knight", "rook"};

      for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 8; x++) {
            if (y == 0) {
              Chess_piece *p = new Chess_piece(position_x[x], position_y[1],
                                  "white", "pawn");
              new_board->addPiece(p);

            } else {
              Chess_piece *p = new Chess_piece(position_x[x], position_y[6],
                                  "black", "pawn");
              new_board->addPiece(p);
            }
          }
        }
      for (int b = 0; b < 2; b++) {
        for (int d = 0; d < 8; d++) {
          if (b == 0) {
            Chess_piece *p = new Chess_piece(position_x[d], position_y[0],
                                "white", chess_pieces[d]);
            new_board->addPiece( p);

          } else {
            Chess_piece *p = new Chess_piece(position_x[d], position_y[7],
                                "black", chess_pieces[d]);
            new_board->addPiece( p);
          }
        }
      }
    return *new_board;
}

void draw_board(Chess_board board) {
  for (int i = 0; i < (int)board.piec.size(); i++) {

    std::cout << board.piec[i]->toString();

  }

}

Chess_board movePiece(Chess_board board, std::string oldMove, std::string newMove) {
    std::string pos;
    Chess_board new_board = board;
  for (int i = 0; i < (int)board.piec.size(); i++) {
     pos = new_board.piec[i]->position[0] + new_board.piec[i]->position[1];
     if (oldMove == pos) {
       new_board.piec[i]->position[0] = newMove[0];
       new_board.piec[i]->position[1] = newMove[1];
       return new_board;
     }
  }
  return board;

}


std::string searchPieceType(Chess_board board, std::string move) {
  std::string pos;
  for (int i = 0; i < (int)board.piec.size(); i++) {
     pos = board.piec[i]->position[0] + board.piec[i]->position[1];
     if (move == pos) {
       return board.piec[i]->player;
     }
  }
  return "NULL";
}


bool canMove(Chess_board board, std::string oldMove, std::string newMove) {
  //piece_type and taken are used to check if the position has a piece and
  //the next position is empty. TODO: check if the piece can legally move there
  std::string piece_type = searchPieceType(board,oldMove);
  std::string taken = searchPieceType(board,newMove);
  if (piece_type == "NULL" || taken != "NULL") {
    return true;
  }
  return false;
}

int checkMate(Chess_board board) {

  return 0;
}
