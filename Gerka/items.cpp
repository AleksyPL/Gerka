#include "items.h"

void rejection_use()
{
	sound_rejection();
	cout << endl << "Nie mo�esz u�y� tego przedmiotu w tym momencie" << endl;
	system("PAUSE");
}

//void use_hp_potion(player &gracz)
//{
//	int index = gracz.find_usage_item_index("Mikstura �ycia");
//	if (gracz.hp >= gracz.max_hp)
//	{
//		sound_rejection();
//		cout << "Nie potrzebujesz si� leczy�" << endl;
//		system("PAUSE");
//	}
//	else if (gracz.inventory_usage_amount[index] > 0)
//	{
//		sound_drink();
//		gracz.hp = gracz.hp + (0.1*gracz.max_hp);
//		if (gracz.hp > gracz.max_hp)
//		{
//			gracz.hp = gracz.max_hp;
//		}
//		gracz.use_item("Mikstura �ycia", "Leczysz si�");
//	}
//	else
//	{
//		cout << endl << "Nie masz przy sobie �adnych mikstur lecz�cych" << endl;
//		system("PAUSE");
//	}
//}

void info_hp_potion()
{
	cout << endl << "Leczy rany" << endl;
	system("PAUSE");
}

void use_item(string name, int tryb,player &gracz,string info)
{
	if (name == "Mikstura �ycia")
	{
		if (tryb == 1)
		{
			typedef player(*Shit_fun)(player);
			Shit_fun shit;
			HINSTANCE cos = LoadLibrary("./dll/MyDll.dll");
			if (cos)
			{
				shit = (Shit_fun)GetProcAddress(cos, "use_hp_potion");
				if (shit)
				{
					shit(gracz);
				}
				FreeLibrary(cos);
			}
			gracz;
		}
		else if (tryb == 2)
		{
			gracz.drop_item(name, "� mikstur� �ycia");
		}
		else if (tryb == 3)
		{
			info_hp_potion();
		}
	}
}
