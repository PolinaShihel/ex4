#ifndef PLAYER_UTILITIES_H
#define PLAYER_UTILITIES_H

#include "PlayerFactory.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <set>

/*
 * Tries to find a PlayerFactory of type "job"

 * @param job - player's job.
 * @param playerFactory - pointer to PlayerFactory that will recieve the PlayerFactory of "job".
 * @return
 *      true if a PlayerFactory of type "job" has been found and false otherwise.
 */
bool tryGetPlayerConstructor(const std::string& job, PlayerFactory* playerFactory);

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