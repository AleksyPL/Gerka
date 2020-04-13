#include "quest.h"
#include "dwellers.h"

void checkQuestStatus(player &gracz)
{
	if (gracz.quest_name != "")
	{
		shaman szaman;
		if (szaman.questIDInfo() == "s00")
		{
			if (gracz.findUsageItem("Ludzki z¹b") == 1)
			{
				int pom = gracz.findUsageItemIndex("Ludzki z¹b");
				if (gracz.inventory_usage_amount[pom] == 3)
				{
					gracz.quest_complete = 1;
				}
			}
		}
	}
}