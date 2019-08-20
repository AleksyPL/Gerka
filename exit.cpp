#include "Biblioteki.h"
#include "ui.h"
#include "save.h"

void exit(player gracz)
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
		save(gracz);
		cout << "Gra zostala zapisana" << endl;
	}
	default:
	{
		system("PAUSE");
		system("cls");
	}
	}
}