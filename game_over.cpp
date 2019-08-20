#include "biblioteki.h"
#include "player.h"

void game_over()
{
	system("cls");
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/mix/game_over.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		cout << linia << endl;
	}
	plik.close();
	sound_game_over();
	system("PAUSE");
}