#ifndef PLAYER_UTILITIES_H
#define PLAYER_UTILITIES_H

#include "PlayerFactory.h"
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

#endif //PLAYER_UTILITIES_H