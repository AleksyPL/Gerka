#include "sleep.h"
#include "koniec_tury.h"
#include "zakres.h"

void sleep(player &gracz, int cena, int tryb)
{
	if (gracz.gold < cena)
	{
		no_money();
	}
	else
	{
		if (tryb == 0)
		{
			cout << "Karczmarz prowadzi ciê do wolnego pokoju" << endl;
		}
		cout << "Przesypiasz bezpiecznie noc" << endl;
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
		end_of_turn(gracz);
		range(gracz);
	}
	system("PAUSE");
}