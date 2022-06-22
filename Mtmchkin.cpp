#include "dependencies.h"

static const int LINE_LENGTH = 256;

using std::all_of;
using std::count;

Mtmchkin::Mtmchkin(const std::string fileName) :
m_roundCount(START_GAME_ROUNDS), m_lastWinner(INITIAL_PLAYER)
{
    printStartGameMessage();
    ifstream source(fileName);
    if(!source) {
        throw DeckFileNotFound();
    }
    if(source.peek() == EOF) {
        throw DeckFileInvalidSize();
    }
    string line;
    int errorLine = INITIAL_LINE;
    while(getline(source, line))
    {
        CardFactory* currentCardFactory = nullptr;
        if (!tryGetCardConstructor(line, &currentCardFactory)) {
            throw DeckFileFormatError(errorLine);
        }
        m_cardDeck.push(unique_ptr<Card>(currentCardFactory->create()));
        if (line == GANG_CARD_NAME) {
            Gang* newGangCard = dynamic_cast<Gang*>(m_cardDeck.back().get());
            bool foundEndGangMessage = false;
            while (!foundEndGangMessage && getline(source, line)) {
                errorLine++;
                if (line == END_GANG_MESSAGE) {
                    foundEndGangMessage = true;
                }
                else {
                    if ((line == GANG_CARD_NAME) || (!isBattleCard(line))) {
                        throw DeckFileFormatError(errorLine);
                    }
                    newGangCard->addMonsterToGang(line);
                }
            }
            if (!foundEndGangMessage) {
                throw DeckFileFormatError(errorLine);
            }
        }
        errorLine++;
    }
	
	if(m_cardDeck.size() < MIN_CARDS) {
        throw DeckFileInvalidSize();
    }
	
    this->makePlayerQueue();
    m_playerRanking.resize(m_teamSize);
    m_lastLoser = m_teamSize - INDEX_OFFSET;
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
    while (!validInput)
    {
        try {
            teamSize = parseInt(teamSizeStr);
            validInput = true;
        }
        //No need for separate exception handling since the print message is identical
        catch (std::exception& e)
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

void Mtmchkin::makePlayerQueue()
{
    setTeamSize();
    string job;
    string playerName;
    int tempPlayerNum = m_teamSize;
    while(tempPlayerNum)
    {
        printInsertPlayerMessage();
        cin >> playerName >> job;

        while (!validPlayerName(playerName)) {
            printInvalidName();
            cin >> playerName >> job;
        }

        PlayerFactory *currentPlayerFactory = nullptr;
        while (!tryGetPlayerConstructor(job, playerName, &currentPlayerFactory)) {
            printInvalidClass();
            cin >> playerName >> job;
        }

        Player* temp = currentPlayerFactory->create(playerName);
        m_playersQueue.push_back(unique_ptr<Player>(currentPlayerFactory->create(playerName)));
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
