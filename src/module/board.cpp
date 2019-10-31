
#include "board.h"
#include <sstream>
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
      //std::cout << board.piec[i]->toString();
  }

}

Chess_board movePiece(Chess_board board, std::string oldMove, std::string newMove, std::string player) {
    std::string pos;
    Chess_board new_board = board;
    std::string taken = searchPlayerType(board,newMove);
  for (int i = 0; i < (int)board.piec.size(); i++) {
     pos = new_board.piec[i]->position[0] + new_board.piec[i]->position[1];
     if (oldMove == pos) {
       if (taken != player && taken != "NULL") {
         new_board.piec.erase(new_board.piec.begin()+i);
       }
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
       return board.piec[i]->chess_piece_type;
     }
  }
  return "NULL";
}

std::string searchPlayerType(Chess_board board, std::string move) {
  std::string pos;
  for (int i = 0; i < (int)board.piec.size(); i++) {
     pos = board.piec[i]->position[0] + board.piec[i]->position[1];
     if (move == pos) {
       return board.piec[i]->player;
     }
  }
  return "NULL";
}


bool canMove(Chess_board board, std::string oldMove, std::string newMove, std::string player) {
  //piece_type and taken are used to check if the position has a piece and
  //the next position is empty. TODO: check if the piece can legally move there
  std::string player_type = searchPlayerType(board, oldMove);
  //std::cout << "PLAYER_TYPE: " << player_type << '\n';
  std::string piece_type = searchPieceType(board,oldMove);
  //std::cout << "PIECE TYPE: " << piece_type << '\n';

  std::string taken = searchPlayerType(board,newMove);
  //std::cout << "TAKEN: " << taken << '\n';

  if (player_type != player || piece_type == "NULL" ||
    taken == player || !legalPieceMove(board, oldMove, newMove, player)) {
    return true;
  }
  return false;
}


std::string translateAddress(std::string oldMove, std::string newMove) {
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
  std::string oX(1, oldMove[0]);
  std::string oY(1, oldMove[1]);
  std::string nX(1, newMove[0]);
  std::string nY(1, newMove[1]);
  //std::cout << "BEFORE ADDRESS TRANSLATION: "  << oX << oY << nX << nY << '\n';
  int oldX;
  int oldY;
  int newX;
  int newY;
  for (int i = 0; i < 8; i++) {
    if (nX == position_x[i]) {
      newX = i;
    } if (nY == position_y[i]) {
      newY= i;
    } if (oX == position_x[i]) {
      oldX= i;
    } if (oY == position_y[i]) {
      oldY= i;
    }
  }
  //std::cout << "AFTER ADDRESS TRANSLATION: "  << (std::to_string(oldX) + std::to_string(oldY) + std::to_string(newX) + std::to_string(newY)) << "\n";
  return (std::to_string(oldX) + " " + std::to_string(oldY) + " " + std::to_string(newX) + " " + std::to_string(newY));
}

bool legalPawnMove(Chess_board board, std::string oldMove, std::string newMove, std::string player) {
  std::stringstream ss(translateAddress(oldMove, newMove));
  int oldX, oldY, newX, newY, changeY, changeX;

  ss >> oldX;
  ss >> oldY;
  ss >> newX;
  ss >> newY;
  changeX = oldX - newX;
  changeY = oldY - newY;
  //std::cout << "PAWN MOVE " << oldMove << " to " << newMove<< '\n';
  if (changeY == 0 || changeY > 1 || changeY < -1) {
    return false;
  } else if (changeX != 0){
    if ((changeX == 1 || changeX == -1) && searchPlayerType(board, newMove) != player) {
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
}

bool legalKnightMove(Chess_board board, std::string oldMove, std::string newMove) {
  std::stringstream ss(translateAddress(oldMove, newMove));
  int oldX, oldY, newX, newY;

  ss >> oldX;
//std::cout << "OLDX: " << oldX << '\n';
  ss >> oldY;
  //std::cout << "OLDY: " << oldY << '\n';
  ss >> newX;
  //std::cout << "NEWX: " << newX << '\n';
  ss >> newY;
  //std::cout << "NEWY: " << newY << '\n';

  if ((oldY - 2 == newY || oldY + 2 == newY) && (oldX + 1 == newX || oldX - 1 == newX)) {
    return true;
  } else if ((oldX - 2 == newX || oldX + 2 == newX) && (oldY + 1 == newY || oldY - 1 == newY)) {
    return true;
  } else  {
    return false;
  }
}

bool legalKingMove(Chess_board board, std::string oldMove, std::string newMove) {
  std::stringstream ss(translateAddress(oldMove, newMove));
  int oldX, oldY, newX, newY;

  ss >> oldX;
  ss >> oldY;
  ss >> newX;
  ss >> newY;

  if ((oldX - 1 == newX || oldX + 1 == newX || oldX == newX) &&
   (oldY - 1 == newY || oldY == newY || oldY + 1 == newY) && !(oldX == newX && oldY == newY)) {
     return true;
   } else {
     return false;
   }
}

bool legalRookMove(Chess_board board, std::string oldMove, std::string newMove) {
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
  std::stringstream ss(translateAddress(oldMove, newMove));
  int oldX, oldY, newX, newY, change;
  std::string taken;
  std::string newCheck;
  ss >> oldX;
  ss >> oldY;
  ss >> newX;
  ss >> newY;

  if (oldX != newX && oldY != newY) {
    return false;
  }
  if (oldX != newX) {
    if (oldX > newX) {
      change = oldX - newX;
      for (int i = 1; i < change; i++) {
        newCheck = position_x[oldX - i] + position_y[oldY];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {
          return false;
        }
      }
      return true;
    } else {
      change = newX - oldX;
      for (int i = 1; i < change; i++) {
        newCheck = position_x[oldX + i] + position_y[oldY];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {
          return false;
        }
      }
      return true;
    }
  } else {
    if (oldY > newY) {
      change = oldY - newY;
      for (int i = 1; i < change; i++) {
        newCheck = position_x[oldX] + position_y[oldY - i];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {
          return false;
        }
      }
      return true;
    } else {
      change = newY - oldY;
      for (int i = 1; i < change; i++) {
        newCheck = position_x[oldX] + position_y[oldY + i];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}


bool legalBishopMove(Chess_board board, std::string oldMove, std::string newMove) {
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
  std::stringstream ss(translateAddress(oldMove, newMove));
  int oldX, oldY, newX, newY, changeX;
  std::string taken;
  std::string newCheck;
  ss >> oldX;
  ss >> oldY;
  ss >> newX;
  ss >> newY;

  if (oldX == newX || oldY == newY) {
    return false;
  }
  if (oldX > newX) {
    if (oldY > newY) {
      if ((oldX - newX) != (oldY - newY)) {
        return false;
      }
      changeX = oldX - newX;
      for (int i = 1; i < changeX; i++) {
        newCheck = position_x[oldX - i] + position_y[oldY - i];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {
          return false;
        }
      }
      return true;

    } else {
      if ((oldX - newX) != (newY - oldY)) {
        return false;
      }
      changeX = oldX - newX;
      for (int i = 1; i < changeX; i++) {
        newCheck = position_x[oldX - i] + position_y[oldY + i];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {
          return false;
        }
      }
      return true;
    }

  } else {
    if (oldY > newY) {
      if ((newX - oldX) != (oldY - newY)) {
        return false;
      }
      changeX = newX - oldX;
      for (int i = 1; i < changeX; i++) {
        newCheck = position_x[oldX + i] + position_y[oldY - i];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {

          return false;
        }
      }
      return true;
    } else {
      if ((newX - oldX) != (newY - oldY)) {
        return false;
      }
      changeX = newX - oldX;
      for (int i = 1; i < changeX; i++) {
        newCheck = position_x[oldX + i] + position_y[oldY + i];
        taken = searchPlayerType(board,newCheck);
        if (taken != "NULL") {


          return false;
        }
      }
      return true;
    }
  }
  return false;
}


bool legalQueenMove(Chess_board board, std::string oldMove, std::string newMove) {
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
  std::stringstream ss(translateAddress(oldMove, newMove));
  int oldX, oldY, newX, newY;
  std::string taken;
  std::string newCheck;
  ss >> oldX;
  ss >> oldY;
  ss >> newX;
  ss >> newY;

  if (oldX == newX || oldY == newY) {
    return legalRookMove(board, oldMove, newMove);
  } else {
    return legalBishopMove(board, oldMove, newMove);
  }
}



bool legalPieceMove(Chess_board board, std::string oldMove, std::string newMove, std::string player) {
  std::string piece_type = searchPieceType(board,oldMove);
  if (piece_type == "pawn") {
      return legalPawnMove(board, oldMove, newMove, player);
  } else if (piece_type == "knight") {
      return legalKnightMove(board, oldMove, newMove);
  } else if (piece_type == "king") {
      return legalKingMove(board, oldMove, newMove);
  } else if (piece_type == "bishop") {
      return legalBishopMove(board, oldMove, newMove);
  } else if (piece_type == "queen") {
      return legalQueenMove(board, oldMove, newMove);
  } else if (piece_type == "rook") {
    return legalRookMove(board, oldMove, newMove);
  }
  return false;
}

bool canDelete(Chess_board board, std::string pos, std::string player, std::string piece) {

  std::cout << "CALLED canDelete" << '\n';
  std::cout << "canDelete: " << player << '\n';
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
    if (position_x[x] + position_y[x] != pos &&
          searchPieceType(board,position_x[x] + position_y[y]) == piece &&
            !canMove(board, pos, position_x[x] + position_y[y], player) &&
              searchPlayerType(board, position_x[x] + position_y[y]) != player) {
      std::cout << "Return True: X "<< x << " Y " << y << '\n';
      std::cout << "POS " << pos << '\n';
      return true;
    }
    }
  }
  return false;
}
// pass in the pos that the king wants to move and the white player
bool canMoveWithoutDelete(Chess_board board, std::string pos, std::string player) {
  std::cout << "CALLED canMoveWithoutDelete" << '\n';
  std::cout << "Player "<< player << '\n';
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      if (searchPieceType(board,position_x[x] + position_y[y]) != "NULL" &&
            searchPlayerType(board, position_x[x] + position_y[y]) == player &&
              !canMove(board, position_x[x] + position_y[y], pos, player)) {

              return false;
      }
    }
  }
  return true;
}



bool canKingMove(Chess_board board, std::string player) {
  std::cout << "CALLED canKingMove" << '\n';
  std::string position_x[8] = {"a","b","c","d","e","f","g","h"};
  std::string position_y[8] = {"1","2","3","4","5","6","7","8"};
  std::string players[] = {"white", "black"};
  int n;
  for (int i = 0; i < 2; i++) {
    if (players[i] != player) {
      n = i;
    }
  }
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {

      if (searchPieceType(board, position_x[x] + position_y[y]) == "king" &&
            searchPlayerType(board, position_x[x] + position_y[y]) == player) {
              std::cout << "Position of King: " << position_x[x] + position_y[y] << '\n';
              for (int xt = 0; xt < 3; xt++) {
                for (int yt = 0; yt < 3; yt++) {
                  if (xt + x != 0 && yt + y != 0 && yt != y &&
                        xt + x < 9 && yt + y < 9 && xt != x) {

                          std::cout << "TRANSLATION check: X " << position_x[x + xt -1] << " Y " << position_y[y + yt -1] << '\n';
                          if (!canMove(board, position_x[x] + position_y[y], position_x[x + xt -1] + position_y[y + yt -1], player) &&
                                canMoveWithoutDelete(board, position_x[x + xt -1] + position_y[y + yt -1], players[n])) {
                                  std::cout << "RETURNED TRUE" << '\n';
                                  return true;
                                }
                        }
                }
              }

      }
    }
  }
  return false;
}


int checkMate(Chess_board board, std::string player, std::string pos) {
  std::string players[] = {"white", "black"};
  int n;
  for (int i = 0; i < 2; i++) {
    if (players[i] != player) {
      n = i;
    }
  }

  if (canDelete(board,pos,players[n],"king") && canKingMove(board, player) != true) {

    return 1;
  } else {
    return 0;
  }
}
