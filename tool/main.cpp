#include "Mtmchkin.h"
static const int MAX_NUMBER_OF_ROUNDS = 100;
static const std::string DECK_FILE = "../deck.txt";

int main()
{
    try
    {
        Mtmchkin game(DECK_FILE);
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
        {
            game.playRound();
        }
        //according to game instructions the leader board is only printed at the end
        game.printLeaderBoard();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}