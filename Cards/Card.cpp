#include "Card.h"

Card::Card(const string& name) 
{
    if (name.length() > MAX_LENGTH || std::count(name.begin(), name.end(), ILLEGAL_SPACE)) {
        throw InvalidCardName("An invalid name has been entered for the current card");
    }
    
    m_name = name;
}

friend ostream& operator<<(ostream& os, const Card& card)
{
    printCardDetails(os, card.m_name);
    card.printAdditionalDetails(os);
    printEndOfCardDetails(os);
}

virtual void printAdditionalDetails(ostream& os) const
{
}