#include "Card.h"

using std::ostream;
using std::cout;
using std::endl;

Card::Card(const std::string& name) 
{
    m_name = name;
}

ostream& operator<<(ostream& os, const Card& CardType)
{
    printCardDetails(os, CardType.m_name);
    CardType.printAdditionalDetails(os);
    printEndOfCardDetails(os);
    return os;
}

