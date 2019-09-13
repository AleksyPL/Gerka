#include "inventory.h"
#include "tabelka.h"
#include "level_up.h"
#include "items.h"

void print_option(string nazwa, int ilosc)
{
	cout << "Co chcesz zrobiÊ z przedmiotem " << nazwa << " (" << ilosc << ") ?"<< endl;
	cout << "1. Uøyj" << endl;
	cout << "2. WyrzuÊ" << endl;
	cout << "3. Informacje o przedmiocie" << endl;
	cout << "4. OpuúÊ menu wyboru" << endl;
	cout << "TwÛj wybÛr to: ";
}
void do_operation(player &gracz,string nazwa, int ilosc, string info[8])
{
	if (ilosc > 0)
	{
		int tryb = 0;
		do
		{
			print_option(nazwa, ilosc);
			string wyb;
			cin >> wyb;
			switch (wyb[0])
			{
			case '1':
			{
				use_item(nazwa,1,gracz,info[0]);
				tryb = 1;
				break;
			}
			case '2':
			{
				use_item(nazwa, 2, gracz,info[0]);
				tryb = 1;
				break;
			}
			case '3':
			{
				use_item(nazwa, 3, gracz,info[0]);
				tryb = 1;
				break;
			}
			case '4':
			{
				tryb = 1;
				break;
			}
			default:
			{
				system("cls");
				tab_items(gracz, info);
			}
			}
		} while (tryb == 0);
	}
}
player enter_inventory(player &gracz)
{
	while (1)
	{
		level_up(gracz);
		system("cls");
		string menu[40];
		string info[8];
		info[0] = "EKWIPUNEK";
		info[1] = "W: WYJDè Z EKWIP.";
		info[2] = "";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[6] = "";
		tab_items(gracz,info);
		cout << "TwÛj wybÛr to: ";
		string wyb;
		cin >> wyb;
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case '1':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[0], gracz.inventory_usage_amount[0], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '2':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[1], gracz.inventory_usage_amount[1], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '3':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[2], gracz.inventory_usage_amount[2], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '4':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[3], gracz.inventory_usage_amount[3], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '5':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[4], gracz.inventory_usage_amount[4], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '6':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[5], gracz.inventory_usage_amount[5], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '7':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[6], gracz.inventory_usage_amount[6], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '8':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[7], gracz.inventory_usage_amount[7], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '9':
		{
			if (wyb.size() == 1)
			{
				do_operation(gracz, gracz.inventory_usage[8], gracz.inventory_usage_amount[8], info);
				break;
			}
			else if (wyb[1] == '0')
			{
				break;
			}
			else if (wyb[1] == '1')
			{
				break;
			}
			else if (wyb[1] == '2')
			{
				break;
			}
			else if (wyb[1] == '3')
			{
				break;
			}
			else if (wyb[1] == '4')
			{
				break;
			}
			else if (wyb[1] == '5')
			{
				break;
			}
			else if (wyb[1] == '6')
			{
				break;
			}
			else if (wyb[1] == '7')
			{
				break;
			}
			else if (wyb[1] == '8')
			{
				break;
			}
			else if (wyb[1] == '9')
			{
				break;
			}
			break;
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