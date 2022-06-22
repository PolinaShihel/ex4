#ifndef Card_H
#define Card_H

#include <iostream>
#include <cstring>
#include <set>
#include "../utilities.h"
#include <algorithm>

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
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

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