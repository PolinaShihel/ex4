#include "dependencies.h"
#include <fstream>
#include <queue>

static const int LINE_LENGTH = 256;

using std::string;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::set;
using std::queue;
using std::unique_ptr;

Mtmchkin::Mtmchkin(const std::string fileName)
{
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
        if(line == FAIRY_CARD_NAME)
        {
            cardDeck.push(unique_ptr<Card>(new Fairy()));
        }
        else if(line == )

    }


}
