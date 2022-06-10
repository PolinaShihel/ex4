#include "Merchant.h"

Merchant* Merchant::Clone() const
{
	return new Merchant(*this);
}

void Merchant::applyEncounter(Player& player) const
{
	string playerName = player.getName();
	printMerchantInitialMessageForInteractiveEncounter(cout, playerName);
	
	bool isInputValid = false;
	while (!isInputValid) {
		string operationIdString;
		getline(cin, operationIdString);

		int operationId = stoi(operationIdString, &(operationIdString.size()));
		switch (operationId)
		{
		case DO_NOTHING_ID: {
			printMerchantSummary(cout, playerName, DO_NOTHING_ID, DO_NOTHING_PAYMENT);
			break;
		}

		case HEAL_ID: {
			isInputValid = true;
			if (player.pay(HEALING_PAYMENT)) {
				player.heal(HEALTH_POINTS_TO_INCREASE);
				printMerchantSummary(cout, playerName, HEAL_ID, HEALING_PAYMENT);
			}
			else {
				printMerchantInsufficientCoins(cout);
			}
			break;
		}

		case INCREASE_FORCE_ID: {
			isInputValid = true;
			if (player.pay(BUFF_PAYMENT)) {
				player.buff(FORCE_UNITS_TO_INCREASE);
				printMerchantSummary(cout, playerName, INCREASE_FORCE_ID, BUFF_PAYMENT);
			}
			else {
				printMerchantInsufficientCoins(cout);
			}
			break;
		}

		default:
			printInvalidInput();
			break;
		}
	}
}