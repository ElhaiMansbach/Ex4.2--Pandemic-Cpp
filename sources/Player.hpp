
#pragma once
#include "City.hpp"
#include "Board.hpp"

namespace pandemic
{
    class Player
    {
    protected:
        Board &board;
        City current_city;
        std::vector<City> cards;
        std::string player_role;

    public:
        Player(Board &b, City c, std::string r) : board(b), current_city(c), player_role(r) {}

        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);

        Player &take_card(City c);
        std::string role();
        void remove_cards();
    };
}