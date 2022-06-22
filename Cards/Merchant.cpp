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

/*
 * Function checks the user input for merchant choice, applies fitting behavior and
 * returns if the value entered is fitting a defined case, false otherwise
 */
static bool checkCase(int operationId, Player& player)
{
    switch (operationId)
    {
        case DO_NOTHING_ID: {
            printMerchantSummary(cout, player.getName(), DO_NOTHING_ID, DO_NOTHING_PAYMENT);
            return true;
        }

        case HEAL_ID: {
            if (player.pay(HEALING_PAYMENT)) {
                player.heal(HEALING_POTION);
                printMerchantSummary(cout, player.getName(), HEAL_ID, HEALING_PAYMENT);
            }
            else {
                handleInsufficientCoins(player, HEAL_ID);
            }
            return true;
        }

        case BUFF_ID: {
            if (player.pay(BUFF_PAYMENT)) {
                player.buff(FORCE_UNITS_TO_INCREASE);
                printMerchantSummary(cout, player.getName(), BUFF_ID, BUFF_PAYMENT);
            }
            else {
                handleInsufficientCoins(player, BUFF_ID);
            }
            return true;
        }

        default:
            printInvalidInput();
            return false;
    }
}

void Merchant::applyEncounter(Player& player) const 
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getCoins());
    bool isInputValid = false;
    while (!isInputValid) {
        string operationIdString;
        try {
            std::getline(cin, operationIdString);
            if (std::find_if(operationIdString.begin(), operationIdString.end(), isspace)!= operationIdString.end())
            {
                throw std::invalid_argument("");
            }
            string::size_type stringSizeType;
            int operationId = stoi(operationIdString, &stringSizeType);
            isInputValid = checkCase(operationId, player);
        }
        catch(std::exception& e)
        {
            printInvalidInput();
        }
    }
}
