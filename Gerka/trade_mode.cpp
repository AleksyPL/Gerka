#include "tabelka.h"
#include "trade_mode.h"

void findANewHighlight(int& highlight, string left_side[20], string right_side[20])
{
	int leftSideBorder = 19;
	int rightSideBorder = 19;
	for (int i = 0; i < 20; i++)
	{
		if (left_side[i] == "")
		{
			leftSideBorder--;
		}
		if (right_side[i] == "")
		{
			rightSideBorder--;
		}
	}
	if (highlight < 20)
	{
		while (highlight > leftSideBorder)
		{
			highlight--;
		}
		if (leftSideBorder == 0 && left_side[0] == "")
		{
			highlight = 40;
		}
	}
	else if (highlight >= 20 && highlight < 40)
	{
		while (highlight>20+ rightSideBorder)
		{
			highlight--;
		}
		if (rightSideBorder == 0 && right_side[0] == "")
		{
			while (highlight < leftSideBorder)
			{
				highlight--;
			}
			if (leftSideBorder == 0 && left_side[0] == "")
			{
				highlight = 40;
			}
		}
	}
}

player trade_mode(player &gracz, seller &handlarz)
{
	bool anythingSoldOrBought = false;
	int leftSideCard = 0;
	int rightSideCard = 0;
	int highlight = 0;
	string top_side[3];
	string left_side[21];
	string right_side[21];
	int right_side_prices[20];
	vector <string> bottomSide = { "<-","->","Return","<-","->" };
	while (1)
	{
		for (int i = 0; i < 20; i++)
		{
			left_side[i] = "";
			right_side[i] = "";
			right_side_prices[i] = 0;
		}
		//handlarz
		{
			if (gracz.level < 10)
			{
				if (leftSideCard > 1)
				{
					leftSideCard = 1;
				}
			}
			else if (gracz.level < 20)
			{
				if (leftSideCard > 2)
				{
					leftSideCard = 2;
				}
			}
			if (leftSideCard == 0)
			{
				left_side[20] = handlarz.name + " - Trash items";
			}
			else if (leftSideCard == 1)
			{
				left_side[20] = handlarz.name + " - Low items";
			}
			else if (leftSideCard == 2)
			{
				left_side[20] = handlarz.name + " - Mid items";
			}
			else if (leftSideCard == 3)
			{
				left_side[20] = handlarz.name + " - Rare items";
			}
			handlarz.loadMerch(leftSideCard);
			for (int i = 0; i < 20; i++)
			{
				handlarz.menu_price[i] = handlarz.loadPrices(handlarz.menu_items[i]);
				if (handlarz.menu_items[i] != "")
				{
					left_side[i] = handlarz.makeString(66, handlarz.menu_items[i], 1, handlarz.menu_price[i]);
				}
			}
		}
		// gracz
		{
			if (rightSideCard == 0)
			{
				right_side[20] = gracz.nazwa + " - Usable items";
				for (int i = 0; i < 20; i++)
				{
					right_side[i] = gracz.inventory_usage[i];
					right_side_prices[i] = handlarz.loadPrices(right_side[i]);
					if (right_side[i] != "")
					{
						right_side[i] = handlarz.makeString(66, right_side[i], gracz.inventory_usage_amount[i], right_side_prices[i]);
					}
				}
			}
			else if (rightSideCard == 1)
			{
				right_side[20] = gracz.nazwa + " - Alchemy items";
				for (int i = 0; i < 20; i++)
				{
					right_side[i] = gracz.inventory_crafting[i];
					right_side_prices[i] = handlarz.loadPrices(right_side[i]);
					if (right_side[i] != "")
					{
						right_side[i] = handlarz.makeString(66, right_side[i], gracz.inventory_crafting_amount[i], right_side_prices[i]);
					}
				}
			}
			else if (rightSideCard == 2)
			{
				right_side[20] = gracz.nazwa + " - Smithery items";
				for (int i = 0; i < 20; i++)
				{
					right_side[i] = gracz.inventory_crafting[20 + i];
					right_side_prices[i] = handlarz.loadPrices(right_side[i]);
					if (right_side[i] != "")
					{
						right_side[i] = handlarz.makeString(66, right_side[i], gracz.inventory_crafting_amount[20 + i], right_side_prices[i]);
					}
				}
			}
		}
		top_side[0] = handlarz.name + "'s gold: " + to_string(handlarz.gold_info());
		top_side[1] = "Trade";
		top_side[2] = gracz.nazwa + "'s gold: " + to_string(gracz.gold);
		if (anythingSoldOrBought==true)
		{
			findANewHighlight(highlight, left_side, right_side);
		}
		highlight = tabTrade(highlight, top_side, left_side, right_side, bottomSide);
		if (highlight < 20)
		{
			handlarz.buyItem(27, 28, gracz, handlarz.menu_items[highlight],1,handlarz.loadPrices(handlarz.menu_items[highlight]),anythingSoldOrBought);
		}
		else if (highlight >= 20 && highlight < 40)
		{
			handlarz.sellItem(27, 28, gracz, gracz.inventory_usage[highlight - 20], gracz.inventory_usage_amount[highlight - 20], right_side_prices[highlight - 20],anythingSoldOrBought);
		}
		else
		{
			switch (highlight)
			{
			case 40:
			{
				if (leftSideCard != 0)
				{
					leftSideCard--;
				}
				break;
			}
			case 41:
			{
				if (leftSideCard < 3)
				{
					leftSideCard++;
				}
				break;
			}
			case 42:
			{
				return gracz;
			}
			case 43:
			{
				if (rightSideCard != 0)
				{
					rightSideCard--;
				}
				break;
			}
			case 44:
			{
				if (rightSideCard < 2)
				{
					rightSideCard++;
				}
				break;
			}
			}
		}
	}
}