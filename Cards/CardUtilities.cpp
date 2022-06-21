#include "CardUtilities.h"
#include <string>

using std::unique_ptr;
using std::string;
using std::map;

bool tryGetCardConstructor(const string& cardName, CardFactory* cardFactory)
{
    map<string, unique_ptr<CardFactory>> cardsNamesToFactories;
    cardsNamesToFactories[BARFIGHT_CARD_NAME] = unique_ptr<BarfightFactory>();
    cardsNamesToFactories[DRAGON_CARD_NAME] = unique_ptr<DragonFactory>();
    cardsNamesToFactories[FAIRY_CARD_NAME] = unique_ptr<FairyFactory>();
    cardsNamesToFactories[GANG_CARD_NAME] = unique_ptr<GangFactory>();
    cardsNamesToFactories[GOBLIN_CARD_NAME] = unique_ptr<GoblinFactory>();
    cardsNamesToFactories[MERCHANT_CARD_NAME] = unique_ptr<MerchantFactory>();
    cardsNamesToFactories[PITFALL_CARD_NAME] = unique_ptr<PitfallFactory>();
    cardsNamesToFactories[TREASURE_CARD_NAME] = unique_ptr<TreasureFactory>();
    cardsNamesToFactories[VAMPIRE_CARD_NAME] = unique_ptr<VampireFactory>();

    if (cardsNamesToFactories.count(cardName)) {
        cardFactory = cardsNamesToFactories.at(cardName).get();
        return true;
    }

    return false;
}

CardFactory* getCardFactory(const string& cardName)
{
    CardFactory* cardFactory;
    tryGetCardConstructor(cardName, cardFactory);
    return cardFactory;
}

bool isBattleCard(const std::string& cardName)
{
    return cardName == DRAGON_CARD_NAME || 
        cardName == GOBLIN_CARD_NAME || 
        cardName == VAMPIRE_CARD_NAME;
}
