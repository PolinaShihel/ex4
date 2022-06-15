#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"

class BattleCard : public Card {
public:
    BattleCard(const std::string& name) : Card(name) {}

protected:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - current player.
     * @return
     *      void
     */
    virtual void applyEncounter(Player& player) const override;
    
    /*
    * Prints additional details of card
    *
    * @param os - reference to the stream the card will be printed to.
    * @return
    *      void
    */
    virtual void printAdditionalDetails(std::ostream& os) const override;
    
    /*
    * Hurts the player when losing to a battle card
    */
    virtual void onLost(Player& player) const = 0;

    /*
     * Returns the force of the monster represented by the current card
     */
    virtual int getMonsterForce() const = 0;
    
    /*
     * Returns the loot of the monster represented by the current card
     */
    virtual int getMonsterLoot() const = 0;
    
    /*
     * Returns the damage of the monster represented by the current card
     */
    virtual int getMonsterDamage() const = 0;
};

#endif //BATTLE_CARD_H