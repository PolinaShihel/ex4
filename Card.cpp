#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats)
{
}

/*
 * Function handles the changes made to the player in case of enounter with battle card
 *
 * @param player - Player object on which the changes are to be made.
 * @param stats   - The stats of the battle card played.
 * @return
 *      void.
 */
static void battleEncounter(Player& player, const CardStats& stats)
{
    if (stats.force <= player.getAttackStrength()) {
        printBattleResult(true);
        player.addCoins(stats.loot);
        player.levelUp();
        return;
    }
    printBattleResult(false);
    player.damage(stats.hpLossOnDefeat);
}

/*
 * Function handles the changes to  be made to player when met with buff card
 *
 * @param player - Player object on which the changes are to be made.
 * @param stats   - The stats of the buff card played.
 * @return
 *      void.
 */
static void buffEncounter(Player& player, const CardStats& stats)
{
    if(player.pay(stats.cost))
    {
        player.buff(stats.buff);
    }
}

/*
 * Function handles the changes to  be made to player when met with heal card
 *
 * @param player - Player object on which the changes are to be made.
 * @param stats   - The stats of the heal card played.
 * @return
 *      void.
 */
static void healEncounter(Player& player, const CardStats& stats)
{
    if(player.pay(stats.cost))
    {
        player.heal(stats.heal);
    }
}

/*
 * Function handles the changes to  be made to player when met with treasure card
 *
 * @param player - Player object on which the changes are to be made.
 * @param stats   - The stats of the treasure card played.
 * @return
 *      void.
 */
static void treasureEncounter(Player& player, const CardStats& stats)
{
    player.addCoins(stats.loot);
}

void Card::applyEncounter(Player& player) const
{
    switch (this->m_effect) {
        case(CardType::Battle):
            battleEncounter(player, this->m_stats);
            return;
        case(CardType::Buff):
            buffEncounter(player, this->m_stats);
            return;
        case(CardType::Heal):
            healEncounter(player, this->m_stats);
            return;
        case(CardType::Treasure):
            treasureEncounter(player, this->m_stats);
    }
}

void Card::printInfo() const
{
    switch (this->m_effect) {
        case(CardType::Battle):
            printBattleCardInfo(this->m_stats);
            return;
        case(CardType::Buff):
            printBuffCardInfo(this->m_stats);
            return;
        case(CardType::Heal):
            printHealCardInfo(this->m_stats);
            return;
        case(CardType::Treasure):
            printTreasureCardInfo(this->m_stats);
            return;
    }
}
