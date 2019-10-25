
#ifndef PIECE
#define  PIECE
#include <string>

struct Chess_piece {
public:

  std::string position[2];
  std::string player;
  std::string chess_piece_type;


  Chess_piece(std::string x,std::string y, std::string play, std::string C_P_T) {
    position[0] = x;
    position[1] = y;
    player = play;
    chess_piece_type = C_P_T;
  };

  std::string toString() {
    std::string x,y;
    x = position[0];
    y = position[1];
    std::string str = "\nPlAYER: " + player + "\n"
                  + "POSITION: " + x + " " + y + "\n"
                  + "TYPE: " + chess_piece_type + "\n";
    return str;
  }
};



#endif /* piece */
