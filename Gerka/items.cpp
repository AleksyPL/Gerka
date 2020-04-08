#include "items.h"
#include "tabelka.h"

void rejection_use()
{
	soundRejection();
	//cout << endl << "Nie mo¿esz u¿yæ tego przedmiotu w tym momencie" << endl;
	system("PAUSE");
}

//void useHpPotion(player &gracz)
//{
//	int index = gracz.findUsageItem_index("Mikstura ¿ycia");
//	if (gracz.hp >= gracz.max_hp)
//	{
//		soundRejection();
//		cout << "Nie potrzebujesz siê leczyæ" << endl;
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
//		gracz.use_item("Mikstura ¿ycia", "Leczysz siê");
//	}
//	else
//	{
//		cout << endl << "Nie masz przy sobie ¿adnych mikstur lecz¹cych" << endl;
//		system("PAUSE");
//	}
//}

void infoHpPotion(int height, int startPoint)
{
	vector <string> message = { "The healing potion heals wounds and injuries" };
	tabSubmenuTextOnly(height, startPoint, message);
}

void useItem(int height, int startPoint, string item, int useDropInfo,player &gracz)
{
	if (item == "Mikstura ¿ycia")
	{
		if (useDropInfo == 1)
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
			soundRejection();
		}
		else if (useDropInfo == 2)
		{
			gracz.dropItem(height, startPoint, item);
		}
		else if (useDropInfo == 3)
		{
			infoHpPotion(height,startPoint);
		}
	}
}
