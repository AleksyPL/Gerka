#include "fight_mode.h"
#include "tabelka.h"
#include "zakres.h"


void victoryCondition(int height, int startPoint, Mob enemy, player& gracz, bool &victory, string &itemName)
{
	if (enemy.HP <= 0)
	{
		sound_success();
		vector <string> message;
		message.push_back("You won!");
		message.push_back("Next to the " + enemy.mobName + " you found " + to_string(enemy.returnDroppedGold()) + " gold.");
		message.push_back("You get " + to_string(enemy.XP) + " experience points for the fight.");
		gracz.exp += enemy.XP;
		gracz.gold += enemy.returnDroppedGold();
		tabSubmenuTextOnly(height, startPoint, message);
		range(gracz);
		pickUpItemDroppedByEnemy(11, 44, enemy, gracz, itemName);
		victory = true;
	}
	else
	{
		victory = false;
	}
}
void pickUpItemDroppedByEnemy(int height, int startPoint, Mob enemy, player& gracz, string& itemName)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (enemy.thisMonsterAreAbleToDropItem == true)
	{
		if (findItemOnList(enemy.droppedItem) == "Usable")
		{
			if (gracz.count_free_fields_usage() != 0)
			{
				vector <string> message = { "Do you want to take " + enemy.droppedItem + "?" };
				int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (highlight == 0)
				{
					gracz.add_usage_item(enemy.droppedItem, 0, 1, height, startPoint);
				}
				else
				{
					message.push_back("You leave " + enemy.droppedItem + " on the ground.");
					itemName = enemy.droppedItem;
				}
			}
			else
			{
				message.push_back("Your backpack is full");
				message.push_back("You leave " + enemy.droppedItem + " on the ground.");
				itemName = enemy.droppedItem;
			}
		}
		else if (findItemOnList(enemy.droppedItem) == "Alchemy")
		{
			if (gracz.count_free_fields_alchemy() != 0)
			{
				vector <string> message = { "Do you want to take " + enemy.droppedItem + "?" };
				int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (highlight == 0)
				{
					gracz.add_crafting_alchemy_item(enemy.droppedItem, 0, 1, height, startPoint);
				}
				else
				{
					message.push_back("You leave " + enemy.droppedItem + " on the ground.");
					itemName = enemy.droppedItem;
				}
			}
			else
			{
				message.push_back("Your backpack is full");
				message.push_back("You leave " + enemy.droppedItem + " on the ground.");
				itemName = enemy.droppedItem;
			}
		}
		else if (findItemOnList(enemy.droppedItem) == "Smithery")
		{
			if (gracz.count_free_fields_forge() != 0)
			{
				vector <string> message = { "Do you want to take " + enemy.droppedItem + "?" };
				int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (highlight == 0)
				{
					gracz.add_crafting_forge_item(enemy.droppedItem, 0, 1, height, startPoint);
				}
				else
				{
					message.push_back("You leave " + enemy.droppedItem + " on the ground.");
					itemName = enemy.droppedItem;
				}
			}
			else
			{
				message.push_back("Your backpack is full");
				message.push_back("You leave " + enemy.droppedItem + " on the ground.");
				itemName = enemy.droppedItem;
			}
		}
		else
		{
			message.push_back("Error");
		}
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}

Mob loadMonsterData(string monsterName)
{
	string path;
	if (monsterName == "Citizen")
	{
		int random = rand() % 3;
		if (random == 0)
		{
			path = "./txt/mobki/citizen_small.txt";
		}
		else if (random == 1)
		{
			path = "./txt/mobki/citizen_medium.txt";
		}
		else
		{
			path = "./txt/mobki/citizen_high.txt";
		}
	}
	else if (monsterName == "Bandit")
	{
		path = "./txt/mobki/bandit.txt";
	}
	else if (monsterName == "Skeleton")
	{
		path = "./txt/mobki/skeleton.txt";
	}
	else if (monsterName == "Dog")
	{
		path = "./txt/mobki/dog.txt";
	}	
	else
	{
		path = "./txt/mobki/default.txt";
	}
	Mob enemy(path);
	return enemy;
}

player enterFightMode(player gracz, string monsterName, bool playerGoesFirst, bool &victory, string &itemName)
{
	sound_start_fight();
	int highlight = 0;
	string playerInfo[18];
	playerInfo[0] = "Health points: " + to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
	playerInfo[1] = "Experience points: " + to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level)+ "(" + to_string(gracz.level) + ")";
	if (gracz.before_boost_str != 0)
	{
		playerInfo[2] = "Strength Level: " + to_string(gracz.str) + "(" + to_string(gracz.before_boost_str) + ")";
	}
	else if (gracz.before_nerf_str != 0)
	{
		playerInfo[2] = "Strength Level: " + to_string(gracz.str) + "(" + to_string(gracz.before_nerf_str) + ")";
	}
	else
	{
		playerInfo[2] = "Strength Level: " + to_string(gracz.str);
	}
	if (gracz.before_boost_agility != 0)
	{
		playerInfo[3] = "Agility Level: " + to_string(gracz.agility) + "(" + to_string(gracz.before_boost_agility) + ")";
	}
	else if (gracz.before_nerf_agility != 0)
	{
		playerInfo[3] = "Agility Level: " + to_string(gracz.agility) + "(" + to_string(gracz.before_nerf_agility) + ")";
	}
	else
	{
		playerInfo[3] = "Agility Level: " + to_string(gracz.intel);
	}
	if (gracz.before_boost_agility != 0)
	{
		playerInfo[4] = "Inteligence Level: " + to_string(gracz.intel) + "(" + to_string(gracz.before_boost_intel) + ")";
	}
	else if (gracz.before_nerf_agility != 0)
	{
		playerInfo[4] = "Inteligence Level: " + to_string(gracz.intel) + "(" + to_string(gracz.before_nerf_intel) + ")";
	}
	else
	{
		playerInfo[4] = "Inteligence Level: " + to_string(gracz.intel);
	}
	if (gracz.before_boost_charisma != 0)
	{
		playerInfo[5] = "Charisma Level: " + to_string(gracz.charisma) + "(" + to_string(gracz.before_boost_charisma) + ")";
	}
	else if (gracz.before_nerf_charisma != 0)
	{
		playerInfo[5] = "Charisma Level: " + to_string(gracz.charisma) + "(" + to_string(gracz.before_nerf_charisma) + ")";
	}
	else
	{
		playerInfo[5] = "Charisma Level: " + to_string(gracz.charisma);
	}
	if (gracz.before_boost_luck != 0)
	{
		playerInfo[6] = "Luck Level: " + to_string(gracz.luck) + "(" + to_string(gracz.before_boost_luck) + ")";
	}
	else if (gracz.before_nerf_luck != 0)
	{
		playerInfo[6] = "Luck Level: " + to_string(gracz.luck) + "(" + to_string(gracz.before_nerf_luck) + ")";
	}
	else
	{
		playerInfo[6] = "Luck Level: " + to_string(gracz.luck);
	}
	playerInfo[7] = "Weapon: " + gracz.weapon_name + " (" + to_string(gracz.weapon) + ")";
	playerInfo[8] = "Defence: " + to_string(gracz.helmet + gracz.chestplate + gracz.gloves + gracz.pants + gracz.shoes);
	playerInfo[9] = "";
	playerInfo[10] = "";
	playerInfo[11] = "";
	playerInfo[12] = "";
	playerInfo[13] = "";
	playerInfo[14] = "";
	playerInfo[15] = "";
	playerInfo[16] = "";
	playerInfo[17] = "";
	string shortcuts[20];
	shortcuts[0] = "Escape";
	shortcuts[1] = "";
	shortcuts[2] = "";
	shortcuts[3] = "";
	shortcuts[4] = "";
	shortcuts[5] = "";
	shortcuts[6] = "";
	shortcuts[7] = "";
	shortcuts[8] = "";
	shortcuts[9] = "";
	shortcuts[10] = "";
	shortcuts[11] = "";
	shortcuts[12] = "";
	shortcuts[13] = "";
	shortcuts[14] = "";
	shortcuts[15] = "";
	shortcuts[16] = "";
	shortcuts[17] = "";
	shortcuts[18] = "";
	shortcuts[19] = "";
	string actions[20];
	actions[0] = "Hit";
	actions[1] = "";
	actions[2] = "";
	actions[3] = "";
	actions[4] = "";
	actions[5] = "";
	actions[6] = "";
	actions[7] = "";
	actions[8] = "";
	actions[9] = "";
	actions[10] = "";
	actions[11] = "";
	actions[12] = "";
	actions[13] = "";
	actions[14] = "";
	actions[15] = "";
	actions[16] = "";
	actions[17] = "";
	actions[18] = "";
	actions[19] = "";
	Mob enemy = loadMonsterData(monsterName);
	bool isItThePlayersTurnNow = playerGoesFirst;
	victoryCondition(11, 44, enemy, gracz, victory, itemName);
	while (victory==false)
	{
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		tabFight(gracz, enemy, highlight, playerInfo, shortcuts, actions);
		if (isItThePlayersTurnNow == true)
		{
			

		}
		victoryCondition(11, 44, enemy, gracz, victory, itemName);
		if(isItThePlayersTurnNow == false)
		{

		}
		victoryCondition(11, 44, enemy, gracz, victory, itemName);
	}
	return gracz;
	
	
	
	
	
	//Przeciwnik enemy;
	//srand((unsigned int)time(NULL));
	//if (nr == 0)
	//{
	//	Mieszkaniec_small cos;
	//	enemy.hp = cos.hp;
	//	enemy.max_hp = cos.max_hp;
	//	enemy.damage = cos.damage;
	//	enemy.gold = cos.gold;
	//	enemy.name = cos.name;
	//	enemy.xp = cos.xp;
	//	enemy.drop_item = cos.drop_item;
	//	enemy.drop_rate = cos.drop_rate;
	//}
	//if (nr == 1)
	//{
	//	Mieszkaniec_medium cos;
	//	enemy.hp = cos.hp;
	//	enemy.max_hp = cos.max_hp;
	//	enemy.damage = cos.damage;
	//	enemy.gold = cos.gold;
	//	enemy.name = cos.name;
	//	enemy.xp = cos.xp;
	//	enemy.drop_item = cos.drop_item;
	//	enemy.drop_rate = cos.drop_rate;
	//}
	//if (nr == 2)
	//{
	//	Mieszkaniec_big cos;
	//	enemy.hp = cos.hp;
	//	enemy.max_hp = cos.max_hp;
	//	enemy.damage = cos.damage;
	//	enemy.gold = cos.gold;
	//	enemy.name = cos.name;
	//	enemy.xp = cos.xp;
	//	enemy.drop_item = cos.drop_item;
	//	enemy.drop_rate = cos.drop_rate;
	//}
	//sound_start_fight();
	//while (1)
	//{
	//	system("cls");
	//	if (gracz.hp <= 0)
	//	{
	//		return gracz;
	//	}
	//	string menu[80];
	//	menu[0] = "IMIÊ POSTACI:";
	//	menu[1] = "UMIEJÊTNOŒÆ POSTACI:";
	//	menu[2] = "PUNKTY SI£Y:";
	//	/* 4*/menu[3] = "PUNKTY ZRÊCZNOŒCI:";
	//	/* 5*/menu[4] = "PUNKTY INTELIGENCJI:";
	//	/* 6*/menu[5] = "PUNKTY SZCZÊŒCIA:";
	//	/* 7*/menu[6] = "SUMA PUNKTÓW ATAKU:";
	//	/* 8*/menu[7] = "SUMA PUNKTÓW OBRONY:";
	//	/* 9*/menu[8] = "MIKSTURY ZDROWIA:";
	//	/*10*/menu[9] = "";
	//	/*11*/menu[10] = "";
	//	/*12*/menu[11] = "";
	//	/*13*/menu[12] = "";
	//	/*14*/menu[13] = "";
	//	/*15*/menu[14] = "";
	//	/*16*/menu[15] = "";
	//	/*17*/menu[16] = "";
	//	/*18*/menu[17] = "";
	//	/*19*/menu[18] = "";
	//	/*20*/menu[19] = "";
	//	//wartosci glownych statow
	//	/* 1*/menu[20] = gracz.nazwa;
	//	/* 2*/menu[21] = gracz.skill;
	//	/* 3*/menu[22] = to_string(gracz.str);
	//	/* 4*/menu[23] = to_string(gracz.agility);
	//	/* 5*/menu[24] = to_string(gracz.intel);
	//	/* 6*/menu[25] = to_string(gracz.luck);
	//	/* 7*/menu[26] = to_string(gracz.weapon);
	//	/* 8*/menu[27] = "";
	//	/* 9*/menu[28] = "";
	//	/*10*/menu[29] = "";
	//	/*11*/menu[30] = "";
	//	/*12*/menu[31] = "";
	//	/*13*/menu[32] = "";
	//	/*14*/menu[33] = "";
	//	/*15*/menu[34] = "";
	//	/*16*/menu[35] = "";
	//	/*17*/menu[36] = "";
	//	/*18*/menu[37] = "";
	//	/*19*/menu[38] = "";
	//	/*20*/menu[39] = "";
	//	//Opcje w lokacji 48 znakow
	//	/* 1*/menu[40] = "UDERZ";
	//	/* 2*/menu[41] = "U¯YJ PRZEDMIOTU";
	//	/* 3*/menu[42] = "U¯YJ UMIEJÊTNOŒCI";
	//	/* 4*/menu[43] = "";
	//	/* 5*/menu[44] = "";
	//	/* 6*/menu[45] = "";
	//	/* 7*/menu[46] = "";
	//	/* 8*/menu[47] = "";
	//	/* 9*/menu[48] = "";
	//	/*10*/menu[49] = "";
	//	/*11*/menu[50] = "";
	//	/*12*/menu[51] = "";
	//	/*13*/menu[52] = "";
	//	/*14*/menu[53] = "";
	//	/*15*/menu[54] = "";
	//	/*16*/menu[55] = "";
	//	/*17*/menu[56] = "";
	//	/*18*/menu[57] = "";
	//	/*19*/menu[58] = "";
	//	/*20*/menu[59] = "";
	//	//Skroty 21 znakow
	//	/* 1*/menu[60] = "W: UCIEKAJ";
	//	/* 2*/menu[61] = "";
	//	/* 3*/menu[62] = "";
	//	/* 4*/menu[63] = "";
	//	/* 5*/menu[64] = "";
	//	/* 6*/menu[65] = "";
	//	/* 7*/menu[66] = "";
	//	/* 8*/menu[67] = "";
	//	/* 9*/menu[68] = "";
	//	/*10*/menu[69] = "";
	//	/*11*/menu[70] = "";
	//	/*12*/menu[71] = "";
	//	/*13*/menu[72] = "";
	//	/*14*/menu[73] = "";
	//	/*15*/menu[74] = "";
	//	/*16*/menu[75] = "";
	//	/*17*/menu[76] = "";
	//	/*18*/menu[77] = "";
	//	/*19*/menu[78] = "";
	//	/*20*/menu[79] = "";
	//	tab_fight(gracz, menu, enemy);
	//	cout << "Twój wybor to: ";
	//	string wyb;
	//	cin >> wyb;
	//	wyb = string_tolower(wyb);
	//	switch (wyb[0])
	//	{
	//	case '1':
	//	{
	//		int random = rand() % 100;
	//		cout << "Atakujesz przeciwnika" << endl;
	//		if (random>50)
	//		{
	//			sound_hit();
	//			cout << "Ranisz przeciwnika lecz dalej jest w stanie walczyæ" << endl;
	//			cout << "Przeciwnik traci " << gracz.weapon << " punktów ¿ycia" << endl;
	//			system("PAUSE");
	//			enemy.hp = enemy.hp - gracz.weapon;
	//			system("cls");
	//			if (enemy.hp < 0)
	//			{
	//				enemy.hp = 0;
	//			}
	//			tab_fight(gracz, menu, enemy);
	//		}
	//		else
	//		{
	//			cout << "Nie trafi³eœ" << endl;
	//			system("PAUSE");
	//			system("cls");
	//			tab_fight(gracz, menu, enemy);
	//		}
	//		if (enemy.hp <= 0)
	//		{
	//			sound_success();
	//			cout << "Wygra³eœ!!!" << endl;
	//			cout << "Przy swoim przeciwniku znajdujesz " << enemy.gold << " sztuk z³ota" << endl;
	//			cout << "Za walkê dostajesz " << enemy.xp << " punktów doœwiadczenia" << endl;
	//			gracz.exp = gracz.exp + enemy.xp;
	//			gracz.gold = gracz.gold + enemy.gold;
	//			range(gracz);
	//			system("PAUSE");
	//			if (drop_item(gracz,enemy.drop_rate)==1)
	//			{
	//				while (1)
	//				{
	//					cout << "Znajdujesz na ziemi 1 " << enemy.drop_item << ". Czy chcesz go wzi¹æ?" << endl;
	//					cout << "1.Tak" << endl;
	//					cout << "2.Nie" << endl;
	//					cout << "Twój wybór to: ";
	//					string wyb;
	//					cin >> wyb;
	//					switch (wyb[0])
	//					{
	//					case '1':
	//					{
	//						seller handlarzyk;
	//						/*handlarzyk.load_merch();
	//						if (handlarzyk.search_on_lists(enemy.drop_item) == 0)
	//						{
	//							gracz.add_usage_item(enemy.drop_item, 0, 1);
	//							gracz.sort_usage_backpack();
	//							handlarzyk.add_prices(gracz);
	//						}*/
	//						gracz.fight_complete = 1;
	//						return gracz;
	//						break;
	//					}
	//					case '2':
	//					{
	//						gracz.fight_complete = 1;
	//						return gracz;
	//						break;
	//					}
	//					default:
	//					{
	//						system("cls");
	//						break;
	//					}
	//					}
	//				}
	//			}
	//			else
	//			{
	//				gracz.fight_complete = 1;
	//				return gracz;
	//			}
	//		}
	//		else
	//		{
	//			random = rand() % 100;
	//			cout << "Przeciwnik atakuje!!!" << endl;
	//			if (random > 50)
	//			{
	//				sound_damage();
	//				cout << "Trafi³, zadaje ci " << enemy.damage <<" punktów obra¿eñ" << endl;
	//				gracz.hp = gracz.hp - enemy.damage;
	//				system("PAUSE");
	//			}
	//			else
	//			{
	//				cout << "Jesteœ dla niego za szybki, nie trafi³" << endl;
	//				system("PAUSE");
	//			}
	//		}
	//		break;
	//	}
	//	case 'w':
	//	{
	//		while (1)
	//		{
	//			cout << "Czy napewno uciec od walki, mo¿e to nieœæ ze sob¹ konsekwencje?" << endl;
	//			cout << "1.Tak" << endl;
	//			cout << "2.Nie" << endl;
	//			cout << "Twój wybór to: ";
	//			string wyb;
	//			cin >> wyb;
	//			switch (wyb[0])
	//			{
	//			case '1':
	//			{
	//				cout << "Uciekasz." << endl;
	//				system("PAUSE");
	//				gracz.fight_failed = 1;
	//				return gracz;
	//			}
	//			case '2':
	//			{
	//				break;
	//			}
	//			default:
	//			{
	//				break;
	//			}
	//			break;
	//			}
	//			break;
	//		}
	//	}
	//	default:
	//	{
	//		break;
	//	}
	//	}
	//}
}