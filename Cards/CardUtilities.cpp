#include "CardUtilities.h"
#include <string>

using std::unique_ptr;
using std::string;
using std::map;

bool tryGetCardConstructor(const string& cardName, CardFactory** cardFactory)
{
    if (CARDS_NAMES_TO_FACTORIES.count(cardName)) {
        *cardFactory = CARDS_NAMES_TO_FACTORIES.at(cardName).get();
        return true;
    }

    return false;
}

CardFactory* getCardFactory(const string& cardName)
{
    CardFactory* cardFactory = nullptr;
    tryGetCardConstructor(cardName, &cardFactory);
    return cardFactory;
}

bool isBattleCard(const std::string& cardName)
{
    return cardName == DRAGON_CARD_NAME || 
        cardName == GOBLIN_CARD_NAME || 
        cardName == VAMPIRE_CARD_NAME;
}
