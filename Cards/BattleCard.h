#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"

class BattleCard : public Card {
public:
    /*
     * C'tor of BattleCard class
     *
     * @param name - the name of the card.
     * @param force - monster's force.
     * @param loot - monster's loot.
     * @param damage - monster's damage.
     * @return
     *      A new instance of BattleCard.
    */
    BattleCard(const std::string& name, int force, int loot, int damage);

    /*
     * D'tor of BattleCard class.
     */
    virtual ~BattleCard() {};

    /*
    * Assignment operator of BattleCard class.
    *
    * @param reference to a BattleCard object.
    *@return
    *      reference to a BattleCard object.
    */
    BattleCard& operator=(const BattleCard& other) = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - current player.
     * @return
     *      void
     */
    virtual void applyEncounter(Player& player) const override;

    /*
    * Hurts the player when losing to a battle card
    */
    virtual void onLost(Player& player) const = 0;

    /*
    * Prints additional details of card
    *
    * @param os - reference to the stream the card will be printed to.
    * @return
    *      void
    */
    virtual void printAdditionalDetails(std::ostream& os) const override;

    virtual std::string getMonsterName() const
    {
        return m_name;
    }

    virtual int getMonsterForce() const
    {
        return m_force;
    }

    virtual int getMonsterLoot() const
    {
        return m_loot;
    }

protected:
    int m_force;
    int m_loot;
    int m_damage;
};

#endif //BATTLE_CARD_H