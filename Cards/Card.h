#ifndef Card_H
#define Card_H

#include <string>
#include <iostream>
#include <set>
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
const string Barfight_CARD_NAME = "Barfight";
const string PITFALL_CARD_NAME = "Pitfall";
const string TREASURE_CARD_NAME = "Treasure";
const string MERCHANT_CARD_NAME = "Merchant";

const set<string> CARDS_OFFICIAL_NAMES = {
        VAMPIRE_CARD_NAME, GOBLIN_CARD_NAME, DRAGON_CARD_NAME,
        FAIRY_CARD_NAME, Barfight_CARD_NAME, PITFALL_CARD_NAME,
        TREASURE_CARD_NAME, MERCHANT_CARD_NAME
};

const int HEALTH_POINTS_TO_INCREASE = 10;
const int DAMAGE = 10;

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
    * Print operator of Card class.
    *
    * @param os - reference to the stream the card will be printed to.
    * @param card - reference to the card that will be printed.
    * @return
    *      reference to an ostream.
    */
    friend ostream& operator<<(ostream& os, const Card& card);

protected:
    /*
    * Prints additional details of card, if they exist
    *
    * @param os - reference to the stream the card will be printed to.
    * @return
    *      void
    */
    virtual void printAdditionalDetails(ostream& os) const;

private:
    string m_name;
};


#endif //Card_H