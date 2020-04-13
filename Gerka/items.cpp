#include "items.h"
#include "tabelka.h"

void rejection_use(int height, int startPoint)
{
	soundRejection();
	vector <string> message;
	message.push_back("You cannot use this item in this moment.");
}

bool useHpPotion(int height, int startPoint, player &gracz)
{
	vector <string> message = { "Do you want to open this door with a lockpick" };
	vector <string> options = { "Yes","No" };
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	if (highlight == 0)
	{
		if (gracz.hp >= gracz.max_hp)
		{
			soundRejection();
			message.push_back("You don't have to heal yourself.");
			tabSubmenuTextOnly(height, startPoint, message);
			return false;
		}
		else
		{
			soundDrink();
			gracz.hp += int(0.1 * gracz.max_hp);
			if (gracz.hp > gracz.max_hp)
			{
				gracz.hp = gracz.max_hp;
			}
			message.push_back("You are healing your wounds.");
			gracz.removeItem(height, startPoint, message, "Healing potion", 1);
			return true;
		}
	}
}

bool useLockpick(int height, int startPoint, player& gracz)
{
	vector <string> message = { "Do you want to open this door with a lockpick" };
	vector <string> options = { "Yes","No" };
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	if (highlight == 0)
	{
		int test = rand() % 100;
		int playerTestValue = rand() % 100 + gracz.luck + gracz.agility;
		if (playerTestValue > test)
		{
			message.clear();
			message.push_back("You managed to open the door without destroying the lockpick.");
			tabSubmenuTextOnly(height, startPoint, message);
			return true;
		}
		else
		{
			message.clear();
			message.push_back("You broke the lockpick while you opened the door, you throw it away.");
			gracz.removeItem(height, startPoint, message, "Lockpick",1);
			tabSubmenuTextOnly(height, startPoint, message);
			return false;
		}
	}
}

void infoHpPotion(int height, int startPoint)
{
	vector <string> message = { "The healing potion heals wounds and injuries" };
	tabSubmenuTextOnly(height, startPoint, message);
}

void infoLockpick(int height, int startPoint)
{
	vector <string> message = { "The lockpick opens closed doors." };
	tabSubmenuTextOnly(height, startPoint, message);
}

bool useItem(int height, int startPoint, string item, int useDropInfo,player &gracz)
{
	if (item == "Healing potion")
	{
		if (useDropInfo == 0 && gracz.findUsageItem("Healing potion") == true)
		{
			return useHpPotion(height, startPoint, gracz);
		}
		else if (useDropInfo == 1 && gracz.findUsageItem("MHealing potion") == true)
		{
			vector <string> message = {"You are dropping a healing potion"};
			gracz.removeItem(height, startPoint, message, item,1);
			return 0;
		}
		else if ((useDropInfo == 0 || useDropInfo == 1) && gracz.findUsageItem("Healing potion") == false)
		{
			vector <string> message = { "You don't have any healing potions" };
			tabSubmenuTextOnly(height, startPoint, message);
			return 0;
		}
		else if (useDropInfo == 2)
		{
			infoHpPotion(height,startPoint);
			return 0;
		}
	}
	else if (item == "Lockpick")
	{
		if (useDropInfo == 0 && gracz.findUsageItem("Lockpick") == true)
		{
			return useLockpick(height, startPoint, gracz);
		}
		else if (useDropInfo == 1 && gracz.findUsageItem("Lockpick") == true)
		{
			vector <string> message = { "You are dropping a lockpick" };
			gracz.removeItem(height, startPoint, message, item,1);
			return 0;
		}
		else if ((useDropInfo == 0 || useDropInfo == 1) && gracz.findUsageItem("Lockpick") == false)
		{
			vector <string> message = { "You don't have any lockpicks" };
			tabSubmenuTextOnly(height, startPoint, message);
			return 0;
		}
		else if (useDropInfo == 2)
		{
			infoLockpick(height, startPoint);
			return 0;
		}
	}
}
