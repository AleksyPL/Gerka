#include "mobki1.h"

Mieszkaniec_small::Mieszkaniec_small()
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	int gold_base = 0;
	int gold_range = 0;
	plik.open("./txt/mobki/citizen_small.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 2:hp = atoi(linia.c_str()); break;
		case 4:xp = atoll(linia.c_str()); break;
		case 6:damage = atoi(linia.c_str()); break;
		case 8:gold_base = atoi(linia.c_str()); break;
		case 10:gold_range = atoi(linia.c_str()); break;
		case 12:name = linia; break;
		case 14:drop_item = linia; break;
		case 16:drop_rate = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	plik.close();
	max_hp = hp;
	gold = (rand() % gold_range) + gold_base;
}
Mieszkaniec_medium::Mieszkaniec_medium()
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	int gold_base = 0;
	int gold_range = 0;
	plik.open("./txt/mobki/citizen_medium.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 2:hp = atoi(linia.c_str()); break;
		case 4:xp = atoll(linia.c_str()); break;
		case 6:damage = atoi(linia.c_str()); break;
		case 8:gold_base = atoi(linia.c_str()); break;
		case 10:gold_range = atoi(linia.c_str()); break;
		case 12:name = linia; break;
		case 14:drop_item = linia; break;
		case 16:drop_rate = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	plik.close();
	max_hp = hp;
	gold = (rand() % gold_range) + gold_base;
}
Mieszkaniec_big::Mieszkaniec_big()
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	int gold_base = 0;
	int gold_range = 0;
	plik.open("./txt/mobki/citizen_high.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 2:hp = atoi(linia.c_str()); break;
		case 4:xp = atoll(linia.c_str()); break;
		case 6:damage = atoi(linia.c_str()); break;
		case 8:gold_base = atoi(linia.c_str()); break;
		case 10:gold_range = atoi(linia.c_str()); break;
		case 12:name = linia; break;
		case 14:drop_item = linia; break;
		case 16:drop_rate = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	plik.close();
	max_hp = hp;
	gold = (rand() % gold_range) + gold_base;
}