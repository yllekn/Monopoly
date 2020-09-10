#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>

#include "player.hpp"
#include "board.hpp"
#define NUM_PROPERTIES 28

// FUNCTION StartSequence(): Get # of players, players' names, and confirm info.
int StartSequence(std::string * const player_names) {
    // FIXME: (EF) Make StartSequence() flexible to accommodate 2-4 players. (Currently only 2 players allowed.)

    int num_players = 2;
    std::cout << std::endl << "* * * * * PLEASE ENTER PLAYER INFO * * * * *" << std::endl; 

    // Player 1
    std::cout << std::endl << "-- Enter Player 1's name." << std::endl;
    while (!std::getline(std::cin, player_names[0])) {   // I/O error
        std::cout << "Please enter a valid name" << std::endl;
    }
    while (player_names[0].empty()) {    // check for empty name
        std::cout << "Please enter a valid name" << std::endl;
    }

    // Player 2
    std::cout << std::endl << "--Enter Player 2's name." << std::endl;
    while (!std::getline(std::cin, player_names[1])) {   // I/O error
        std::cout << "Please enter a valid name" << std::endl;
    }
    while (player_names[1].empty()) {    // check for empty name
        std::cout << "Please enter a valid name" << std::endl;
    }

    // CONFIRM USER INPUT 
    char confirm;
    do {
        std::cout << std::endl << "Confirm that the following is correct (type \"y\" or \"n\"):" << std::endl;
        for (int i = 0; i < num_players; i++) {
            std::cout << i + 1 << ". " << player_names[i] << std::endl;
        }
        std::cout << std::endl;
        std::cin >> confirm;    // Get first char
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Ignore rest of line
    }
    while (!std::cin.fail() && confirm != 'y' && confirm != 'n');

    // 1) User wants to change player info.
    if (confirm == 'n') {
        return -1;
    }

    // 2) User accepts player info.
    std::cout << std::endl << "* * * * * Player info accepted. LET'S PLAY! * * * * *" << std::endl << std::endl;
    return 2;
}

void LoadProperties(std::vector<Property> &deeds) {
    std::string name;
    std::string info;
    std::string rents;
    std::ifstream deeds_file("deeds.txt");
    for (int i = 0; i < NUM_PROPERTIES; i++) {
        // 1) Read in property name
        while (std::getline(deeds_file, name)) {
            if (!name.empty()) break;  // Ignore empty lines
        }
        // 2) Read in color, # color set members, and price
        while (std::getline(deeds_file, info)) {
            if (!info.empty()) break;  // Ignore empty lines
        }
        // 3) Read in rent prices
        while (std::getline(deeds_file, rents)) {
            if (!rents.empty()) break;  // Ignore empty lines
        }
        Property property(name, info, rents);
        deeds.push_back(property);  // dynamic allocation
    }
    deeds_file.close();
}

// FUNCTION InitBoard(): Reads in property deed info from deeds.txt
void InitBoard(int num_players, Player * players) {
    
}

