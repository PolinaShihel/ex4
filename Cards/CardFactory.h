#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Dragon.h"
#include "Cards/Gang.h"

#include <string>
#include <vector>

class CardFactory {
public:
	virtual Card* create() const = 0;

	///*
	//* Assignment operator of CardFactory class.
	//*
	//* @param reference to a CardFactory object.
	//*@return
	//*      reference to a CardFactory object.
	//*/
	//CardFactory& operator=(const CardFactory& other) = default;
};

class BarfightFactory : public CardFactory {
public:
	Barfight* create() const override 
	{
		return new Barfight;
	}
};

class DragonFactory : public CardFactory {
public:
	Dragon* create() const override
	{
		return new Dragon;
	}
};

class FairyFactory : public CardFactory {
public:
	Fairy* create() const override
	{
		return new Fairy;
	}
};

class GangFactory : public CardFactory {
public:
	Gang* create() const override
	{
		return new Gang();
	}
};

class GoblinFactory : public CardFactory {
public:
	Goblin* create() const override
	{
		return new Goblin;
	}
};

class MerchantFactory : public CardFactory {
public:
	Merchant* create() const override
	{
		return new Merchant;
	}
};

class PitfallFactory : public CardFactory {
public:
	Pitfall* create() const override
	{
		return new Pitfall;
	}
};

class TreasureFactory : public CardFactory {
public:
	Treasure* create() const override
	{
		return new Treasure;
	}
};

class VampireFactory : public CardFactory {
public:
	Vampire* create() const override
	{
		return new Vampire;
	}
};

#endif //CARDFACTORY_H