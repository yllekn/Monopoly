// UI, RNG, doubles, jail
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "board.hpp"

#include "player.hpp"

int StartSequence(std::string * const player_names);
void LoadProperties(std::vector<Property> &deeds, std::vector<PropertyType> &property_types);
void InitBoard(int num_players, Player * players);

#endif