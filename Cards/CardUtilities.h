#ifndef CARD_UTILITIES_H
#define CARD_UTILITIES_H

#include "CardFactory.h"
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <set>

const std::map<std::string, std::shared_ptr<CardFactory>> CARDS_NAMES_TO_FACTORIES =
        {
                {BARFIGHT_CARD_NAME, std::shared_ptr<BarfightFactory>(new BarfightFactory)},
                {DRAGON_CARD_NAME, std::shared_ptr<DragonFactory>(new DragonFactory)},
                {FAIRY_CARD_NAME, std::shared_ptr<FairyFactory>(new FairyFactory)},
                {GANG_CARD_NAME, std::shared_ptr<GangFactory>(new GangFactory)},
                {GOBLIN_CARD_NAME, std::shared_ptr<GoblinFactory>(new GoblinFactory)},
                {MERCHANT_CARD_NAME, std::shared_ptr<MerchantFactory>(new MerchantFactory)},
                {PITFALL_CARD_NAME, std::shared_ptr<PitfallFactory>(new PitfallFactory)},
                {TREASURE_CARD_NAME, std::shared_ptr<TreasureFactory>(new TreasureFactory)},
                {VAMPIRE_CARD_NAME, std::shared_ptr<VampireFactory>(new VampireFactory)}
        };
/*
 * Tries to find a CardFactory of type "cardName"

 * @param cardName - card's name.
 * @param cardFactory - pointer to CardFactory that will recieve the CardFactory of "cardName".
 * @return
 *      true if a CardFactory of type "cardName" has been found and false otherwise.
 */
bool tryGetCardConstructor(const std::string& cardName, CardFactory** cardFactory);

/*
 * Returns CardFactory of type "cardName", assuming a Card of type "cardName" exists 

 * @param cardName - card's name.
 * @param cardFactory - pointer to CardFactory that will recieve the 
 * @return
 *      pointer to CardFactory of "cardName".
 */
CardFactory* getCardFactory(const std::string& cardName);

/*
* Returns true if a card of the given type is a BattleCard and false if it's no
*/
bool isBattleCard(const std::string& cardName);


#endif //CARD_UTILITIES_H