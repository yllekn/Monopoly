#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "constants.hpp"
#include "board.hpp"

class Player {
    public:
        void PrintAllPlayerInfo(std::vector<Property> &deeds) {
            std::cout << "-- " << name << "'s Info" << std::endl;
            PrintPlayerMoney();
            PrintPlayerOwnedProperties(deeds);
            std::cout << "Color sets: " << std::endl;
            // BR [ ][X]
        }

        void PrintPlayerMoney() {
            std::cout << name << "'s Money: $" << money << std::endl;
        }

        void PrintPlayerOwnedProperties(std::vector<Property> &deeds) {
            std::cout << name << "'s properties: " << std::endl;
            for (int i = 0; i < NUM_PROPERTIES; i++) {
                if (properties[i] == owned) {
                    deeds[i].PrintDeedAbbrev();
                    std::cout << std::endl;
                }
            }
            std::cout << std::endl;
            std::cout << "Mortgaged: " << std::endl;
            for (int i = 0; i < NUM_PROPERTIES; i++) {
                if (properties[i] == mortgaged) {
                    std::cout << "- ";
                    deeds[i].PrintDeedAbbrev();
                    std::cout << std::endl;
                }
            }
        }

        void PayPlayer(int amount) {

        }

        void ChargePlayer (int amount) {

        }

        // CONSTRUCTOR: initialize Player data
        Player (std::string player_name) {
            name = player_name;
            money = 1500;
            num_owned = 0;
            // Initialize 'properties' array
            for (int i = 0; i < NUM_PROPERTIES; i++) {
                properties[i] = not_owned;
            }
        }

    private:
        std::string name;
        int money;
        int num_owned;
        property_status properties[NUM_PROPERTIES];
};

#endif