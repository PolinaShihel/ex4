#include "Card.h"

using std::ostream;
using std::cout;
using std::endl;

Card::Card(const std::string& name) 
{
    m_name = name;
}

ostream& operator<<(ostream& os, const Card& card)
{
    printCardDetails(os, card.m_name);
    card.printAdditionalDetails(os);
    printEndOfCardDetails(os);
    return os;
}

void Card::printAdditionalDetails(ostream& os) const
{
    cout << endl;
}

