#include "level_up.h"
#include "tytul.h"

void giveTheTitle(player &gracz)
{
	int pomoc = gracz.level / 5;
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/mix/pseudo.txt", ios::in);
	for (int a = 0; a <= pomoc; a++)
	{
		getline(plik, gracz.pseudonym);
	}
	plik.close();
}