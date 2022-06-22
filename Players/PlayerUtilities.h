#ifndef PLAYER_UTILITIES_H
#define PLAYER_UTILITIES_H

#include "PlayerFactory.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <set>

const std::map<std::string, std::shared_ptr<PlayerFactory>> PLAYERS_NAMES_TO_FACTORIES =
{
        {NAME_OF_FIGHTER, std::shared_ptr<FighterFactory>(new FighterFactory)},
        {NAME_OF_ROGUE, std::shared_ptr<RogueFactory>(new RogueFactory)},
        {NAME_OF_WIZARD, std::shared_ptr<WizardFactory>(new WizardFactory)},
};
/*
/*
 * Tries to find a PlayerFactory of type "job"

 * @param job - player's job.
 * @param playerName - player's name.
 * @param playerFactory - pointer to PlayerFactory that will recieve the PlayerFactory of "job".
 * @return
 *      true if a PlayerFactory of type "job" has been found and false otherwise.
 */
bool tryGetPlayerConstructor(const std::string& job, std::string& playerName, PlayerFactory** playerFactory);

/*
 * Checks for the validity of the user input for a players name, contains no spaces and
 * is shorter than 15 chars
 * 
 * @param playerName - the given player name
 * @return
 *      true if playerName is valid and false otherwise.
 */
bool validPlayerName(std::string& playerName);

#endif //PLAYER_UTILITIES_H