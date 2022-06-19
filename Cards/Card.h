#ifndef Card_H
#define Card_H

#include <string>
#include <iostream>
#include <set>
#include "../utilities.h"

static const std::string VAMPIRE_CARD_NAME = "Vampire";
static const std::string GOBLIN_CARD_NAME = "Goblin";
static const std::string DRAGON_CARD_NAME = "Dragon";
static const std::string FAIRY_CARD_NAME = "Fairy";
static const std::string BARFIGHT_CARD_NAME = "Barfight";
static const std::string PITFALL_CARD_NAME = "Pitfall";
static const std::string TREASURE_CARD_NAME = "Treasure";
static const std::string MERCHANT_CARD_NAME = "Merchant";

const int HEALTH_POINTS_TO_INCREASE = 10;

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
    virtual ~Card() = default;

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
     * @param player - current player.
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
    friend std::ostream& operator<<(std::ostream& os, const Card& CardType);

    /*
    * Prints additional details of card, if they exist
    *
    * @param os - reference to the stream the card will be printed to.
    * @return
    *      void
    */
    virtual void printAdditionalDetails(std::ostream& os) const
    {}

    std::string m_name;
};


#endif //Card_H