#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <map>
#include <string>
#include <vector>
#include "Cards/Card.h"

static const int MAX_TEAM = 6;
static const int MIN_TEAM = 2;
static const int START_GAME_ROUNDS = 0;
static const int INITIAL_PLAYER = 0;
static const int INDEX_DECREASE = 1;

typedef Card* (*CardConstructor)();
typedef Player* (*PlayerConstructor)(std::string);

class Mtmchkin{
public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;



private:
    void makePlayerQueue();
    void setTeamSize();

    std::map<std::string, CardConstructor> m_cardsConstructors;
    std::map<std::string, PlayerConstructor> m_playersConstructors;

    std::queue<std::unique_ptr<Card>> m_cardDeck;
    std::queue<std::unique_ptr<Player>> m_playersQueue;
    std::vector<std::unique_ptr<Player>> m_playerRanking;

    int m_teamSize;
    int m_roundCount;
    int m_lastWinner;
    int m_lastLoser;

};


#endif /* MTMCHKIN_H_ */
