#include "PlayerUtilities.h"

using std::unique_ptr;
using std::string;
using std::map;
using std::all_of;

bool tryGetPlayerConstructor(const string& job, string& playerName, PlayerFactory** playerFactory)
{
    if (PLAYERS_NAMES_TO_FACTORIES.count(job)) {
        *playerFactory = PLAYERS_NAMES_TO_FACTORIES.at(job).get();
        return true;
    }

    return false;
}

/*
 * Function checks if the string that given contains only letters i.e no numbers or specials characters
 * @param str - string to be checked
 * @return -
 *      whether it contains only lettters or not
 */
static bool containsOnlyLetters(string const& str)
{
    return all_of(str.begin(), str.end(), [](char const& c) {
        return isalpha(c);
        });
}

bool validPlayerName(string& playerName)
{
    if ((playerName.length() > MAX_LENGTH) ||
        (count(playerName.begin(), playerName.end(), ILLEGAL_SPACE)) ||
        (!containsOnlyLetters(playerName)))
    {
        return false;
    }
    return true;
}


