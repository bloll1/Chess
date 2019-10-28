#ifndef BOARD
#define  BOARD
#include "peices.h"
#include <string>
#include <iostream>
#include <vector>
#include <array>

struct Chess_board {
public:
  std::string chess_piece_types[6] = {"pawn","bishop","knight","king","queen",
                                      "rook"};
  std::vector<Chess_piece*> piec;

  std::vector< char( * )[3] > boardcord;


  Chess_board(){
    char position_x[8] = {'a','b','c','d','e','f','g','h'};
    char position_y[8] = {'1','2','3','4','5','6','7','8'};
    for (int i = 0; i < 64; i++) {

      char cord[3] = {position_x[i % 8], ',' , position_y[i % 8]};
      boardcord.push_back(&cord);
    }
  };

  void addPiece(Chess_piece *p){
    piec.push_back(p);
  };



  std::string toString(int n) {


    return str;
  };

};



Chess_board initialize_board();

void draw_board();

#endif /* Board */
