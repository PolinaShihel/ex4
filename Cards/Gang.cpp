#include "Gang.h"
#include "CardUtilities.h"

using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;

Gang* Gang::Clone() const
{
	return new Gang(*this);
}

void Gang::applyEncounter(Player& player) const
{
	BattleCard* currentMonsterCard;
	unsigned int i;
	for (i = 0; i < m_gangMembers.size(); ++i) {
		currentMonsterCard = m_gangMembers[i].get();
		if (player.getAttackStrength() >= currentMonsterCard->getMonsterForce()) {
			player.addCoins(currentMonsterCard->getMonsterLoot());
		}
	}

	if (i == m_gangMembers.size()) {
		player.levelUp();
	}

	while (i < m_gangMembers.size())
	{
		m_gangMembers[i].get()->onLost(player);
		++i;
	}
}

void Gang::addMonsterToGang(const string& monsterName)
{
	//m_gangMembers.push_back(make_unique<BattleCard>(getCardFactory(monsterName)->create()));
}
