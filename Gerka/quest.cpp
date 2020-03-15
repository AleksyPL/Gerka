#include "quest.h"
#include "dwellers.h"

void check_quest_status(player &gracz)
{
	if (gracz.quest_name != "")
	{
		shaman szaman;
		if (szaman.quest_id_info() == "s00")
		{
			if (gracz.find_usage_item("Ludzki z¹b") == 1)
			{
				int pom = gracz.find_usage_item_index("Ludzki z¹b");
				if (gracz.inventory_usage_amount[pom] == 3)
				{
					gracz.quest_complete = 1;
				}
			}
		}
	}
}