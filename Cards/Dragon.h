#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"


static const int DRAGON_FORCE = 25;
static const int DRAGON_LOOT = 1000;
static const int DRAGON_DAMAGE = INITIAL_MAX_HP;

class Dragon : public BattleCard {
public:
	/*
	 * C'tor of Dragon class
	 *
	 * @param name - the name of the card ("Dragon").
	 * @return
	 *      A new instance of Dragon.
	*/
	Dragon();
	
	/*
	* D'tor of Dragon class.
	*/
	~Dragon() override = default;
	
	/*
	* Copy C'tor of Dragon class
	*/
	Dragon(const Dragon& name) = default;
	
	/*
	 * Clones a Dragon object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Dragon.
	*/
	Dragon* Clone() const override;

    virtual std::string getMonsterName() const override;

private:
	/*
	 * "Burns" the player
	 *
	 * @return
	 *      void
	*/
	void onLost(Player& player) const override;

	/*
	* Prints additional details of card
	*
	* @param os - reference to the stream the card will be printed to.
	* @return
	*      void
	*/
	void printAdditionalDetails(std::ostream& os) const override;
};


#endif //DRAGON_H