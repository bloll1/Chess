#ifndef BOARD
#define  BOARD
#include "peices.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <array>

struct Chess_board {
public:
  //std::string chess_piece_types[6] = {"pawn","bishop","knight","king","queen",
              //                        "rook"};
  std::vector<Chess_piece*> piec;

  std::vector< char( * ) > boardcord;


  Chess_board(){
    char position_x[8] = {'a','b','c','d','e','f','g','h'};
    char position_y[8] = {'1','2','3','4','5','6','7','8'};
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
        char * str3 = (char *)malloc(3);
        char arb[3] = {position_x[x % 8] ,position_y[y % 8] , '\0'};
        strncpy(str3, (char *)arb, 3);
        boardcord.push_back(str3);
      }
    }
  };

  void addPiece(Chess_piece *p){
    piec.push_back(p);
  };



  std::string toString(int n) {
    return std::string( boardcord.at(n));
  };

};

bool putsInCheck(Chess_board board, std::string oldMove, std::string newMove, std::string player);

bool movingPieceBlocks(Chess_board board, std::string oldMove, std::string newMove, std::string player);

void draw_box(Chess_board board, std::string pos);

std::string getPiece(Chess_board board, std::string pos);

bool pieceBlocks(Chess_board board, std::string player);

bool isMovingKing(Chess_board board, std::string oldMove, std::string newMove, std::string player);

bool inCheck(Chess_board board, std::string player, std::string pos);

bool canDelete(Chess_board board, std::string pos, std::string player, std::string piece);

bool canKingMove(Chess_board board, std::string player);

bool checkMate(Chess_board board, std::string player);

bool canMoveWithoutDelete(Chess_board board, std::string pos, std::string player);

std::string searchPlayerType(Chess_board board, std::string move);

bool legalQueenMove(Chess_board board, std::string oldMove, std::string newMove);

bool legalBishopMove(Chess_board board, std::string oldMove, std::string newMove);

bool legalRookMove(Chess_board board, std::string oldMove, std::string newMove);

bool legalKingMove(Chess_board board, std::string oldMove, std::string newMove);

bool legalPawnMove(Chess_board board, std::string oldMove, std::string newMove, std::string player);

bool legalKnightMove(Chess_board board, std::string oldMove, std::string newMove);

bool legalPieceMove(Chess_board board, std::string oldMove, std::string newMove, std::string player);

int checkMate(Chess_board board);

Chess_board initialize_board();

void draw_board(Chess_board board);

Chess_board movePiece(Chess_board board, std::string oldMove, std::string newMove, std::string player);

std::string searchPieceType(Chess_board board, std::string move);

bool canMove(Chess_board board, std::string oldMove, std::string newMove, std::string player);

#endif /* Board */
