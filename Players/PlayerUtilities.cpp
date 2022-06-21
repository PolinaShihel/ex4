#include "PlayerUtilities.h"
#include <string>

using std::unique_ptr;
using std::string;
using std::map;

bool tryGetPlayerConstructor(const string& job, PlayerFactory* playerFactory)
{
    map<string, unique_ptr<PlayerFactory>> playersNamesToFactories;
    playersNamesToFactories[NAME_OF_FIGHTER] = unique_ptr<FighterFactory>();
    playersNamesToFactories[NAME_OF_ROGUE] = unique_ptr<RogueFactory>();
    playersNamesToFactories[NAME_OF_WIZARD] = unique_ptr<WizardFactory>();

    if (playersNamesToFactories.count(name)) {
        playerFactory = playersNamesToFactories.at(name).get();
        return true;
    }

    return false;
}
