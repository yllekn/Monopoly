// UI, RNG, doubles, jail
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "board.hpp"

#include "player.hpp"

int StartSequence(std::string * const player_names);
void InitBoard(int num_players, Player * players);
void LoadProperties(std::vector<Property> &deeds);

#endif