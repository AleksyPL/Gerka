#include "biblioteki.h"
#include "ui.h"
#include "tytul.h"
#include "boost-syf.h"

void level_up(player &gracz)
{
	while (gracz.exp >= gracz.exp_to_next_level)
	{
		if (gracz.counter_nerf_str != 0)
		{
			remove_nerf_str(gracz);
		}
		if (gracz.counter_nerf_agility != 0)
		{
			remove_nerf_agility(gracz);
		}
		if (gracz.counter_nerf_intel != 0)
		{
			remove_nerf_intel(gracz);
		}
		if (gracz.counter_nerf_luck != 0)
		{
			remove_nerf_luck(gracz);
		}
		if (gracz.counter_nerf_charisma != 0)
		{
			remove_nerf_charisma(gracz);
		}
		cout << "AWANSUJESZ NA "<<gracz.level+1<<" POZIOM"<< endl;
		gracz.exp= gracz.exp- gracz.exp_to_next_level;
		gracz.exp_to_next_level = gracz.exp_to_next_level * 2;
		gracz.level = gracz.level + 1;
		gracz.hp = gracz.max_hp + 10;
		gracz.max_hp = gracz.hp;
		give_the_title(gracz);
		char wyb_statystyki = 0;
		while (1)
		{
			cout << "DOSTAJESZ PUNKT UMIEJ�TNO�CI, DO KT�REJ STATYSTYKI CHCESZ GO DODA�?" << endl;
			cout << "1. SI�A" << endl;
			cout << "2. ZR�CZNO��" << endl;
			cout << "3. INTELIGENCJA" << endl;
			cout << "4. SZCZʌCIE" << endl;
			cout << "Twoj wybor to: ";
			cin >> wyb_statystyki;
			switch (wyb_statystyki)
			{
			case '1':
			{
				cout << endl << "DODANO JEDEN PUNKT DO SI�Y" << endl;
				gracz.str = gracz.str + 1;
				break;
			}
			case '2':
			{
				cout << endl << "DODANO JEDEN PUNKT DO ZR�CZNO�CI" << endl;
				gracz.agility = gracz.agility + 1;
				break;
			}
			case '3':
			{
				cout << endl << "DODANO JEDEN PUNKT DO INTELIGENCJI" << endl;
				gracz.intel = gracz.intel + 1;
				break;
			}
			case '4':
			{
				cout << endl << "DODANO JEDEN PUNKT DO SZCZʌCIA" << endl;
				gracz.luck = gracz.luck + 1;
				break;
			}
			default:
			{
				system("cls");
				break;
			}
			}
			break;
			system("cls");
		}
	}
}

void level_up_without_exp(player &gracz)
{
	if (gracz.counter_nerf_str != 0)
	{
		remove_nerf_str(gracz);
	}
	if (gracz.counter_nerf_agility != 0)
	{
		remove_nerf_agility(gracz);
	}
	if (gracz.counter_nerf_intel != 0)
	{
		remove_nerf_intel(gracz);
	}
	if (gracz.counter_nerf_luck != 0)
	{
		remove_nerf_luck(gracz);
	}
	if (gracz.counter_nerf_charisma != 0)
	{
		remove_nerf_charisma(gracz);
	}
	cout << "AWANSUJESZ NA " << gracz.level + 1 << " POZIOM" << endl;
	gracz.exp_to_next_level = gracz.exp_to_next_level * 2;
	gracz.level = gracz.level + 1;
	gracz.hp = gracz.max_hp + 10;
	gracz.max_hp = gracz.hp;
	string wyb_statystyki;
	while (1)
	{
		cout << "DOSTAJESZ PUNKT UMIEJ�TNO�CI, DO KT�REJ STATYSTYKI CHCESZ GO DODA�?" << endl;
		cout << "1. SI�A" << endl;
		cout << "2. ZR�CZNO��" << endl;
		cout << "3. INTELIGENCJA" << endl;
		cout << "4. SZCZʌCIE" << endl;
		cout << "Twoj wybor to: ";
		cin >> wyb_statystyki;
		switch (wyb_statystyki[0])
		{
		case '1':
		{
			cout << endl << "DODANO JEDEN PUNKT DO SI�Y" << endl;
			gracz.str = gracz.str + 1;
			break;
		}
		case '2':
		{
			cout << endl << "DODANO JEDEN PUNKT DO ZR�CZNO�CI" << endl;
			gracz.agility = gracz.agility + 1;
			break;
		}
		case '3':
		{
			cout << endl << "DODANO JEDEN PUNKT DO INTELIGENCJI" << endl;
			gracz.intel = gracz.intel + 1;
			break;
		}
		case '4':
		{
			cout << endl << "DODANO JEDEN PUNKT DO SZCZʌCIA" << endl;
			gracz.luck = gracz.luck + 1;
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
		break;
		system("cls");
	}
}