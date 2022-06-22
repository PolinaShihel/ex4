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
	*/
	virtual Player* create(std::string playerName) const = 0;
};

class FighterFactory : public PlayerFactory {
public:
	/*
	* Returns a new instance of Fighter
	*/
	Fighter* create(std::string playerName) const override
	{
		return new Fighter(playerName);
	}
};

class RogueFactory : public PlayerFactory {
public:
	/*
	* Returns a new instance of Rogue
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
	*/
	Wizard* create(std::string playerName) const override
	{
		return new Wizard(playerName);
	}
};

#endif //PLAYER_FACTORY_H