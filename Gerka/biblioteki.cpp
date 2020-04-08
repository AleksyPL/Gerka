#include "biblioteki.h"

void soundDrums()
{
	PlaySound(TEXT("./wav/drums.wav"), NULL, SND_ASYNC);
}
void soundDamage()
{
	PlaySound(TEXT("./wav/damage.wav"), NULL, SND_ASYNC);
}
void soundDrink()
{
	PlaySound(TEXT("./wav/picie.wav"), NULL, SND_ASYNC);
}
void soundStartFight()
{
	PlaySound(TEXT("./wav/start_fight.wav"), NULL, SND_ASYNC);
}
void soundHit()
{
	PlaySound(TEXT("./wav/hit.wav"), NULL, SND_ASYNC);
}
void soundBeer()
{
	PlaySound(TEXT("./wav/beer.wav"), NULL, SND_ASYNC);
}
void soundSuccess()
{
	PlaySound(TEXT("./wav/sukces.wav"), NULL, SND_ASYNC);
}
void soundAlchemy()
{
	PlaySound(TEXT("./wav/alchemik.wav"), NULL, SND_ASYNC);
}
void soundCash()
{
	PlaySound(TEXT("./wav/cash.wav"), NULL, SND_ASYNC);
}
void soundBlacksmith()
{
	PlaySound(TEXT("./wav/kowal_up.wav"), NULL, SND_ASYNC);
}
void soundHealUp()
{
	PlaySound(TEXT("./wav/heal_up.wav"), NULL, SND_ASYNC);
}
void soundShaman()
{
	PlaySound(TEXT("./wav/shaman.wav"), NULL, SND_ASYNC);
}
void soundCheatActivated()
{
	PlaySound(TEXT("./wav/cheat_activated.wav"), NULL, SND_ASYNC);
}
void soundGameOver()
{
	PlaySound(TEXT("./wav/church_bells.wav"), NULL, SND_SYNC);
}
void soundStop()
{
	PlaySound(NULL, NULL, 0);
}
void soundNoMoney()
{
	PlaySound(TEXT("./wav/no_money.wav"), NULL, SND_ASYNC);
}
void soundDropItem()
{
	PlaySound(TEXT("./wav/drop_item.wav"), NULL, SND_ASYNC);
}
void soundRejection()
{
	PlaySound(TEXT("./wav/no.wav"), NULL, SND_ASYNC);
}
string noMoney()
{
	soundNoMoney();
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
string stringToLower(string data)
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
bool fileExist(string path)
{
	std::ifstream ifile(path);
	if (ifile)
	{
		return true;
	}
	else
	{
		return false;
	}
}