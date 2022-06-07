#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include <iostream>
#include "Exception.h"
#include "Player.h"
#include "utilities.h"

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(const string& name);
    virtual Card* Clone();
    virtual ~Card();
    /*virtual?*/ Card& operator=(const Card& other) /*= default*/;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;
    
    virtual friend ostream& operator<<(ostream& os, const Card& card);

private:
    string m_name;
};


#endif //EX2_Card_H