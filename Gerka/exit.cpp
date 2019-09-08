#include "Biblioteki.h"
#include "ui.h"
#include "save.h"
#include "exit.h"
#include "dwellers.h"

void exit(player gracz, barman bobby, seller handlarz, blacksmith kowal, alchemist alchemik, shaman szaman, doctor lekarz)
{
	char zapis = 0;
	cout << "Wychodze do menu" << endl;
	cout << "Czy chcesz zapisac postep?" << endl;
	cout << "1.Tak" << endl;
	cout << "2.Nie" << endl;
	cout << "Twoj wybor to: ";
	cin >> zapis;
	switch (zapis)
	{
	case '1':
	{
		save(gracz,bobby,handlarz,kowal,alchemik);
		cout << "Gra zostala zapisana" << endl;
	}
	default:
	{
		system("PAUSE");
		system("cls");
	}
	}
}