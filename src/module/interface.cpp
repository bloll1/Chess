#include <string>
#include "interface.h"
#include <array>
#include <iostream>

std::string new_game() {
  std::string player;
  std::cout << "Who Goes First? Black or White" << '\n';
  player = read();
  int p = checkStart(player);
  while (p == 0) {
    std::cout << "Who Goes First? Black or White" << '\n';
    player = read();
    p = checkStart(player);
  }
  std::cout << '\n';
  if (p == 1) {
    return "white";
  } else {
    return "black";
  }
}



std::string read() {
  std::string prompt;
  std::cin >> prompt;
  return prompt;
}

int checkStart(std::string player) {
  std::string possible_b[] = {"b",  "BLACK",  "black", "Black"};
  std::string possible_w[] = {"w", "WHITE", "white", "White"};

  for (int i = 0 ; i < 4; i++) {
    if (possible_b[i] == player) {
      return 1;
    }
    if (possible_w[i] == player) {
      return 2;
    }
  }
  return 0;
}



std::string oturn(int turn) {
  if (turn) {
    std::cout << "Black's turn" << '\n';
  } else {
    std::cout << "White's turn" << '\n';
  }
  std::cout << "Move Peice from Position: ";
  std::string move = read();
  return move;
}

std::string nturn() {
  std::cout << "To: ";
  std::string move = read();
  return move;
}
