#include "BattleCard.h"
#include "BattleCard.h"
#include "BattleCard.h"

using std::ostream;

void BattleCard::applyEncounter(Player& player) const
{
	if (player.getAttackStrength() >= m_force) {
		player.levelUp();
		player.addCoins(m_loot);
	}
	else {
		onLost(player);
        printLossBattle(player.getName(), this->getMonsterName());
	}
}

BattleCard::BattleCard(const std::string& name, int loot, int force, int damage) :
	Card(name), m_loot(loot), m_force(force), m_damage(damage)
{
}

void BattleCard::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, m_force, m_damage, m_loot);
}
