// (EF) = expanded functionality-- future features

#include <iostream>
#include <string>
#include <vector>

#include "game.hpp"
#include "board.hpp"

int main () {
    
    // [[A]] Get num_players & player_names
    std::string player_names[4];
    int num_players = 0;
    while (num_players < 2 || num_players > 4) {
        num_players = StartSequence(player_names);
    }
    // FIXME: (EF) 2-4 players
    // else if (num_players < 2 || num_players > 4) {}

    // [[B]] Load property deeds into a vector "deeds"
    std::vector<Property> deeds;
    LoadProperties(deeds);
    deeds[0].PrintDeed();

    // [[C]] 
}