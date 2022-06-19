#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"

class BattleCard : public Card {
public:
    BattleCard(const std::string& name, int force, int loot, int damage);

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

    virtual std::string getMonsterName() const = 0;
    
private:
    /*
    * Hurts the player when losing to a battle card
    */
    virtual void onLost(Player& player) const = 0;

protected:
    int m_force;
    int m_loot;
    int m_damage;
};

#endif //BATTLE_CARD_H