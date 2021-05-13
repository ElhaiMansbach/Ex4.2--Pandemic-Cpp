#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::treat(City c)
{
    if (current_city != c)
    {
        throw invalid_argument{"Error!!!: You are not in the city " + get_city(c)};
    }
    if (board.get_disease_level(c) <= 0)
    {
        throw invalid_argument("Error!!!: There is no disease in the city");
    }
    board.set_disease_level(c, 0);
    return *this;
}

Player &Medic::drive(City c)
{
    if (board.cure[cities_colors.at(c)])
    {
        board.set_disease_level(c, 0);
    }
    return Player::drive(c);
}

Player &Medic::fly_direct(City c)
{
    if (board.cure[cities_colors.at(c)])
    {
        board.set_disease_level(c, 0);
    }
    return Player::fly_direct(c);
}

Player &Medic::fly_charter(City c)
{
    if (board.cure[cities_colors.at(c)])
    {
        board.set_disease_level(c, 0);
    }
    return Player::fly_charter(c);
}

Player &Medic::fly_shuttle(City c)
{
    if (board.cure[cities_colors.at(c)])
    {
        board.set_disease_level(c, 0);
    }
    return Player::fly_shuttle(c);
}
