#include "dependencies.h"

static const int LINE_LENGTH = 256;

enum card { barFight, fairy, merchant, pitfall,
        treasure, vampire, goblin, dragon };
map<string, card> cardTypes;

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

static void registerPlayers()
{
    playerTypes[WIZARD] = wizard;
    playerTypes[FIGHTER] = fighter;
    playerTypes[ROGUE] = rogue;
}

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

void Mtmchkin::setTeamSize()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int teamSize;
    cin >> teamSize;
    while((teamSize > MAX_TEAM)||(teamSize < MIN_TEAM))
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        cin >> teamSize;
    }
    m_teamSize = teamSize;
}

static void checkPlayerName(string playerName)
{
    while((playerName.length() > MAX_LENGTH)||
          (std::count(playerName.begin(), playerName.end(), ILLEGAL_SPACE)))
    {
        printInvalidName();
        printInsertPlayerMessage();
        std::getline(std::cin, playerName);
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
