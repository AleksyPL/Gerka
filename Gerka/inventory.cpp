#include "inventory.h"
#include "tabelka.h"
#include "level_up.h"

void print_option(string item)
{
	cout << "Co chcesz zrobiæ z przedmiotem " << item << " ?" << endl;
	cout << "1. U¿yj" << endl;
	cout << "2. Wyrzuæ" << endl;
	cout << "3. Opuœæ menu wyboru" << endl;
	cout << "Twój wybór to: ";
}

player what_to_do(player &gracz,string menu[60], int menu_amount[60], string info[7],int i)
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
					tab_items(gracz, menu, menu_amount, info);
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
		string menu[100];
		int menu_amount[60];
		string info[7];
		info[0] = "";
		info[1] = "";
		info[2] = "W: WYJD Z EKWIP.";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		for (int i = 0; i < 20; i++)
		{
			if (gracz.inventory_usage[i] == "" && gracz.inventory_usage_amount[i] == 0)
			{
				menu[i] = "";
				menu_amount[i] = 0;
			}
			else
			{
				menu[i] = gracz.inventory_usage[i];
				menu_amount[i] = gracz.inventory_usage_amount[i];
			}
			if (gracz.inventory_crafting[i] == "" && gracz.inventory_crafting_amount[i] == 0)
			{
				menu[20 + i] = "";
				menu_amount[20 + i] = 0;
			}
			else
			{
				menu[20 + i] = gracz.inventory_crafting[i];
				menu_amount[20 + i] = gracz.inventory_crafting_amount[i];
			}
			if (gracz.inventory_crafting[20 + i] == "" && gracz.inventory_crafting_amount[20 + i] == 0)
			{
				menu[40 + i] = "";
				menu_amount[40 + i] = 0;
			}
			else
			{
				menu[40 + i] = gracz.inventory_crafting[20 + i];
				menu_amount[40 + i] = gracz.inventory_crafting_amount[20 + i];
			}
		}
		{
			if (gracz.count_free_fields_usage() == 20)
			{
				menu[0] = "BRAK PRZEDMIOTÓW";
			}
			if (gracz.count_free_fields_alchemy() == 20)
			{
				menu[20] = "BRAK PRZEDMIOTÓW ALCHEMICZNYCH";
			}
			if (gracz.count_free_fields_forge() == 20)
			{
				menu[40] = "BRAK PRZEDMIOTÓW KOWALSKICH";
			}
		}
		/* 1*/menu[60] = "PUNKTY HE£MU";
		/* 2*/menu[61] = "PUNKTY NAPIERŒNIKA";
		/* 3*/menu[62] = "PUNKTY RÊKAWIC";
		/* 4*/menu[63] = "PUNKTY SPODNI";
		/* 5*/menu[64] = "PUNKTY BUTÓW";
		/* 6*/menu[65] = "NAZWA BRONI";
		/* 7*/menu[66] = "OBRA¯ENIA BRONI";
		/* 8*/menu[67] = "";
		/* 9*/menu[68] = "";
		/*10*/menu[69] = "";
		/*11*/menu[70] = "";
		/*12*/menu[71] = "";
		/*13*/menu[72] = "";
		/*14*/menu[73] = "";
		/*15*/menu[74] = "";
		/*16*/menu[75] = "";
		/*17*/menu[76] = "";
		/*18*/menu[77] = "";
		/*19*/menu[78] = "";
		/*20*/menu[79] = "";

		/* 1*/menu[80] = to_string(gracz.helmet);
		/* 2*/menu[81] = to_string(gracz.chestplate);
		/* 3*/menu[82] = to_string(gracz.gloves);
		/* 4*/menu[83] = to_string(gracz.pants);
		/* 5*/menu[84] = to_string(gracz.shoes);
		/* 6*/menu[85] = gracz.weapon_name;
		/* 7*/menu[86] = to_string(gracz.weapon);
		/* 8*/menu[87] = "";
		/* 9*/menu[88] = "";
		/*10*/menu[89] = "";
		/*11*/menu[90] = "";
		/*12*/menu[91] = "";
		/*13*/menu[92] = "";
		/*14*/menu[93] = "";
		/*15*/menu[94] = "";
		/*16*/menu[95] = "";
		/*17*/menu[96] = "";
		/*18*/menu[97] = "";
		/*19*/menu[98] = "";
		/*20*/menu[99] = "";
		tab_items(gracz,menu, menu_amount,info);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
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