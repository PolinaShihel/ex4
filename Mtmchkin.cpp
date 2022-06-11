#include "dependencies.h"

static const int LINE_LENGTH = 256;

enum card { barFight, fairy, merchant, pitfall,
        treasure, vampire, goblin, dragon };
map<string, card> cardTypes;

/*
 * Function assigns card names to enum types for later switch case use
 */
static void registerCards()
{
    cardTypes[BARFIGHT_CARD_NAME] = barFight;
    cardTypes[FAIRY_CARD_NAME] = fairy;
    cardTypes[MERCHANT_CARD_NAME] = merchant;
    cardTypes[PITFALL_CARD_NAME] = pitfall;
    cardTypes[TREASURE_CARD_NAME] = treasure;
    cardTypes[VAMPIRE_CARD_NAME] = vampire;
    cardTypes[GOBLIN_CARD_NAME] = goblin;
    cardTypes[DRAGON_CARD_NAME] = dragon;
}

enum player { wizard, fighter, rogue };
map<string, player> playerTypes;

/*
 * Function assigns player's jobs names to enum types for later switch case use
 */
static void registerPlayers()
{
    playerTypes[WIZARD] = wizard;
    playerTypes[FIGHTER] = fighter;
    playerTypes[ROGUE] = rogue;
}

/*
 * Function creates the correct type of card according to the user input
 */
static void makeCardDeck(const string currentLine, queue<unique_ptr<Card>>& cardDeck) {
    switch (cardTypes[currentLine]) {
        case barFight: {
            cardDeck.push(unique_ptr<Card>(new Barfight()));
            break;
        }
        case fairy: {
            cardDeck.push(unique_ptr<Card>(new Fairy()));
            break;
        }
        case merchant: {
            cardDeck.push(unique_ptr<Card>(new Merchant()));
            break;
        }
        case pitfall: {
            cardDeck.push(unique_ptr<Card>(new Pitfall()));
            break;
        }
        case treasure: {
            cardDeck.push(unique_ptr<Card>(new Treasure()));
            break;
        }
        case vampire: {
            cardDeck.push(unique_ptr<Card>(new Vampire()));
            break;
        }
        case goblin: {
            cardDeck.push(unique_ptr<Card>(new Goblin));
            break;
        }
        case dragon: {
            cardDeck.push(unique_ptr<Card>(new Dragon()));
            break;
        }
    }
}

Mtmchkin::Mtmchkin(const std::string fileName)
{
    registerCards();
    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }
    char line[LINE_LENGTH];
    queue<unique_ptr<Card>> cardDeck;
    while(source.getline(line, sizeof(line)))
    {
        if (!CARDS_OFFICIAL_NAMES.count(line)) {
            throw InvalidCardName();
        }
        makeCardDeck(line, cardDeck);
    }
    m_cardDeck = cardDeck;
    this->makePlayerQueue();
}

/*
 * Function checks if the user input for team size contains only numbers, if not throws an exception
 */
static int parseInt(const std::string &teamSizeStr)
{
    std::size_t pos;
    int teamSize = std::stoi(teamSizeStr, &pos);
    if (pos != teamSizeStr.size())
        throw std::invalid_argument("");
    return teamSize;
}

/*
 * Function handles user input for teamSize in cases of input made of integers and letters, only letters and
 * user input that is bigger than the int size
 */
static int checkIntIsEntered()
{
    int teamSize;
    string teamSizeStr;
    bool validInput = false;
    getline(cin, teamSizeStr);
    while(!validInput)
    {
        try {
                teamSize = parseInt(teamSizeStr);
                validInput = true;
            }
            //No need for separate exception handling since the print message is identical
            catch(std::exception& e)
            {
                printInvalidTeamSize();
                printEnterTeamSizeMessage();
                getline(cin, teamSizeStr);
            }
    }
    return teamSize;
}

void Mtmchkin::setTeamSize()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int teamSize = checkIntIsEntered();
    while((teamSize > MAX_TEAM)||(teamSize < MIN_TEAM))
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        teamSize = checkIntIsEntered();
    }
    m_teamSize = teamSize;
}

/*
 * Function checks for the validity of the user input for a players name, contains no spaces and
 * is shorter than 15 chars
 */
static void checkPlayerName(string playerName)
{
    while((playerName.length() > MAX_LENGTH)||
          (std::count(playerName.begin(), playerName.end(), ILLEGAL_SPACE)))
    {
        printInvalidName();
        printInsertPlayerMessage();
        std::getline(cin, playerName);
    }
}

void Mtmchkin::makePlayerQueue()
{
    setTeamSize();
    registerPlayers();
    std::queue<std::unique_ptr<Player>> playersQueue;
    string job;
    string playerName;
    int tempPlayerNum = m_teamSize;
    while(tempPlayerNum)
    {
        printInsertPlayerMessage();
        cin >> playerName >>job;
        checkPlayerName(playerName);
        switch(playerTypes[job]){
            case wizard:
            {
                playersQueue.push(unique_ptr<Player>(new Wizard(playerName)));
                tempPlayerNum--;
                break;
            }
            case fighter:
            {
                playersQueue.push(unique_ptr<Player>(new Fighter(playerName)));
                tempPlayerNum--;
                break;
            }
            case rogue:
            {
                playersQueue.push(unique_ptr<Player>(new Rogue(playerName)));
                tempPlayerNum--;
                break;
            }
            default:
                printInvalidClass();
        }
    }
    m_playersQueue = playersQueue;
}
