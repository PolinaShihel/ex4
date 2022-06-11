#ifndef Card_H
#define Card_H

#include <string>
#include <iostream>
#include <set>
#include "utilities.h"

const std::string VAMPIRE_CARD_NAME = "Vampire";
const std::string GOBLIN_CARD_NAME = "Goblin";
const std::string DRAGON_CARD_NAME = "Dragon";
const std::string FAIRY_CARD_NAME = "Fairy";
const std::string BARFIGHT_CARD_NAME = "Barfight";
const std::string PITFALL_CARD_NAME = "Pitfall";
const std::string TREASURE_CARD_NAME = "Treasure";
const std::string MERCHANT_CARD_NAME = "Merchant";

const std::set<std::string> CARDS_OFFICIAL_NAMES = {
        VAMPIRE_CARD_NAME, GOBLIN_CARD_NAME, DRAGON_CARD_NAME,
        FAIRY_CARD_NAME, BARFIGHT_CARD_NAME, PITFALL_CARD_NAME,
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
    Card(const std::string& name);

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
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

protected:
    /*
    * Prints additional details of card, if they exist
    *
    * @param os - reference to the stream the card will be printed to.
    * @return
    *      void
    */
    virtual void printAdditionalDetails(std::ostream& os) const;

    std::string m_name;
};


#endif //Card_H