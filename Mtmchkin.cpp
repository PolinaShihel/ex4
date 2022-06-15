#include "dependencies.h"

static const int LINE_LENGTH = 256;

template<class T>
Card* createCard()
{
    return new T;
}

template<class T>
Player* createPlayer(std::string playerName)
{
    return new T(playerName);
}

static void initializeCardsConstructors(std::map<std::string, CardConstructor>& cardsConstructors)
{
    cardsConstructors[BARFIGHT_CARD_NAME] = createCard<Barfight>;
    cardsConstructors[FAIRY_CARD_NAME] = createCard<Fairy>;
    cardsConstructors[MERCHANT_CARD_NAME] = createCard<Merchant>;
    cardsConstructors[PITFALL_CARD_NAME] = createCard<Pitfall>;
    cardsConstructors[TREASURE_CARD_NAME] = createCard<Treasure>;
    cardsConstructors[VAMPIRE_CARD_NAME] = createCard<Vampire>;
    cardsConstructors[GOBLIN_CARD_NAME] = createCard<Goblin>;
    cardsConstructors[DRAGON_CARD_NAME] = createCard<Dragon>;
}

static void initializePlayersConstructors(std::map<std::string, PlayerConstructor>& playersConstructors)
{
    playersConstructors[NAME_OF_WIZARD] = createPlayer<Wizard>;
    playersConstructors[NAME_OF_FIGHTER] = createPlayer<Fighter>;
    playersConstructors[NAME_OF_ROGUE] = createPlayer<Rogue>;
}

Mtmchkin::Mtmchkin(const std::string fileName)
{
    initializeCardsConstructors(m_cardsConstructors);
    initializePlayersConstructors(m_playersConstructors);

    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }
    char line[LINE_LENGTH];
    while(source.getline(line, sizeof(line)))
    {
        if (!CARDS_OFFICIAL_NAMES.count(line)) {
            throw InvalidCardName();
        }
        m_cardDeck.push(unique_ptr<Card>(m_cardsConstructors[line]()));
    }
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
    string job;
    string playerName;
    int tempPlayerNum = m_teamSize;
    while(tempPlayerNum)
    {
        printInsertPlayerMessage();
        cin >> playerName >>job;
        checkPlayerName(playerName);
        if (!PLAYERS_OFFICIAL_NAMES.count(playerName)) {
            printInvalidClass();
        }
        else {
            m_playersQueue.push(unique_ptr<Player>(m_playersConstructors[job](playerName)));
            tempPlayerNum--;
        }
    }
}
