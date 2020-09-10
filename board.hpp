// Property deeds, chance/community chest, taxes
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <string>
#include <sstream>

class Property {
    public:
        void PrintDeed() {  // TODO: test
            std::cout << "Property Name: " << name << std::endl;
            std::cout << "PRICE: $" << price << std::endl;
            std::cout << "Color set: " << color << ", " << size_of_color_set << " total properties" << std::endl << std::endl;
            
            std::cout << "Base rent: $" << rent_base << std::endl;
            std::cout << "Monopoly rent: $" << rent_monopoly << std::endl;
            std::cout << "With 1 house: $" << rent_1 << std::endl;
            std::cout << "With 2 houses: $" << rent_2 << std::endl;
            std::cout << "With 3 houses: $" << rent_3 << std::endl;
            std::cout << "With 4 houses: $" << rent_4 << std::endl;
            std::cout << "With 1 hotel: $" << rent_hotel << std::endl << std::endl;

            std::cout << "Cost per house: $" << house_cost << std::endl;
            std::cout << "Cost for hotel: $" << hotel_cost << " & 4 houses" <<  std::endl;
            std::cout << "Mortgaged value: $" << mortgage_value << std::endl << std::endl;
        }

        // Constructor
        Property (std::string name_str, std::string info_str, std::string rents_str) {
            name = name_str;
            std::istringstream iss;
            iss.str(info_str);
            iss >> color >> size_of_color_set >> price;
            iss.str(std::string());     // Reset & reuse stringstream
            iss.clear();
            iss.str(rents_str);
            iss >> rent_base >> rent_monopoly >> rent_1 >> rent_2 >> rent_3 >> rent_4 >> rent_hotel >> house_cost >> hotel_cost >> mortgage_value;
            num_houses = 0;
            num_hotels = 0;
            //TODO: idx_color_set?
        }

        // get values
        // buy houses
        // buy hotel (must have enough houses)

    private:
        // Property info-- TODO: how to ensure that everything is initialized? INIT ROUTINE
        std::string name;
        std::string color;
        int size_of_color_set;  // how many in the color set?
        int price;
        // int idx_color_set[2];   // FIXME: indicies of the other properties in the color set (necessary?)
        int rent_base;
        int rent_monopoly;
        int rent_1;     // own 1 house
        int rent_2;
        int rent_3;
        int rent_4;
        int rent_hotel;
        int house_cost;
        int hotel_cost;
        int mortgage_value;

        // User info
        // int owner_ID;
        // int current_worth;  // TODO: i.e. how do you buy properties off of other people?
        int num_houses;
        int num_hotels;
        ///int rent?
};

// TODO: print function for board, user info (e.g how much money)
// TODO: NEED GLOBAL COUNT FOR # HOUSES + HOTELS AVAILABLE
// TODO: NEED GLOBAL SCOREBOARD FOR MONEY

#endif