#include "Gang.h"
#include "CardUtilities.h"

using std::string;
using std::vector;
using std::unique_ptr;

Gang::Gang(const Gang &other) : Card(other)
{
    for(std::vector<std::unique_ptr<BattleCard>>::const_iterator it = other.m_gangMembers.begin();
    it != other.m_gangMembers.end(); ++it) {
        m_gangMembers.push_back(std::unique_ptr<BattleCard>((BattleCard *) it->get()->Clone()));
    }
}

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
    m_gangMembers.emplace_back(std::unique_ptr<BattleCard>(dynamic_cast<BattleCard*>(getCardFactory(monsterName)->create())));
    //m_gangMembers.push_back((std::unique_ptr<BattleCard>(dynamic_cast<BattleCard*>(getCardFactory(monsterName)->create()))));
}
