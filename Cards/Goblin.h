#ifndef GOBLIN_H
#define GOBLIN_H

#include "BattleCard.h"

const std::string GOBLIN_CARD_NAME = "Goblin";
static const int GOBLIN_FORCE = 6;
static const int GOBLIN_LOOT = 2;
static const int GOBLIN_DAMAGE = 10;

class Goblin : public BattleCard {
public:
	/*
	 * C'tor of Goblin class
	 *
	 * @param name - the name of the card ("Goblin").
	 * @return
	 *      A new instance of Goblin.
	*/
	Goblin();

	/*
	* D'tor of Goblin class.
	*/
	~Goblin() override = default;

	/*
	* Copy C'tor of Goblin class
	*/
	Goblin(const Goblin& other) = default;

	/*
	 * Clones a Goblin object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Goblin.
	*/
	Goblin* Clone() const override;

	/*
	 * Decrease player's health
	 *
	 * @return
	 *      void
	*/
	void onLost(Player& player) const override;
};


#endif //GOBLIN_H