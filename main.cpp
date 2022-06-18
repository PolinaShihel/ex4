#include "Mtmchkin.h"
static const int MAX_NUMBER_OF_ROUNDS = 100
int main(){
    Mtmchkin game("deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();
    return 0;
}