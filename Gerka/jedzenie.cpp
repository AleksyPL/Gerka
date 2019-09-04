#include "biblioteki.h"
#include "player.h"
#include "jedzenie.h"

void eat_food(player &gracz, int cena, int ile_punktow)
{
	if (gracz.hunger == 10)
	{
		cout << "Nie jesteœ g³odny"<<endl;
		system("PAUSE");
	}
	else
	{
		if (gracz.gold >= cena)
		{
			cout << "Zajadasz schabowego ze smakiem" << endl;
			gracz.gold = gracz.gold - cena;
			gracz.hunger = gracz.hunger + ile_punktow;
			if (gracz.hunger > 10)
			{
				gracz.hunger = 10;
			}
		}
		else
		{
			no_money();
		}
		system("PAUSE");
	}
}