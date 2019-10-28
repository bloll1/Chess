#include <string>
#include "interface.h"
#include <array>
#include <iostream>

std::string new_game() {
  std::string player;
  std::cout << "Who Goes First? Black or White" << '\n';
  player = read();
  while (checkStart(player) == 0) {
    std::cout << "Who Goes First? Black or White" << '\n';
    player = read();
  }
  return player;
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
