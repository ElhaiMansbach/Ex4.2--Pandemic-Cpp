#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (current_city == c)
    {
        throw invalid_argument{"Error!!! you are in this city"};
    }
    if (board.is_research_stations(current_city))
    {
        current_city = c;
        return *this;
    }
        return Player::fly_direct(c);
}