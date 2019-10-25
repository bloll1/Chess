
#include "board.h"

#include <string>

Chess_board initialize_board() {
    Chess_board *new_board = NULL;
    std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
    std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
    std::string chess_pieces[8] = {"rook","knight","bishop","king","queen",
                                    "bishop", "knight", "rook"};

      std::cout << "EMPTY" <<  new_board->piec.empty() << '\n';                                
  //  int count = 0;
      //ADD PAWN OBJECTS:
      for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 8; x++) {
            if (y == 0) {
              Chess_piece *p = new Chess_piece(position_x[x], position_y[1],
                                  "white", "pawn");

              new_board->addPiece(p);
              //count++;
            } else {
              Chess_piece *p = new Chess_piece(position_x[x], position_y[6],
                                  "black", "pawn");

              new_board->addPiece(p);
              //count++;
            }
          }
        }
      for (int b = 0; b < 2; b++) {
        for (int d = 0; d < 8; d++) {
          if (b == 0) {
            Chess_piece *p = new Chess_piece(position_x[d], position_y[0],
                                "white", chess_pieces[d]);

            new_board->addPiece( p);
          //count++;
          } else {
            Chess_piece *p = new Chess_piece(position_x[d], position_y[7],
                                "black", chess_pieces[d]);

            new_board->addPiece( p);
            //count++;
          }
        }
      }

    draw_board();

    return *new_board;
}

void draw_board() {


}
