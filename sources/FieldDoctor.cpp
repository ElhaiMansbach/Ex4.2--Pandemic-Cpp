#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    if (!Board::Neighbors(current_city, c) && current_city != c)
    {
        throw invalid_argument{"Error!!!: You are not in one of the neighboring cities"};
    }
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