#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"

class BattleCard : public Card {
public:
    BattleCard(const std::string& name) : Card(name) {}

protected:
    virtual void applyEncounter(Player& player) const override;
    virtual void afterLost(Player& player) const {};

protected:
    virtual int getMonsterForce() const = 0;
    virtual int getMonsterLoot() const = 0;
    virtual int getMonsterDamage() const = 0;
};

#endif //BATTLE_CARD_H