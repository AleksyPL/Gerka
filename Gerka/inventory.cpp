#include "biblioteki.h"
#include "tabelka.h"
#include "inventory.h"

void print_option(string item)
{
	cout << "Co chcesz zrobiæ z przedmiotem " << item << " ?" << endl;
	cout << "1. U¿yj" << endl;
	cout << "2. Wyrzuæ" << endl;
	cout << "3. Opuœæ menu wyboru" << endl;
	cout << "Twój wybór to: ";
}

player what_to_do(player &gracz,string menu[60],int i)
{
	if (i == 40)
	{
		if (menu[40] != "")
		{
			while (1)
			{
				print_option(menu[40]);
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					gracz.use_hp_potion();
					return gracz;
				}
				case '2':
				{
					gracz.drop_hp_potion();
					return gracz;
				}
				case '3':
				{
					return gracz;
				}
				default:
				{
					system("cls");
					tab_items(gracz, menu);
				}
				}
			}
			
		}
		else
		{
			cout << "BRAK PRZEDMIOTU" << endl;
		}
	}
}
player enter_inventory(player &gracz)
{
	while (1)
	{
		level_up(gracz);
		system("cls");
		string menu[60];
		{
			for (int i = 0; i < 20; i++)
			{
				if (gracz.inventory_usage[i] == "" && gracz.inventory_usage_amount[i] == 0)
				{
					menu[i] = "";
				}
				else
				{
					menu[i] = gracz.inventory_usage[i] + " x" + to_string(gracz.inventory_usage_amount[i]);
				}
				if (gracz.inventory_crafting[i] == "" && gracz.inventory_crafting_amount[i] == 0)
				{
					menu[20 + i] = "";
				}
				else
				{
					menu[20 + i] = gracz.inventory_crafting[i] + " x" + to_string(gracz.inventory_crafting_amount[i]);
				}
			}
			
			menu[40] = gracz.return_amount_of_hp_potions();
			menu[41] = gracz.return_amount_of_str_potions();
			menu[42] = gracz.return_amount_of_agility_potions();
			menu[43] = gracz.return_amount_of_intel_potions();
			menu[44] = gracz.return_amount_of_charisma_potions();
			menu[45] = gracz.return_amount_of_luck_potions();
			menu[46] = "";
			menu[47] = "";
			menu[48] = "";
			menu[49] = "";
			menu[50] = "";
			menu[51] = "";
			menu[52] = "";
			menu[53] = "";
			menu[54] = "";
			menu[55] = "";
			menu[56] = "";
			menu[57] = "";
			menu[58] = "";
			menu[59] = "";
			{
				int licznik = 0;
				int licznik1 = 0;
				int licznik2 = 0;
				for (int i = 0; i < 20; i++)
				{
					if (menu[i] == "")
					{
						licznik = licznik +1;
					}
					if (menu[20 + i] == "")
					{
						licznik1 = licznik1 + 1;
					}
					if (menu[40 + i] == "")
					{
						licznik2 = licznik2 + 1;
					}
					if (licznik == 20)
					{
						menu[0] = "BRAK PRZEDMIOTÓW";
					}
					if (licznik1 == 20)
					{
						menu[20] = "BRAK PRZEDMIOTÓW";
					}
					if (licznik2 == 20)
					{
						menu[40] = "BRAK MIKSTUR";
					}
				}
			}
		}
		tab_items(gracz,menu);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '4':
		{
			if (wyb[1] == '1')
			{
				what_to_do(gracz, menu, 40);
				break;
			}
			if (wyb[1] == '2')
			{
				what_to_do(gracz, menu, 41);
				break;
			}
			if (wyb[1] == '3')
			{
				what_to_do(gracz, menu, 42);
				break;
			}
			if (wyb[1] == '4')
			{
				what_to_do(gracz, menu, 43);
				break;
			}
			if (wyb[1] == '5')
			{
				what_to_do(gracz, menu, 44);
				break;
			}
			if (wyb[1] == '6')
			{
				what_to_do(gracz, menu, 45);
				break;
			}
			break;
		}
		case 'W':
		{
			return gracz;
		}
		case 'w':
		{
			return gracz;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}