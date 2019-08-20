#include "biblioteki.h"
#include "start.h"
#include "ui.h"
#include "player.h"
#include "tytul.h"
#include "dwellers.h"

int logo(int introo)
{
	if (introo == 0)
	{
		string linia;
		int nr_linii = 1;
		fstream plik;
		plik.open("./txt/mix/logo2.txt", ios::in);
		while (!plik.eof())
		{
			getline(plik, linia);
			cout << linia << endl;
		}
		plik.close();
		cout << "Twoj wybor to: ";
	}
	//INTRO
	else
	{		
		sound_drums();
		{
			string linia;
			int nr_linii = 1;
			fstream plik;
			plik.open("./txt/mix/logo0.txt", ios::in);
			while (!plik.eof())
			{
				getline(plik, linia);
				cout << linia << endl;
			}
			plik.close();
		}
		Sleep(1000);
		system("cls");
		{
			string linia;
			int nr_linii = 1;
			fstream plik;
			plik.open("./txt/mix/logo1.txt", ios::in);
			while (!plik.eof())
			{
				getline(plik, linia);
				cout << linia << endl;
			}
			plik.close();
		}
		Sleep(1000);
		system("cls");
		{
			string linia;
			int nr_linii = 1;
			fstream plik;
			plik.open("./txt/mix/logo2.txt", ios::in);
			while (!plik.eof())
			{
				getline(plik, linia);
				cout << linia << endl;
				Sleep(100);
			}
			plik.close();
		}
		cout << "Twoj wybor to: ";
		introo = 0;
	}
	return introo;
}

int main()
{
	setlocale(LC_ALL, "polish");
	system("MODE CON COLS=148 LINES=50");
	int introo = 0;
	while (1)
	{
		system("cls");
		introo = logo(introo);
		char wyb = 0;
		player gracz;
		barman bobby;
		seller handlarz;
		blacksmith kowal;
		alchemist alchemik;
		shaman szaman;
		doctor lekarz;
		cin >> wyb;
		switch (wyb)
		{
		case '1':
		{
			system("cls");
			cout << "X--------------------------------------------------------------------------------------------------------------------------------------------------X" << endl;
			cout << "|                                                                 STWÓRZ W£ASN¥ POSTAÆ                                                             |" << endl;
			cout << "X--------------------------------------------------------------------------------------------------------------------------------------------------X" << endl;
			cout << "IMIÊ TWOJEJ POSTACI TO: ";
			cin >> gracz.nazwa;
			while (cin.fail() || gracz.nazwa.length() > 20)
			{
				cout << "IMIE TWOJEJ POSTACI JEST ZA D£UGIE" << endl;
				cout << "IMIÊ TWOJEJ POSTACI TO: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> gracz.nazwa;
			}
			system("PAUSE");
			for (int g = 0; g < 3; g++)
			{
				int pomoc;
				string info;
				if (g == 0)
				{
					info = "NADAJ PIERWSZY PUNKT UMIEJÊTNOŒCI";
				}
				else if (g == 1)
				{
					info = "NADAJ DRUGI PUNKT UMIEJÊTNOŒCI";
				}
				else
				{
					info = "NADAJ TRZECI PUNKT UMIEJÊTNOŒCI";
				}
				pomoc = 142 - info.length();
				while (1)
				{
					system("cls");
					cout << "X--------------------------------------------------------------------------------------------------------------------------------------------------X" << endl;
					cout << "|";
					int i = pomoc % 2;
					if (i == 0)
					{
						for (int j = 0; j < pomoc / 2; j++)
						{
							cout << " ";
						}
					}
					else
					{
						for (int j = 0; j < (pomoc / 2) + 1; j++)
						{
							cout << " ";
						}
					}
					cout << "~~" << info << "~~";
					for (int j = 0; j < pomoc / 2; j++)
					{
						cout << " ";
					}
					cout << "|" << endl;
					cout << "X--------------------------------------------------------------------------------------------------------------------------------------------------X" << endl;
					cout << "|ILOŒÆ PUNKTÓW ¯YCIA: " << gracz.max_hp << "                                                   | 1. WZMOCNIJ SWOJE ZDROWIE                                             |" << endl;
					cout << "|ILOŒÆ PUNKTÓW SI£Y: " << gracz.str << "                                                     | 2. WZMOCNIJ SWOJ¥ SI£Ê                                                |" << endl;
					cout << "|ILOŒÆ PUNKTÓW ZRÊCZNOŒCI: " << gracz.agility << "                                               | 3. WZMOCNIJ SWOJ¥ ZRÊCZNOŒÆ                                           |" << endl;
					cout << "|ILOŒÆ PUNKTÓW INTELIGENCJI: " << gracz.intel << "                                             | 4. WZMOCNIJ SWOJ¥ INTELIGENCJÊ                                        |" << endl;
					cout << "|ILOŒÆ PUNKTÓW CHARYZMY: " << gracz.charisma << "                                                 | 5. WZMOCNIJ SWOJ¥ CHARYZMÊ                                            |" << endl;
					cout << "|ILOŒÆ PUNKTÓW SZCZÊŒCIA: " << gracz.luck << "                                                | 6. WZMOCNIJ SWOJE SZCZÊŒCIE                                           |" << endl;
					cout << "X--------------------------------------------------------------------------------------------------------------------------------------------------X" << endl;
					cout << "TWÓJ WYBÓR TO: ";
					string wybor;
					cin >> wybor;
					int pomoc = 0;
					switch (wybor[0])
					{
					case '1':
					{
						cout << "WZMOCNIONO ZDROWIE" << endl;
						gracz.max_hp = gracz.max_hp + 10;
						gracz.hp = gracz.max_hp;
						system("PAUSE");
						break;
					}
					case '2':
					{
						cout << "WZMOCNIONO SI£Ê" << endl;
						gracz.str = gracz.str + 1;
						system("PAUSE");
						break;
					}
					case '3':
					{
						cout << "WZMOCNIONO ZRÊCZNOŒÆ" << endl;
						gracz.agility = gracz.agility + 1;
						system("PAUSE");
						break;
					}
					case '4':
					{
						cout << "WZMOCNIONO INTELIGENCJÊ" << endl;
						gracz.intel = gracz.intel + 1;
						system("PAUSE");
						break;
					}
					case '5':
					{
						cout << "WZMOCNIONO CHARYZMÊ" << endl;
						gracz.charisma = gracz.charisma + 1;
						system("PAUSE");
						break;
					}
					case '6':
					{
						cout << "WZMOCNIONO SZCZÊŒCIE" << endl;
						gracz.luck = gracz.luck + 1;
						system("PAUSE");
						break;
					}
					default:
					{
						pomoc = 1;
						break;
					}
					}
					if (pomoc == 0)
						break;
				}
			}
			give_the_title(gracz);
			handlarz.load_merch();
			handlarz.add_prices(gracz);
			ui(gracz, bobby, handlarz, kowal, alchemik,szaman,lekarz);
			break;
		}
		case '2':
		{
			string linia;
			fstream plik;
			int nr_linii = 1;
			plik.open("./txt/mix/Zapis_gry_basic.txt", ios::in);
			while (getline(plik, linia))
			{
				switch (nr_linii)
				{
				case 2:gracz.nazwa = linia; break;
				case 4:gracz.level = atoi(linia.c_str()); break;
				case 6:gracz.gold = atoll(linia.c_str()); break;
				case 8:gracz.hp = atoi(linia.c_str()); break;
				case 10:gracz.max_hp = atoi(linia.c_str()); break;
				case 12:gracz.str = atoi(linia.c_str()); break;
				case 14:gracz.agility = atoi(linia.c_str()); break;
				case 16:gracz.intel = atoi(linia.c_str()); break;
				case 18:gracz.luck = atoi(linia.c_str()); break;
				case 20:gracz.charisma = atoi(linia.c_str()); break;
				case 22:gracz.hunger = atoi(linia.c_str()); break;
				case 24:gracz.alko = atoi(linia.c_str()); break;
				case 26:gracz.exp = atoi(linia.c_str()); break;
				case 28:gracz.exp_to_next_level = atoi(linia.c_str()); break;
				case 30:gracz.licznik_dnia = atoi(linia.c_str()); break;
				case 32:gracz.quest = linia; break;
				case 34:gracz.skill = linia; break;
				}
				nr_linii++;
			}
			plik.close();
			nr_linii = 1;
			plik.open("./txt/mix/Zapis_gry_eq.txt", ios::in);
			while (getline(plik, linia))
			{
				switch (nr_linii)
				{
				case 2:gracz.hp_potion = atoi(linia.c_str()); break;
				case 4:gracz.str_potion = atoi(linia.c_str()); break;
				case 6:gracz.agility_potion = atoi(linia.c_str()); break;
				case 8:gracz.intel_potion = atoi(linia.c_str()); break;
				case 10:gracz.charisma_potion = atoi(linia.c_str()); break;
				case 12:gracz.luck_potion = atoi(linia.c_str()); break;
				case 14:gracz.helmet = atoi(linia.c_str()); break;
				case 16:gracz.chestplate = atoi(linia.c_str()); break;
				case 18:gracz.gloves = atoi(linia.c_str()); break;
				case 20:gracz.pants = atoi(linia.c_str()); break;
				case 22:gracz.shoes = atoi(linia.c_str()); break;
				case 24:gracz.weapon = atoi(linia.c_str()); break;
				case 26:gracz.weapon_name = linia; break;
				}
				nr_linii++;
			}
			plik.close();
			nr_linii = 1;
			plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::in);
			while (getline(plik, linia))
			{
				switch (nr_linii)
				{
				case 2:gracz.inventory_usage[0] = linia; break;
				case 3:gracz.inventory_usage_amount[0] = atoi(linia.c_str()); break;
				case 5:gracz.inventory_usage[1] = linia; break;
				case 6:gracz.inventory_usage_amount[1] = atoi(linia.c_str()); break;
				case 8:gracz.inventory_usage[2] = linia; break;
				case 9:gracz.inventory_usage_amount[2] = atoi(linia.c_str()); break;
				case 11:gracz.inventory_usage[3] = linia; break;
				case 12:gracz.inventory_usage_amount[3] = atoi(linia.c_str()); break;
				case 14:gracz.inventory_usage[4] = linia; break;
				case 15:gracz.inventory_usage_amount[4] = atoi(linia.c_str()); break;
				case 17:gracz.inventory_usage[5] = linia; break;
				case 18:gracz.inventory_usage_amount[5] = atoi(linia.c_str()); break;
				case 20:gracz.inventory_usage[6] = linia; break;
				case 21:gracz.inventory_usage_amount[6] = atoi(linia.c_str()); break;
				case 23:gracz.inventory_usage[7] = linia; break;
				case 24:gracz.inventory_usage_amount[7] = atoi(linia.c_str()); break;
				case 26:gracz.inventory_usage[8] = linia; break;
				case 27:gracz.inventory_usage_amount[8] = atoi(linia.c_str()); break;
				case 29:gracz.inventory_usage[9] = linia; break;
				case 30:gracz.inventory_usage_amount[9] = atoi(linia.c_str()); break;
				case 32:gracz.inventory_usage[10] = linia; break;
				case 33:gracz.inventory_usage_amount[10] = atoi(linia.c_str()); break;
				case 35:gracz.inventory_usage[11] = linia; break;
				case 36:gracz.inventory_usage_amount[11] = atoi(linia.c_str()); break;
				case 38:gracz.inventory_usage[12] = linia; break;
				case 39:gracz.inventory_usage_amount[12] = atoi(linia.c_str()); break;
				case 41:gracz.inventory_usage[13] = linia; break;
				case 42:gracz.inventory_usage_amount[13] = atoi(linia.c_str()); break;
				case 44:gracz.inventory_usage[14] = linia; break;
				case 45:gracz.inventory_usage_amount[14] = atoi(linia.c_str()); break;
				case 47:gracz.inventory_usage[15] = linia; break;
				case 48:gracz.inventory_usage_amount[15] = atoi(linia.c_str()); break;
				case 50:gracz.inventory_usage[16] = linia; break;
				case 51:gracz.inventory_usage_amount[16] = atoi(linia.c_str()); break;
				case 53:gracz.inventory_usage[17] = linia; break;
				case 54:gracz.inventory_usage_amount[17] = atoi(linia.c_str()); break;
				case 56:gracz.inventory_usage[18] = linia; break;
				case 57:gracz.inventory_usage_amount[18] = atoi(linia.c_str()); break;
				case 59:gracz.inventory_usage[19] = linia; break;
				case 60:gracz.inventory_usage_amount[19] = atoi(linia.c_str()); break;
				case 62:gracz.inventory_crafting[0] = linia; break;
				case 63:gracz.inventory_crafting_amount[0] = atoi(linia.c_str()); break;
				case 65:gracz.inventory_crafting[1] = linia; break;
				case 66:gracz.inventory_crafting_amount[1] = atoi(linia.c_str()); break;
				case 68:gracz.inventory_crafting[2] = linia; break;
				case 69:gracz.inventory_crafting_amount[2] = atoi(linia.c_str()); break;
				case 71:gracz.inventory_crafting[3] = linia; break;
				case 72:gracz.inventory_crafting_amount[3] = atoi(linia.c_str()); break;
				case 74:gracz.inventory_crafting[4] = linia; break;
				case 75:gracz.inventory_crafting_amount[4] = atoi(linia.c_str()); break;
				case 77:gracz.inventory_crafting[5] = linia; break;
				case 78:gracz.inventory_crafting_amount[5] = atoi(linia.c_str()); break;
				case 80:gracz.inventory_crafting[6] = linia; break;
				case 81:gracz.inventory_crafting_amount[6] = atoi(linia.c_str()); break;
				case 83:gracz.inventory_crafting[7] = linia; break;
				case 84:gracz.inventory_crafting_amount[7] = atoi(linia.c_str()); break;
				case 86:gracz.inventory_crafting[8] = linia; break;
				case 87:gracz.inventory_crafting_amount[8] = atoi(linia.c_str()); break;
				case 89:gracz.inventory_crafting[9] = linia; break;
				case 90:gracz.inventory_crafting_amount[9] = atoi(linia.c_str()); break;
				case 92:gracz.inventory_crafting[10] = linia; break;
				case 93:gracz.inventory_crafting_amount[10] = atoi(linia.c_str()); break;
				case 95:gracz.inventory_crafting[11] = linia; break;
				case 96:gracz.inventory_crafting_amount[11] = atoi(linia.c_str()); break;
				case 98:gracz.inventory_crafting[12] = linia; break;
				case 99:gracz.inventory_crafting_amount[12] = atoi(linia.c_str()); break;
				case 101:gracz.inventory_crafting[13] = linia; break;
				case 102:gracz.inventory_crafting_amount[13] = atoi(linia.c_str()); break;
				case 104:gracz.inventory_crafting[14] = linia; break;
				case 105:gracz.inventory_crafting_amount[14] = atoi(linia.c_str()); break;
				case 107:gracz.inventory_crafting[15] = linia; break;
				case 108:gracz.inventory_crafting_amount[15] = atoi(linia.c_str()); break;
				case 110:gracz.inventory_crafting[16] = linia; break;
				case 111:gracz.inventory_crafting_amount[16] = atoi(linia.c_str()); break;
				case 113:gracz.inventory_crafting[17] = linia; break;
				case 114:gracz.inventory_crafting_amount[17] = atoi(linia.c_str()); break;
				case 116:gracz.inventory_crafting[18] = linia; break;
				case 117:gracz.inventory_crafting_amount[18] = atoi(linia.c_str()); break;
				case 119:gracz.inventory_crafting[19] = linia; break;
				case 120:gracz.inventory_crafting_amount[19] = atoi(linia.c_str()); break;
				}
				nr_linii++;
			}
			plik.close();
			gracz.sort_backpack_usage();
			gracz.sort_backpack_crafting();
			nr_linii = 1;
			plik.open("./txt/mix/Zapis_gry_npc.txt", ios::in);
			while (getline(plik, linia))
			{
				switch (nr_linii)
				{
				case 2:bobby.rep_level_set(atoi(linia.c_str())); break;
				case 4:bobby.rep_points_set(atoi(linia.c_str())); break;
				case 6:bobby.rep_points_to_next_level_set(atoi(linia.c_str())); break;
				case 8:bobby.gold_set(atoi(linia.c_str())); break;
				case 10:handlarz.rep_level_set(atoi(linia.c_str())); break;
				case 12:handlarz.rep_points_set(atoi(linia.c_str())); break;
				case 14:handlarz.rep_points_to_next_level_set(atoi(linia.c_str())); break;
				case 16:handlarz.gold_set(atoi(linia.c_str())); break;
				case 18:kowal.rep_level_set(atoi(linia.c_str())); break;
				case 20:kowal.rep_points_set(atoi(linia.c_str())); break;
				case 22:kowal.rep_points_to_next_level_set(atoi(linia.c_str())); break;
				case 24:kowal.gold_set(atoi(linia.c_str())); break;
				case 26:alchemik.rep_level_set(atoi(linia.c_str())); break;
				case 28:alchemik.rep_points_set(atoi(linia.c_str())); break;
				case 30:alchemik.rep_points_to_next_level_set(atoi(linia.c_str())); break;
				case 32:alchemik.gold_set(atoi(linia.c_str())); break;
				}
				nr_linii++;
			}
			plik.close();
			nr_linii = 1;
			plik.open("./txt/mix/Zapis_gry_boost.txt", ios::in);
			while (getline(plik, linia))
			{
				switch (nr_linii)
				{
				case 2:gracz.counter_nerf_str = atoi(linia.c_str()); break;
				case 4:gracz.before_nerf_str = atoi(linia.c_str()); break;
				case 6:gracz.counter_boost_str = atoi(linia.c_str()); break;
				case 8:gracz.before_boost_str = atoi(linia.c_str()); break;
				case 10:gracz.counter_nerf_agility = atoi(linia.c_str()); break;
				case 12:gracz.before_nerf_agility = atoi(linia.c_str()); break;
				case 14:gracz.counter_boost_agility = atoi(linia.c_str()); break;
				case 16:gracz.before_boost_agility = atoi(linia.c_str()); break;
				case 18:gracz.counter_nerf_intel = atoi(linia.c_str()); break;
				case 20:gracz.before_nerf_intel = atoi(linia.c_str()); break;
				case 22:gracz.counter_boost_intel = atoi(linia.c_str()); break;
				case 24:gracz.before_boost_intel = atoi(linia.c_str()); break;
				case 26:gracz.counter_nerf_luck = atoi(linia.c_str()); break;
				case 28:gracz.before_nerf_luck = atoi(linia.c_str()); break;
				case 30:gracz.counter_boost_luck = atoi(linia.c_str()); break;
				case 32:gracz.before_boost_luck = atoi(linia.c_str()); break;
				case 34:gracz.counter_nerf_charisma = atoi(linia.c_str()); break;
				case 36:gracz.before_nerf_charisma = atoi(linia.c_str()); break;
				case 38:gracz.counter_boost_charisma = atoi(linia.c_str()); break;
				case 40:gracz.before_boost_charisma = atoi(linia.c_str()); break;
				}
			}
			plik.close();
			system("cls");
			range(gracz);
			give_the_title(gracz);
			handlarz.load_merch();
			handlarz.add_prices(gracz);
			ui(gracz, bobby, handlarz, kowal, alchemik,szaman,lekarz);
			break;
		}
		case '3':
		{
			system("cls");
			cout << "Pseudoprogramisci: " << endl;
			cout << "-Aleksy" << endl;
			cout << endl << "Testerzy: " << endl;
			cout << "-Olaf" << endl;
			cout << "-Mariusz" << endl;
			cout << "-Ryba" << endl;
			cout << "-Marek" << endl;
			cout << "-Yeti" << endl;
			cout << "-Suchy" << endl;
			cout << endl << "Podziêkowania za drobn¹ pomoc w pisaniu kodu dla:" << endl;
			cout << "-Bauer" << endl;
			cout << "-Konstanty" << endl;
			cout << "-Yeti" << endl;
			cout << endl << "Podziêkowania za drobn¹ pomoc w wymyœlaniu mechanik dla:" << endl;
			cout << "-Suchy" << endl;
			cout << "-Pawe³" << endl;
			
			cout << endl;
			system("PAUSE");
			system("cls");
			break;
		}
		case '4':
		{
			while (1)
			{
				cout << "Czy napewno chcesz zamkn¹æ grê?" << endl;
				cout << "1.Tak" << endl;
				cout << "2.Nie" << endl;
				cout << "Twój wybór to: ";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					cout << "Zamykam gre" << endl;
					system("PAUSE");
					return 0;
				}
				case '2':
				{
					break;
				}
				default:
				{
					break;
				}
				break;
				}
				break;
			}
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}
