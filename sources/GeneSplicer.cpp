#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

Player &GeneSplicer::discover_cure(Color color)
{
    if (!board.is_research_stations(current_city))
    {
        throw invalid_argument("Error!!!: There is no research station in the city");
    }
    if (board.get_cure(color))
    {
        return *this;
    }
    const int min = 5;
    if (cards.size() < min)
    {
        throw invalid_argument("Error!!!: You don't have enough cards");
    }
    cards.erase(cards.begin(),cards.begin()+min);
    board.cure[color] = true;
    return *this;
}