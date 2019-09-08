#include "karty.h"
#include "zakres.h"
#include "level_up.h"

void gambling(player &gracz)
{
	if (gracz.gold == 0)
	{
		cout << "Nie masz czym graæ, spadaj!" << endl;
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
		cout << "Gracie o " << stawka << " golda" << endl;
		int pom = rand() % 100;
		int pom2 = rand() % 100;
		if (gracz.luck + pom>pom2)
		{
			cout << "Wygrywasz " << stawka << " golda" << endl;
			gracz.gold = gracz.gold + stawka;
			gracz.exp = gracz.exp + 5;
		}
		else
		{
			cout << "Przegrywasz " << stawka << " golda" << endl;
			gracz.gold = gracz.gold - stawka;
		}
		gracz.exp = gracz.exp + 5;
		level_up(gracz);
		range(gracz);
		system("PAUSE");
	}
}