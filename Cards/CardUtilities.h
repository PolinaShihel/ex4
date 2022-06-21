#ifndef CARD_UTILITIES_H
#define CARD_UTILITIES_H

#include "CardFactory.h"
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <set>

/*
 * Tries to find a CardFactory of type "cardName"

 * @param cardName - card's name.
 * @param cardFactory - pointer to CardFactory that will recieve the CardFactory of "cardName".
 * @return
 *      true if a CardFactory of type "cardName" has been found and false otherwise.
 */
bool tryGetCardConstructor(const std::string& cardName, CardFactory* cardFactory);

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