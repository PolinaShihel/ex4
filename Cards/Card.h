#ifndef Card_H
#define Card_H

#include <string>
#include <iostream>
#include <set>
#include "Exception.h"
#include "Players/Player.h"
#include "utilities.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::set;

const string VAMPIRE_CARD_NAME = "Vampire";
const string GOBLIN_CARD_NAME = "Goblin";
const string DRAGON_CARD_NAME = "Dragon";
const string FAIRY_CARD_NAME = "Fairy";
const string BARFIGHT_CARD_NAME = "Barfight";
const string PITFALL_CARD_NAME = "Pitfall";
const string TREASURE_CARD_NAME = "Treasure";
const string MERCHANT_CARD_NAME = "Merchant";

const string* CARDS_OFFICIAL_NAMES = new string[] {
        VAMPIRE_CARD_NAME, GOBLIN_CARD_NAME, DRAGON_CARD_NAME,
        FAIRY_CARD_NAME, BARFIGHT_CARD_NAME, PITFALL_CARD_NAME,
        TREASURE_CARD_NAME, MERCHANT_CARD_NAME
};

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param name - the name of the card.
     * @return
     *      A new instance of Card.
    */
    Card(const string& name);

    /*
     * D'tor of Card class.
     */
    virtual ~Card() {};

    /*
    * Assignment operator of Card class.
    *
    * @param reference to a Card object.
    *@return
    *      reference to a Card object.
    */
    Card& operator=(const Card& other) = default;
    
    /*
    * Virtual Copy C'tor of Card class
    */
    virtual Card* Clone() const = 0;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;
    
    /*
    * Assignment operator of Card class.
    *
    * @param reference to a Card object.
    *@return
    *      reference to a Card object.
    *
    */
    friend ostream& operator<<(ostream& os, const Card& card);

protected:
    virtual void printAdditionalDetails(ostream& os) const;

private:
    string m_name;
};


#endif //Card_H