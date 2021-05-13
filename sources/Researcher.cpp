#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Player &Researcher::discover_cure(Color color)
{
    if (board.get_cure(color))
    {
        return *this;
    }
    int count = 0;
    for (auto e : cards)
    {
        if (Board::city_color(e) == color)
        {
            count++;
        }
    }
    const int min = 5;
    if (count < min)
    {
        throw invalid_argument("Error!!!: You don't have enough cards in the required color");
    }
    int stop = 0;
    for (auto i = cards.begin(); i != cards.end() && stop < 4; ++i)
    {
        City c = *i;
        if (Board::city_color(c) == color)
        {
            cards.erase(i);
            i--;
            stop++;
        }
    }
    board.cure[color] = true;
    return *this;
}