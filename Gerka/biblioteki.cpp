#include "biblioteki.h"

void sound_drums()
{
	PlaySound(TEXT("./wav/drums.wav"), NULL, SND_ASYNC);
}
void sound_damage()
{
	PlaySound(TEXT("./wav/damage.wav"), NULL, SND_ASYNC);
}
void sound_drink()
{
	PlaySound(TEXT("./wav/picie.wav"), NULL, SND_ASYNC);
}
void sound_start_fight()
{
	PlaySound(TEXT("./wav/start_fight.wav"), NULL, SND_ASYNC);
}
void sound_hit()
{
	PlaySound(TEXT("./wav/hit.wav"), NULL, SND_ASYNC);
}
void sound_beer()
{
	PlaySound(TEXT("./wav/beer.wav"), NULL, SND_ASYNC);
}
void sound_success()
{
	PlaySound(TEXT("./wav/sukces.wav"), NULL, SND_ASYNC);
}
void sound_alchemy()
{
	PlaySound(TEXT("./wav/alchemik.wav"), NULL, SND_ASYNC);
}
void sound_cash()
{
	PlaySound(TEXT("./wav/cash.wav"), NULL, SND_ASYNC);
}
void sound_blacksmith()
{
	PlaySound(TEXT("./wav/kowal_up.wav"), NULL, SND_ASYNC);
}
void sound_heal_up()
{
	PlaySound(TEXT("./wav/heal_up.wav"), NULL, SND_ASYNC);
}
void sound_shaman()
{
	PlaySound(TEXT("./wav/shaman.wav"), NULL, SND_ASYNC);
}
void sound_cheat_activated()
{
	PlaySound(TEXT("./wav/cheat_activated.wav"), NULL, SND_ASYNC);
}
void sound_game_over()
{
	PlaySound(TEXT("./wav/hugo.wav"), NULL, SND_SYNC);
}
void sound_stop()
{
	PlaySound(NULL, NULL, 0);
}
void sound_no_money()
{
	PlaySound(TEXT("./wav/no_money.wav"), NULL, SND_ASYNC);
}
void sound_drop_item()
{
	PlaySound(TEXT("./wav/drop_item.wav"), NULL, SND_ASYNC);
}
void sound_rejection()
{
	PlaySound(TEXT("./wav/no.wav"), NULL, SND_ASYNC);
}
string no_money()
{
	sound_no_money();
	return "You don't have enough money";
}
void change_color(int num)
{
	HANDLE cz;
	cz = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cz, num);
	//0 - czarny
	//1 - niebieski
	//2 - zielony
	//3 - b喚kitny
	//4 - czerwony
	//5 - purpurowy
	//6 - 鄴速y
	//7 - bia造
	//8 - szary
	//9 - jasnoniebieski
	//10 - jasnozielony
	//11 - jasnob喚kitny
	//12 - jasnoczerwony
	//13 - jasnopurpurowy
	//14 - jasno鄴速y
	//15 - jaskrawobia造
}
string string_tolower(string data)
{
	transform(data.begin(), data.end(), data.begin(), tolower);
	return data;
}
void windowDrawOnCenter(WINDOW * win, int y, int how_log, string name, int x, int spaces_on_the_end)
{
	int j = name.length();
	int i = how_log - j;
	string temp;
	if ((how_log - j) % 2 == 0)
	{
		for (int j = 0; j < i / 2; j++)
		{
			temp = temp + " ";
		}
	}
	else
	{
		for (int j = 0; j < (i / 2) + 1; j++)
		{
			temp = temp + " ";
		}
	}
	temp = temp + name;
	if (spaces_on_the_end == 0)
	{
		mvwprintw(win, y, x, temp.c_str());
	}
	else
	{
		for (int j = 0; j < i / 2; j++)
		{
			temp = temp + " ";
		}
		mvwprintw(win, y, x, temp.c_str());
	}
}
string findItemOnList(string item)
{
	int nr_linii = 1;
	string linia;
	fstream plik;
	plik.open("./txt/mix/Items_usable.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		if (linia == item)
		{
			return "Usable";
		}
		else
		{
			nr_linii++;
		}
	}
	plik.close();
	nr_linii = 1;
	plik.open("./txt/mix/Items_alchemy.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		if (linia == item)
		{
			return "Alchemy";
		}
		else
		{
			nr_linii++;
		}
	}
	plik.close();
	nr_linii = 1;
	plik.open("./txt/mix/Items_smithery.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		if (linia == item)
		{
			return "Smithery";
		}
		else
		{
			nr_linii++;
		}
	}
	plik.close();
	return "Error";
}