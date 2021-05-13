#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{

    if (current_city == c)
    {
        Player::treat(c);
        return *this;
    }
    if (count(cards.begin(), cards.end(), c) == 0)
    {
        throw invalid_argument("Error!!!: You don't have the card of the desired city");
    }
    auto it = find(cards.begin(), cards.end(), c);
    cards.erase(it);
    if (board.get_disease_level(c) <= 0)
    {
        throw invalid_argument("Error!!!: There is no disease in the city");
    }
    if (board.is_cure_discoverd(c))
    {
        board.set_disease_level(c, 0);
        return *this;
    }
    int num = board.get_disease_level(c);
    num--;
    board.set_disease_level(c, num);
    return *this;
}