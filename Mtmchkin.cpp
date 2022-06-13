#include "dependencies.h"

static const int LINE_LENGTH = 256;

enum CardType { BARFIGHT, FAIRY, MERCHANT, PITFALL,
        TREASURE, VAMPIRE, GOBLIN, DRAGON };
map<string, CardType> cardTypes;

/*
 * Function assigns card names to enum types for later switch case use
 */
static void registerCards()
{
    cardTypes[BARFIGHT_CARD_NAME] = BARFIGHT;
    cardTypes[FAIRY_CARD_NAME] = FAIRY;
    cardTypes[MERCHANT_CARD_NAME] = MERCHANT;
    cardTypes[PITFALL_CARD_NAME] = PITFALL;
    cardTypes[TREASURE_CARD_NAME] = TREASURE;
    cardTypes[VAMPIRE_CARD_NAME] = VAMPIRE;
    cardTypes[GOBLIN_CARD_NAME] = GOBLIN;
    cardTypes[DRAGON_CARD_NAME] = DRAGON;
}

enum PlayerType { WIZARD, FIGHTER, ROGUE };
map<string, PlayerType> playerTypes;

/*
 * Function assigns player's jobs names to enum types for later switch case use
 */
static void registerPlayers()
{
    playerTypes[NAME_OF_WIZARD] = WIZARD;
    playerTypes[NAME_OF_FIGHTER] = FIGHTER;
    playerTypes[NAME_OF_ROGUE] = ROGUE;
}

/*
 * Function creates the correct type of card according to the user input
 */
static void makeCardDeck(const string currentLine, queue<unique_ptr<Card>>& cardDeck) {
    switch (cardTypes[currentLine]) {
        case BARFIGHT: {
            cardDeck.push(unique_ptr<Card>(new Barfight()));
            break;
        }
        case FAIRY: {
            cardDeck.push(unique_ptr<Card>(new Fairy()));
            break;
        }
        case MERCHANT: {
            cardDeck.push(unique_ptr<Card>(new Merchant()));
            break;
        }
        case PITFALL: {
            cardDeck.push(unique_ptr<Card>(new Pitfall()));
            break;
        }
        case TREASURE: {
            cardDeck.push(unique_ptr<Card>(new Treasure()));
            break;
        }
        case VAMPIRE: {
            cardDeck.push(unique_ptr<Card>(new Vampire()));
            break;
        }
        case GOBLIN: {
            cardDeck.push(unique_ptr<Card>(new Goblin));
            break;
        }
        case DRAGON: {
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
            case WIZARD:
            {
                playersQueue.push(unique_ptr<Player>(new Wizard(playerName)));
                tempPlayerNum--;
                break;
            }
            case FIGHTER:
            {
                playersQueue.push(unique_ptr<Player>(new Fighter(playerName)));
                tempPlayerNum--;
                break;
            }
            case ROGUE:
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
