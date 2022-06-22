#include "Card.h"

using std::ostream;
using std::cout;
using std::endl;

Card::Card(const std::string& name)
{
    m_name = name;
}

ostream& operator<<(ostream& stream, const Card& card)
{
    printCardDetails(stream, card.m_name);
    card.printAdditionalDetails(stream);
    printEndOfCardDetails(stream);
    return stream;
}

