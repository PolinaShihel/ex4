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
		if (player.getAttackStrength() >= currentMonsterCard->getMonsterForce())
        {
			player.addCoins(currentMonsterCard->getMonsterLoot());
        }
		else{
           break;
        }
	}

	if (i == m_gangMembers.size()) {
        printWinBattle(player.getName(),GANG_CARD_NAME);
		player.levelUp();
	}

	while (i < m_gangMembers.size())
	{
        printLossBattle(player.getName(), m_gangMembers[i].get()->getMonsterName());
		m_gangMembers[i].get()->onLost(player);
		++i;
	}
}

void Gang::addMonsterToGang(const string& monsterName)
{
    m_gangMembers.emplace_back(
		unique_ptr<BattleCard>(dynamic_cast<BattleCard*>(getCardFactory(monsterName)->create())));
}
