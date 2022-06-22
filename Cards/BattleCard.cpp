#include "BattleCard.h"

using std::ostream;

BattleCard::BattleCard(const std::string& name, int force, int loot, int damage) :
	Card(name), m_force(force), m_loot(loot), m_damage(damage)
{
}

void BattleCard::applyEncounter(Player& player) const
{
	if (player.getAttackStrength() >= m_force) {
		player.levelUp();
		player.addCoins(m_loot);
		printWinBattle(player.getName(), getMonsterName());
	}
	else {
		onLost(player);
        printLossBattle(player.getName(), getMonsterName());
	}
}

void BattleCard::printAdditionalDetails(std::ostream& stream) const
{
	printMonsterDetails(stream, m_force, m_damage, m_loot);
}
