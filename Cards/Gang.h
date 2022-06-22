#ifndef GANG_H
#define GANG_H

#include "Card.h"
#include "BattleCard.h"
#include <string>
#include <vector>
#include <memory>

const std::string GANG_CARD_NAME = "Gang";
const std::string END_GANG_MESSAGE = "EndGang";
const int INITIAL_CARD = 0;


class Gang : public Card {
public:
	/*
	 * C'tor of Gang class
	 *
	 * @return
	 *      A new instance of Gang.
	*/
	Gang() : Card(GANG_CARD_NAME)
	{}

	/*
	* D'tor of Gang class.
	*/
	~Gang() override = default;

	/*
	* Copy C'tor of Gang class
	*/
    Gang(const Gang &other);

	/*
	 * Clones a Gang object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Gang.
	*/
	virtual Gang* Clone() const override;

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	virtual void applyEncounter(Player& player) const override;

	void addMonsterToGang(const std::string& monsterName);

private:
	std::vector<std::unique_ptr<BattleCard>> m_gangMembers;
};


#endif //GANG_H