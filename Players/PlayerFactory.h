#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "Player.h"
#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"

class PlayerFactory {
public:
	/*
	* "Virtual C'tor" of Player class
    * @param playerName - The name of the player to be assigned to the Player object
	*/
	virtual Player* create(std::string playerName) const = 0;
};

class FighterFactory : public PlayerFactory {
public:
	/*
	* Returns a new instance of Fighter
    * @param playerName - The name of the player to be assigned to the Fighter object
	*/
	Fighter* create(std::string playerName) const override
	{
		return new Fighter(playerName);
	}
};

class RogueFactory : public PlayerFactory {
public:
	/*
	* Returns a new instance of Rogue with the name that's been given
    * @param playerName - The name of the player to be assigned to the Rogue object
	*/
	Rogue* create(std::string playerName) const override
	{
		return new Rogue(playerName);
	}
};

class WizardFactory : public PlayerFactory {
public:
	/*
	* Returns a new instance of Wizard
    *@param playerName - The name of the player to be assigned to the Wizard object
	*/
	Wizard* create(std::string playerName) const override
	{
		return new Wizard(playerName);
	}
};

#endif //PLAYER_FACTORY_H