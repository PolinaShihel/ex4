#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

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
	/*
	* "Virtual C'tor" of Card class
	*/
	virtual Card* create() const = 0;
    virtual ~CardFactory() {};
};

class BarfightFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Barfight
	*/
	Barfight* create() const override 
	{
		return new Barfight;
	}

    ~BarfightFactory() override = default;

};

class DragonFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Dragon
	*/
	Dragon* create() const override
	{
		return new Dragon;
	}
    ~DragonFactory() override = default;
};

class FairyFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Fairy
	*/
	Fairy* create() const override
	{
		return new Fairy;
	}

    ~FairyFactory() override = default;
};

class GangFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Gang
	*/
	Gang* create() const override
	{
		return new Gang();
	}

    ~GangFactory() override = default;
};

class GoblinFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Goblin
	*/
	Goblin* create() const override
	{
		return new Goblin;
	}

    ~GoblinFactory() override = default;
};

class MerchantFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Merchant
	*/
	Merchant* create() const override
	{
		return new Merchant;
	}

    ~MerchantFactory() override = default;
};

class PitfallFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Pitfall
	*/
	Pitfall* create() const override
	{
		return new Pitfall;
	}
    ~PitfallFactory() override = default;
};

class TreasureFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Treasure
	*/
	Treasure* create() const override
	{
		return new Treasure;
	}

    ~TreasureFactory() override = default;
};

class VampireFactory : public CardFactory {
public:
	/*
	* Returns a new instance of Vampire
	*/
	Vampire* create() const override
	{
		return new Vampire;
	}

    ~VampireFactory() override = default;
};

#endif //CARD_FACTORY_H