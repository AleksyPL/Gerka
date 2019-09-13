#include "level_up.h"
#include "tytul.h"
#include "boost_syf.h"

void level_up(player &gracz,int tryb)
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
	if (tryb == 1)
	{
		cout << "AWANSUJESZ NA " << gracz.level + 1 << " POZIOM" << endl;
		gracz.exp_to_next_level = gracz.level * 1000;
		gracz.level = gracz.level + 1;
		gracz.hp = gracz.max_hp + 10;
		gracz.max_hp = gracz.hp;
		give_the_title(gracz);
		string wyb_statystyki;
		while (1)
		{
			cout << "DOSTAJESZ PUNKT UMIEJÊTNOŒCI, DO KTÓREJ STATYSTYKI CHCESZ GO DODAÆ?" << endl;
			cout << "1. SI£A" << endl;
			cout << "2. ZRÊCZNOŒÆ" << endl;
			cout << "3. INTELIGENCJA" << endl;
			cout << "4. CHARYZMA" << endl;
			cout << "5. SZCZÊŒCIE" << endl;
			cout << "Twoj wybor to: ";
			cin >> wyb_statystyki;
			switch (wyb_statystyki[0])
			{
			case '1':
			{
				cout << endl << "DODANO JEDEN PUNKT DO SI£Y" << endl;
				gracz.str++;
				break;
			}
			case '2':
			{
				cout << endl << "DODANO JEDEN PUNKT DO ZRÊCZNOŒCI" << endl;
				gracz.agility++;
				break;
			}
			case '3':
			{
				cout << endl << "DODANO JEDEN PUNKT DO INTELIGENCJI" << endl;
				gracz.intel++;
				break;
			}
			case '4':
			{
				cout << endl << "DODANO JEDEN PUNKT DO CHARYZMY" << endl;
				gracz.charisma++;
				break;
			}
			case '5':
			{
				cout << endl << "DODANO JEDEN PUNKT DO SZCZÊŒCIA" << endl;
				gracz.luck++;
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
	else
	{
		while (gracz.exp >= gracz.exp_to_next_level)
		{
			cout << "AWANSUJESZ NA " << gracz.level + 1 << " POZIOM" << endl;
			gracz.exp = gracz.exp - gracz.exp_to_next_level;
			gracz.exp_to_next_level = gracz.level * 1000;
			gracz.level = gracz.level + 1;
			gracz.hp = gracz.max_hp + 10;
			gracz.max_hp = gracz.hp;
			give_the_title(gracz);
			char wyb_statystyki = 0;
			while (1)
			{
				cout << "DOSTAJESZ PUNKT UMIEJÊTNOŒCI, DO KTÓREJ STATYSTYKI CHCESZ GO DODAÆ?" << endl;
				cout << "1. SI£A" << endl;
				cout << "2. ZRÊCZNOŒÆ" << endl;
				cout << "3. INTELIGENCJA" << endl;
				cout << "4. CHARYZMA" << endl;
				cout << "5. SZCZÊŒCIE" << endl;
				cout << "Twoj wybor to: ";
				cin >> wyb_statystyki;
				switch (wyb_statystyki)
				{
				case '1':
				{
					cout << endl << "DODANO JEDEN PUNKT DO SI£Y" << endl;
					gracz.str++;
					break;
				}
				case '2':
				{
					cout << endl << "DODANO JEDEN PUNKT DO ZRÊCZNOŒCI" << endl;
					gracz.agility++;
					break;
				}
				case '3':
				{
					cout << endl << "DODANO JEDEN PUNKT DO INTELIGENCJI" << endl;
					gracz.intel++;
					break;
				}
				case '4':
				{
					cout << endl << "DODANO JEDEN PUNKT DO CHARYZMY" << endl;
					gracz.charisma++;
					break;
				}
				case '5':
				{
					cout << endl << "DODANO JEDEN PUNKT DO SZCZÊŒCIA" << endl;
					gracz.luck++;
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
}