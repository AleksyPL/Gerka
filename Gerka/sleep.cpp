#include "sleep.h"
#include "zakres.h"
#include "czas.h"

void sleep(player &gracz, int cena,int hours, int minutes)
{
	if (gracz.gold < cena)
	{
		no_money();
	}
	else
	{
		if (gracz.hunger < 5)
		{
			cout << "Jesteœ zbyt g³ody by zasn¹æ" << endl;
		}
		else
		{
			if (minutes == 0)
			{
				cout << "Bezpiecznie przesypiasz " << hours << " godzin" << endl;
			}
			else
			{
				cout << "Bezpiecznie przesypiasz " << hours << " godzin i " << minutes << " minut" << endl;
			}
			if (gracz.hp < gracz.max_hp)
			{
				cout << "Regenerujesz swoje si³y" << endl;
				gracz.hp = gracz.hp + (0.05*gracz.hp);
			}
			gracz.gold = gracz.gold - cena;
			if (gracz.hp > gracz.max_hp)
			{
				gracz.hp = gracz.max_hp;
			}
			change_time(gracz, hours, minutes);
			range(gracz);
		}
	}
	system("PAUSE");
}