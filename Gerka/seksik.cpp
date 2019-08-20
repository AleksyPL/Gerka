#include "biblioteki.h"
#include "level_up.h"
#include "boost-syf.h"
#include "koniec_tury.h"
#include "zakres.h"

void have_sex(player &gracz, int cena)
{
	if (gracz.gold > cena || gracz.gold == cena)
	{
		system("cls");
		string linia;
		int nr_linii = 1;
		fstream plik;
		{
			int pani = rand() % 9;
			if (pani == 0)
			{
				plik.open("./txt/burdel/burdel0.txt", ios::in);
			}
			else if (pani == 1)
			{
				plik.open("./txt/burdel/burdel1.txt", ios::in);
			}
			else if (pani == 2)
			{
				plik.open("./txt/burdel/burdel2.txt", ios::in);
			}
			else if (pani == 3)
			{
				plik.open("./txt/burdel/burdel3.txt", ios::in);
			}
			else if (pani == 4)
			{
				plik.open("./txt/burdel/burdel4.txt", ios::in);
			}
			else if (pani == 5)
			{
				plik.open("./txt/burdel/burdel5.txt", ios::in);
			}
			else if (pani == 6)
			{
				plik.open("./txt/burdel/burdel6.txt", ios::in);
			}
			else if (pani == 7)
			{
				plik.open("./txt/burdel/burdel7.txt", ios::in);
			}
			else if (pani == 8)
			{
				plik.open("./txt/burdel/burdel8.txt", ios::in);
			}
		}
		while (!plik.eof())
		{
			getline(plik, linia);
			cout << linia << endl;
		}
		plik.close();
		cout << endl;
		system("PAUSE");
		gracz.gold = gracz.gold - cena;
		gracz.exp = gracz.exp + 1;
		level_up(gracz);
		int chance_for_std = rand() % 10;
		if (gracz.find_item_usage("Durexy") == 1)
		{
			int index = gracz.find_usage_item_index("Durexy");
			gracz.inventory_usage_amount[index] = gracz.inventory_usage_amount[index] - 1;
			cout << "ZU¯YWASZ JEDNEGO DUREXA" << endl;
			chance_for_std = chance_for_std + 1;
			system("PAUSE");
			if (gracz.inventory_usage_amount[index] == 0)
			{
				gracz.inventory_usage[index] = "";
				gracz.sort_backpack_usage();
			}
		}
		if (chance_for_std == 0)
		{
			if (gracz.counter_boost_str != 0)
			{
				cout << "TWOJE WZMOCNIENIE PRZESTAJE DZIA£AÆ!!!" << endl;
				remove_boost_str(gracz);
			}
			sound_damage();
			cout << "Z£APA£EŒ CHOROBÊ WENERYCZN¥, CZASOWO TRACISZ 1 PUNKT SI£Y" << endl;
			if (gracz.counter_nerf_str != 0)
			{
				cout << "TWOJE OS£ABIENIA SIÊ KUMULUJ¥!!!" << endl;
			}
			add_nerf_str(gracz, 3, 1);
			system("PAUSE");
		}
		else if (chance_for_std == 1)
		{
			cout << "TO BY£ NAJLEPSZY SEKS TWOJEGO ¯YCIA" << endl;
			if (gracz.counter_nerf_str == 0)
			{
				cout << "JAKIMŒ CUDEM LECZYSZ SWOJE OS£ABIENIE SI£Y" << endl;
			}
			cout << "CZASOWO ZYSKUJESZ 1 PUNKT SI£Y" << endl;
			if (gracz.counter_boost_str != 0)
			{
				cout << "TWOJE PREMIE SIÊ KUMULUJ¥!!!" << endl;
			}
			add_boost_str(gracz, 3, 1);
			system("PAUSE");
		}
	}
	else
	{
		no_money();
		system("PAUSE");
	}
}