#include "karty.h"
#include "zakres.h"
#include "level_up.h"
#include "czas.h"

void gambling(player &gracz)
{
	if (gracz.gold == 0)
	{
		sound_rejection();
		fancy_text("Nie masz czym graæ, spadaj!");
	}
	else
	{
		cout << endl << "Grasz z mieszczanami w karty" << endl;
		cout << "Podaj stawkê: ";
		int stawka;
		cin >> stawka;
		while (cin.fail() || stawka<0 || stawka>gracz.gold)
		{
			cout << "Podaj stawkê: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> stawka;
		}
		cout << "Gracie o " << stawka << " sztuk z³ota" << endl;
		int pom = rand() % 100;
		int pom2 = rand() % 100;
		if (gracz.luck + pom>pom2)
		{
			cout << "Wygrywasz " << stawka << " sztuk z³ota" << endl;
			gracz.gold = gracz.gold + stawka;
			gracz.exp = gracz.exp + 5;
		}
		else
		{
			cout << "Przegrywasz " << stawka << " sztuk z³ota" << endl;
			gracz.gold = gracz.gold - stawka;
		}
		change_time(gracz, 0, 10);
		gracz.exp = gracz.exp + 5;
		level_up(gracz);
		range(gracz);
		system("PAUSE");
	}
}