#include "PlayerUtilities.h"

using std::unique_ptr;
using std::string;
using std::map;
using std::all_of;

bool tryGetPlayerConstructor(const string& job, PlayerFactory* playerFactory)
{
    map<string, unique_ptr<PlayerFactory>> playersNamesToFactories;
    playersNamesToFactories[NAME_OF_FIGHTER] = unique_ptr<FighterFactory>();
    playersNamesToFactories[NAME_OF_ROGUE] = unique_ptr<RogueFactory>();
    playersNamesToFactories[NAME_OF_WIZARD] = unique_ptr<WizardFactory>();

    if (playersNamesToFactories.count(job)) {
        playerFactory = playersNamesToFactories.at(job).get();
        return true;
    }

    return false;
}

static bool containsOnlyLetters(string const& str) {
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


