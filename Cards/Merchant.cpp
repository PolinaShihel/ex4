#include "Merchant.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;

Merchant* Merchant::Clone() const
{
	return new Merchant(*this);
}

/*
* Prints the relevant messages when player doesn't have enough money 
*/
static void handleInsufficientCoins(const Player& player, int operationId)
{
	printMerchantInsufficientCoins(cout);
	printMerchantSummary(cout, player.getName(), operationId, DO_NOTHING_PAYMENT);
}

void Merchant::applyEncounter(Player& player) const {
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getCoins());

    bool isInputValid = false;
    while (!isInputValid) {
        string operationIdString;
        cin >> operationIdString;

        string::size_type stringSizeType;
        try {
            int operationId = stoi(operationIdString, &stringSizeType);
            switch (operationId)
            {
                case DO_NOTHING_ID: {
                    isInputValid = true;
                    printMerchantSummary(cout, player.getName(), DO_NOTHING_ID, DO_NOTHING_PAYMENT);
                    break;
                }

                case HEAL_ID: {
                    isInputValid = true;
                    if (player.pay(HEALING_PAYMENT)) {
                        player.heal(HEALING_POTION);
                        printMerchantSummary(cout, player.getName(), HEAL_ID, HEALING_PAYMENT);
                    }
                    else {
                        handleInsufficientCoins(player, HEAL_ID);
                    }
                    break;
                }

                case BUFF_ID: {
                    isInputValid = true;
                    if (player.pay(BUFF_PAYMENT)) {
                        player.buff(FORCE_UNITS_TO_INCREASE);
                        printMerchantSummary(cout, player.getName(), BUFF_ID, BUFF_PAYMENT);
                    }
                    else {
                        handleInsufficientCoins(player, BUFF_ID);
                    }
                    break;
                }

                default:
                    printInvalidInput();
                    break;
            }
        }
        catch(std::exception& e)
        {
            printInvalidInput();
        }
    }
}
