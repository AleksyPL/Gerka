#pragma once
//#include "biblioteki.h"
#include "player.h"


class dweller
{
public:
	int rep_points;
	int rep_level;
	int rep_points_to_next_level;
	int gold;
	string name;
	string quest_id;
	int gold_for_complete_quest;
	int exp_for_complete_quest;
	string menu[20];
	int ceny[20];
	string info[20];
	dweller();
	int goldInfo();
	int repLevelInfo();
	int repPointsInfo();
	int repPointsToNextLevelInfo();
	string questIDInfo();
	int goldForCompleteQuestInfo();
	int expForCompleteQuestInfo();
	string nameInfo();
	void goldSet(int a);
	void repLevelSet(int a);
	void repPointsSet(int a);
	void repPointsToNextLevelSet(int a);
	void questIDSet(string a);
	void goldForCompleteQuestSet(int a);
	void expForCompleteQuestSet(int a);
	void weAreClosing(player gracz);
	void rejectQuestGiving(int height, int startPoint);
};

class barman : public dweller
{
public:
	barman();
	void gossip(int height, int startPoint, player& gracz);
	void giveRoom(int height, int startPoint, player &gracz);
	void sellFood(int height, int startPoint, player &gracz, int ilosc);
	void sellBeer(int height, int startPoint, player &gracz);
};
class seller : public dweller
{
public:
	string itemName[20];
	int itemPrice[20];
	void loadItems(string path);
	int loadPrices(string item, string path);
	string makeString(int howLong, string item, int amount, int price, bool skipPrice = false);
};

class generalStoreSeller : public seller
{
public:
	generalStoreSeller();
	void buyItem(int height, int startPoint, player& gracz, string item, int amount, int price, bool &anythingSoldOrBought);
	void sellItem(int height, int startPoint, player &gracz, string item, int amount, int price, bool &anythingSoldOrBought);
};

class blacksmith : public dweller
{
public:
	blacksmith();
	void loadPlayerPoints(player gracz);
	void printImage(vector <string>& message);
	void powerUp(int height, int startPoint, player &gracz, int tryb);
};

class bladesmith : public seller
{
public:
	int weaponsDamage[20];
	bool weaponsRarity[20];
	vector <string> weaponNames;
	bladesmith();
	void upgradeWeapon(int height, int startPoint, player& gracz, int price);
	void generateMerch(player gracz);
	void buyItem(int height, int startPoint, player& gracz, int index);
	void sellItem(int height, int startPoint, player& gracz);
	void printImage(vector <string>& message);
};
class alchemist : public dweller
{
public:
	alchemist();
	void showImage(vector <string>& message);
	void buyNewLevelPotion(int height, int startPoint, player &gracz);
	void buyHpPotion(int height, int startPoint, player &gracz);
};

class shaman : public dweller
{
public:
	shaman();
	void showImage(vector <string>& message);
	void addBoost(int height, int startPoint, player &gracz, int tryb);
	int dialogBox(int height, int startPoint);
	void everythingAboutQuests(int height, int startPoint, player &gracz);
};

class doctor : public dweller
{
public:
	doctor();
	void showImage(vector <string>& message);
	void heal(int height, int startPoint, player &gracz);
	void sober(int height, int startPoint, player &gracz);
	void removeNerf(int height, int startPoint, player &gracz, int tryb);
};

class chest
{
public:
	string menu[60];
	int menu_amount[60];
	chest();
	int countFreeFieldsUsage();
	int countFreeFieldsAlchemy();
	int countFreeFieldsSmithery();
	bool isInChest(string itemName);
	int findSelectedItemInChestIndex(string itemName);
	int findFreeUsageIndex();
	int findFreeAlchemyIndex();
	int findFreeSmitheryIndex();
	void sortUsage();
	void sortAlchemy();
	void sortSmithery();
	void moveToPlayer(int height, int startPoint, int numer, player &gracz);
	void moveToChest(int height, int startPoint, int numer, player &gracz);
};