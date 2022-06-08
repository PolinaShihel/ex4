#include "Card.h"

Card::Card(const string& name) 
{
    if (!Player::checkName(name)) {
        throw InvalidCardName("An invalid name has been entered for the current card");
    }
    m_name = name;
}