#include "tabelka.h"
#include "trade_mode.h"


void changeData(string whichFunction, string whichSide,string (&array)[21], int card)
{
	if (whichFunction == "General Store")
	{

	}
	else if (whichFunction == "Bladesmith Shop")
	{
		
	}
}

void tradeModeGeneralStore(player &gracz, generalStoreSeller &handlarz)
{
	string functionToSwitchData = "General Store";
	bool anythingSoldOrBought = false;
	int leftSideCard = 0;
	int rightSideCard = 0;
	int highlight = 0;
	string top_side[3];
	string left_side[21];
	string right_side[21];
	int right_side_prices[20];
	bool exit = false;
	vector <string> bottomSide = { "<-","->","Return","<-","->" };
	while (exit == false)
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
				handlarz.loadItems("./txt/trader/items_trash.txt");
			}
			else if (leftSideCard == 1)
			{
				left_side[20] = handlarz.name + " - Low items";
				handlarz.loadItems("./txt/trader/items_low.txt");
			}
			else if (leftSideCard == 2)
			{
				left_side[20] = handlarz.name + " - Mid items";
				handlarz.loadItems("./txt/trader/items_mid.txt");
			}
			else if (leftSideCard == 3)
			{
				left_side[20] = handlarz.name + " - Rare items";
				handlarz.loadItems("./txt/trader/items_high.txt");
			}
			for (int i = 0; i < 20; i++)
			{
				handlarz.itemPrice[i] = handlarz.loadPrices(handlarz.itemName[i], "./txt/mix/items_prices.txt");
				if (handlarz.itemName[i] != "")
				{
					left_side[i] = handlarz.makeString(66, handlarz.itemName[i], 1, handlarz.itemPrice[i]);
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
					right_side_prices[i] = handlarz.loadPrices(right_side[i], "./txt/mix/items_prices.txt");
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
					right_side_prices[i] = handlarz.loadPrices(right_side[i], "./txt/mix/items_prices.txt");
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
					right_side_prices[i] = handlarz.loadPrices(right_side[i], "./txt/mix/items_prices.txt");
					if (right_side[i] != "")
					{
						right_side[i] = handlarz.makeString(66, right_side[i], gracz.inventory_crafting_amount[20 + i], right_side_prices[i]);
					}
				}
			}
		}
		top_side[0] = handlarz.name + "'s gold: " + to_string(handlarz.goldInfo());
		top_side[1] = "Trade";
		top_side[2] = gracz.nazwa + "'s gold: " + to_string(gracz.gold);
		if (anythingSoldOrBought==true)
		{
			findANewHighlight(highlight, left_side, right_side);
		}
		highlight = tabTrade(highlight, top_side, left_side, right_side, bottomSide);
		if (highlight < 20)
		{
			handlarz.buyItem(27, 28, gracz, handlarz.itemName[highlight],1,handlarz.loadPrices(handlarz.itemName[highlight], "./txt/mix/items_prices.txt"),anythingSoldOrBought);
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
				exit = true;
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
void tradeModeBladesmithShop(player &gracz, bladesmith &miecznik)
{
	string functionToSwitchData = "Bladesmith Shop";
	bool anythingSoldOrBought = false;
	int leftSideCard = 0;
	int rightSideCard = 0;
	int highlight = 0;
	string top_side[3];
	string left_side[21];
	string right_side[21];
	int right_side_prices[20];
	miecznik.generateMerch(gracz);
	vector <string> bottomSide = { "<-","->","Return","<-","->" };
	top_side[1] = "Trade";
	bool exit = false;
	while (exit == false)
	{
		top_side[0] = miecznik.name + "'s gold: " + to_string(miecznik.goldInfo());
		top_side[2] = gracz.nazwa + "'s gold: " + to_string(gracz.gold);
		for (int i = 0; i < 20; i++)
		{
			left_side[i] = "";
			right_side[i] = "";
			right_side_prices[i] = 0;
		}
		//handlarz
		{
			/*if (gracz.level < 10)
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
			}*/
			if (leftSideCard == 0)
			{
				left_side[20] = miecznik.name + " - Weapons";
				//miecznik.loadItems("./txt/bladesmith/weapons.txt");
			}
			for (int i = 0; i < 20; i++)
			{
				//handlarz.itemPrice[i] = handlarz.loadPrices(handlarz.itemName[i], "./txt/mix/items_prices.txt");
				if (miecznik.itemName[i] != "")
				{
					if (miecznik.weaponsRarity[i] == true)
					{
						string temp = "[RARE]" + miecznik.itemName[i] + "(" + to_string(miecznik.weaponsDamage[i]) + ")";
						left_side[i] = miecznik.makeString(66, temp, 1, miecznik.itemPrice[i]);
					}
					else
					{
						if (miecznik.weaponsDamage[i] == 0)
						{
							left_side[i] = miecznik.makeString(66, miecznik.itemName[i], 1, miecznik.itemPrice[i], true);
						}
						else
						{
							string temp = miecznik.itemName[i] + "(" + to_string(miecznik.weaponsDamage[i]) + ")";
							left_side[i] = miecznik.makeString(66, temp, 1, miecznik.itemPrice[i]);
						}
					}
				}
			}
		}
		// gracz
		{
			if (rightSideCard == 0)
			{
				right_side[20] = gracz.nazwa + " - Weapons";
				if (gracz.isTheWeaponRare == true)
				{
					right_side[0] = "[RARE]" + gracz.weaponName;
				}
				else
				{
					right_side[0] = gracz.weaponName;
				}
				right_side_prices[0] = gracz.weaponPrice;
				right_side[0] = miecznik.makeString(66, right_side[0], 1, right_side_prices[0]);
				/*for (int i = 0; i < 20; i++)
				{
					right_side[i] = gracz.inventory_usage[i];
					right_side_prices[i] = handlarz.loadPrices(right_side[i], "./txt/mix/items_prices.txt");
					if (right_side[i] != "")
					{
						right_side[i] = handlarz.makeString(66, right_side[i], gracz.inventory_usage_amount[i], right_side_prices[i]);
					}
				}*/
			}
		}
		if (anythingSoldOrBought == true)
		{
			findANewHighlight(highlight, left_side, right_side);
		}
		highlight = tabTrade(highlight, top_side, left_side, right_side, bottomSide);
		if (highlight < 20)
		{
			miecznik.buyItem(27, 28, gracz, highlight);
		}
		else if (highlight >= 20 && highlight < 40)
		{
			miecznik.sellItem(27, 28, gracz);
		}
		else
		{
			switch (highlight)
			{
			/*case 40:
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
			}*/
			case 42:
			{
				exit = true;
			}
			/*case 43:
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
			}*/
			}
		}
	}
}