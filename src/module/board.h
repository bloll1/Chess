#ifndef BOARD
#define  BOARD
#include "peices.h"
#include <string>
#include <iostream>
#include <vector>
struct Chess_board {
public:
  std::string chess_piece_types[6] = {"pawn","bishop","knight","king","queen",
                                      "rook"};
  std::vector<Chess_piece*> piec;



  Chess_board();

  void addPiece(Chess_piece *p) {


    std::cout << "HI" << '\n';
    std::cout << p->toString();
    std::cout << "BYE" << '\n';

    piec.push_back(p);


  };

};



Chess_board initialize_board();

void draw_board();

#endif /* Board */
