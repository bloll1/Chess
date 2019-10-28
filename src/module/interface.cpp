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
  if (p == 1) {
    return "B";
  } else {
    return "W";
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

std::string oturn() {
  std::cout << "Move Peice from Position: ";
  std::string move = read();
  return move;
}

std::string nturn() {
  std::cout << "To: ";
  std::string move = read();
  return move;
}
