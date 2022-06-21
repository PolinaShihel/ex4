#ifndef CARD_UTILITIES_H
#define CARD_UTILITIES_H

#include "CardFactory.h"
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <set>

bool tryGetCardConstructor(const std::string& name, CardFactory* cardFactory);
CardFactory* getCardFactory(const std::string& name);
bool isBattleCard(const std::string& name);


#endif //CARD_UTILITIES_H