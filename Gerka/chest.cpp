#include "chest.h"
#include "tabelka.h"

void enter_chest_mode(player &gracz, chest &krzynka)
{
	/*int tryb = 0;
	string info[7];
	info[0] = "W:ZAMKNIJ SKRZYNIÊ ";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";*/
	int highlight = 0;
	int card = 0;
	string leftSide[21];
	string rightSide[21];
	vector <string> bottomSide = {"<-","Return","->"};
	bool leaveWhile = false;
	do
	{
		for (int i = 0; i < 20; i++)
		{
			leftSide[i] = "";
			rightSide[i] = "";
		}
		if (card == 0)
		{
			leftSide[20] = "Items - Usable";
			if (gracz.count_free_fields_usage() == 20)
			{
				leftSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (gracz.inventory_usage[i] != "" && gracz.inventory_usage_amount[i] != 1)
					{
						leftSide[i] = gracz.inventory_usage[i] + " x" + to_string(gracz.inventory_usage_amount[i]);
					}
					else if (gracz.inventory_usage[i] != "" && gracz.inventory_usage_amount[i] == 1)
					{
						leftSide[i] = gracz.inventory_usage[i];
					}
				}
			}
			rightSide[20] = "Chest - Usable";
			if (krzynka.count_free_fields_usage() == 20)
			{
				rightSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (krzynka.menu[i] != "" && krzynka.menu_amount[i] != 1)
					{
						rightSide[i] = krzynka.menu[i] + " x" + to_string(krzynka.menu_amount[i]);
					}
					else if (krzynka.menu[i] != "" && krzynka.menu_amount[i] == 1)
					{
						rightSide[i] = krzynka.menu[i];
					}
				}
			}
		}
		else if (card == 1)
		{
			leftSide[20] = "Items - Alchemy";
			if (gracz.count_free_fields_alchemy() == 20)
			{
				leftSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (gracz.inventory_crafting[i] != "" && gracz.inventory_crafting_amount[i] != 1)
					{
						leftSide[i] = gracz.inventory_crafting[i] + " x" + to_string(gracz.inventory_crafting_amount[i]);
					}
					else if (gracz.inventory_crafting[i] != "" && gracz.inventory_crafting_amount[i] == 1)
					{
						leftSide[i] = gracz.inventory_crafting[i];
					}
				}
			}
			rightSide[20] = "Chest - Alchemy";
			if (krzynka.count_free_fields_alchemy() == 20)
			{
				rightSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (krzynka.menu[20 + i] != "" && krzynka.menu_amount[20 + i] != 1)
					{
						rightSide[i] = krzynka.menu[20 + i] + " x" + to_string(krzynka.menu_amount[20 + i]);
					}
					else if (krzynka.menu[20 + i] != "" && krzynka.menu_amount[20 + i] == 1)
					{
						rightSide[i] = krzynka.menu[20 + i];
					}
				}
			}
		}
		else if (card == 2)
		{
			leftSide[20] = "Items - Smithery";
			if (gracz.count_free_fields_forge() == 20)
			{
				leftSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (gracz.inventory_crafting[20 + i] != "" && gracz.inventory_crafting_amount[20 + i] != 1)
					{
						leftSide[i] = gracz.inventory_crafting[20 + i] + " x" + to_string(gracz.inventory_crafting_amount[20 + i]);
					}
					else if (gracz.inventory_crafting[20 + i] != "" && gracz.inventory_crafting_amount[20 + i] == 1)
					{
						leftSide[i] = gracz.inventory_crafting[20 + i];
					}
				}
			}
			rightSide[20] = "Chest - Smithery";
			if (krzynka.count_free_fields_forge() == 20)
			{
				rightSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (krzynka.menu[40 + i] != "" && krzynka.menu_amount[40 + i] != 1)
					{
						rightSide[i] = krzynka.menu[40 + i] + " x" + to_string(krzynka.menu_amount[40 + i]);
					}
					else if (krzynka.menu[40 + i] != "" && krzynka.menu_amount[40 + i] == 1)
					{
						rightSide[i] = krzynka.menu[40 + i];
					}
				}
			}
		}
		highlight = tabItemsLeftAndRight(highlight, "Chest", leftSide, rightSide, bottomSide);
		if (highlight < 20)
		{
			krzynka.move_to_chest(27,28,highlight*(card+1), gracz);
		}
		else if (highlight >= 20 && highlight < 40)
		{
			krzynka.move_to_player(27, 28, (highlight-20) * (card + 1), gracz);
		}
		else
		{
			switch (highlight)
			{
			case 40:
			{
				if (card != 0)
				{
					card--;
				}
				break;
			}
			case 41:
			{
				leaveWhile = true;
			}
			case 42:
			{
				if (card < 2)
				{
					card++;
				}
				break;
			}
			}
		}
	} while (leaveWhile == false);
}
