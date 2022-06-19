#include "dependencies.h"

static const int LINE_LENGTH = 256;

using std::all_of;
using std::count;

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

/*
 * Function assigns player's jobs names to enum types for later switch case use
 */
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

Mtmchkin::Mtmchkin(const std::string fileName) :
m_roundCount(START_GAME_ROUNDS), m_lastWinner(INITIAL_PLAYER)
{
    printStartGameMessage();
    initializeCardsConstructors(m_cardsConstructors);
    initializePlayersConstructors(m_playersConstructors);
    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }
    if(source.peek() == EOF)
    {
        throw DeckFileInvalidSize();
    }
    char line[LINE_LENGTH];
    int errorLine = INITIAL_LINE;
    while(source.getline(line, sizeof(line)))
    {
        if (!CARDS_OFFICIAL_NAMES.count(line)) {
            throw DeckFileFormatError(errorLine);
        }
        m_cardDeck.push(unique_ptr<Card>(m_cardsConstructors[line]()));
        errorLine++;
    }
    this->makePlayerQueue();
    m_playerRanking.resize(m_teamSize);
    m_lastLoser = m_teamSize - INDEX_OFFSET;
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

static bool containsOnlyLetters(string const &str) {
    return all_of(str.begin(), str.end(), [](char const &c) {
        return isalpha(c);
    });
}
/*
 * Function checks for the validity of the user input for a players name, contains no spaces and
 * is shorter than 15 chars
 */
static void checkPlayerName(string& playerName, string& job)
{
    while((playerName.length() > MAX_LENGTH)||
          (count(playerName.begin(), playerName.end(), ILLEGAL_SPACE)) ||
            (!containsOnlyLetters(playerName)))
    {
        printInvalidName();
        printInsertPlayerMessage();
        cin >> playerName >>job;

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
        checkPlayerName(playerName, job);
        while (!PLAYERS_OFFICIAL_NAMES.count(job))
        {
            printInvalidClass();
            cin >> playerName >>job;
        }
        m_playersQueue.push_back(unique_ptr<Player>(m_playersConstructors[job](playerName)));
        tempPlayerNum--;
    }
}


void Mtmchkin::playRound()
{
    printRoundStartMessage(++m_roundCount);
    for (int player = INITIAL_PLAYER; player < m_teamSize; player++)
    {
        unique_ptr<Player> currentPlayer = move(m_playersQueue.front());
        printTurnStartMessage(currentPlayer->getName());
        m_playersQueue.pop_front();
        unique_ptr<Card> currentCard = std::move(m_cardDeck.front());
        m_cardDeck.pop();
        currentCard->applyEncounter(*currentPlayer);
        if (currentPlayer->getLevel() == MAXIMUM_LEVEL) {
            m_playerRanking[m_lastWinner] = move(currentPlayer);
            m_lastWinner++;
        }
        else if (currentPlayer->getHealthPoints() == MIN_HP)
        {
            m_playerRanking[m_lastLoser] = move(currentPlayer);
            m_lastLoser--;
        }
        else
        {
            m_playersQueue.emplace_back(move(currentPlayer));
        }
        m_cardDeck.emplace(move(currentCard));
    }
    m_teamSize = m_playersQueue.size();
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCount;
}

bool Mtmchkin::isGameOver() const {
    if(m_teamSize == 0)
    {
        return true;
    }
    return false;
}

int Mtmchkin::printWinnersAndLosers(int ranking, int firstIndex, int lastIndex) const
{
    for(int player = firstIndex; player < lastIndex; player++)
    {
        Player *currentPlayer = m_playerRanking.at(player).get();
        printPlayerLeaderBoard(ranking++, *currentPlayer);
    }
    return ranking;
}
void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = INITIAL_RANK;
    //Printing the current winners of the game
    ranking = printWinnersAndLosers(ranking,INITIAL_PLAYER,m_lastWinner);
    //Printing the players that are still playing the game
    if(!m_playersQueue.empty())
    {
        for(unsigned int player = INITIAL_PLAYER; player < m_playersQueue.size(); player++)
        {
            Player *currentPlayer = m_playersQueue[player].get();
            printPlayerLeaderBoard(ranking++, *currentPlayer);
        }
    }
    //Printing the current losers of the game
    printWinnersAndLosers(ranking, m_lastLoser + INDEX_OFFSET, m_playerRanking.size());
}
