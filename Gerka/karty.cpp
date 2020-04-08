#include "karty.h"
#include "zakres.h"
#include "level_up.h"
#include "czas.h"
#include "tabelka.h"

void gambling(int height, int startPoint, player &gracz)
{
	vector<string> message;
	if (gracz.gold == 0)
	{
		soundRejection();
		message.push_back("You don't have money to play cards!");
		tabSubmenuTextOnly(height, startPoint, message);
	}
	else
	{
		string temp = "You play cards with the residents, place bet: ";
		int stake = stoi(tabSubmenuInputField(height, startPoint, temp));
		while (stake<0 || stake>gracz.gold)
		{
			stake = stoi(tabSubmenuInputField(height, startPoint, temp));
		}
		message.push_back("Stake: " + to_string(stake));
		int pom = rand() % 100;
		int pom2 = rand() % 100;
		if (gracz.luck + pom>pom2)
		{
			message.push_back("You won " + to_string(stake) + " gold");
			gracz.gold = gracz.gold + stake;
			gracz.exp = gracz.exp + 5;
		}
		else
		{
			message.push_back("You lose " + to_string(stake) + " gold");
			gracz.gold = gracz.gold - stake;
		}
		tabSubmenuTextOnly(height, startPoint, message);
		changeTime(height, startPoint, gracz, 0, 10);
		gracz.exp = gracz.exp + 5;
		levelUp(height, startPoint, gracz);
		range(gracz);
	}
}