#pragma once
#include "biblioteki.h"
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
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	string quest_id_info();
	int gold_for_complete_quest_info();
	int exp_for_complete_quest_info();
	string name_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void quest_id_set(string a);
	void gold_for_complete_quest_set(int a);
	void exp_for_complete_quest_set(int a);
	void weAreClosing(player gracz);
	void reject_quest_giving(int height, int startPoint);
};

class barman : public dweller
{
public:
	barman();
	void gossip(int height, int startPoint, player& gracz);
	void give_room(int height, int startPoint, player &gracz);
	void sell_food(int height, int startPoint, player &gracz, int ilosc);
	void sell_beer(int height, int startPoint, player &gracz);
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
	void load_player_points(player gracz);
	void print_image(vector <string>& message);
	void power_up(int height, int startPoint, player &gracz, int tryb);
};

class bladesmith : public seller
{
public:
	int weaponsDamage[20];
	bool weaponsRarity[20];
	vector <string> weaponNames;
	bladesmith();
	void upgradeWeapon(int height, int startPoint, player& gracz);
	void generateMerch(player gracz);
	void buyItem(int height, int startPoint, player& gracz, int index);
	void sellItem(int height, int startPoint, player& gracz);
	void printImage(vector <string>& message);
};
class alchemist : public dweller
{
public:
	alchemist();
	void show_image(vector <string>& message);
	void buy_new_level_potion(int height, int startPoint, player &gracz);
	void buy_hp_potion(int height, int startPoint, player &gracz);
};

class shaman : public dweller
{
public:
	shaman();
	void show_image(vector <string>& message);
	void add_boost(int height, int startPoint, player &gracz, int tryb);
	int dialog_box(int height, int startPoint);
	void everything_about_quests(int height, int startPoint, player &gracz);
};

class doctor : public dweller
{
public:
	doctor();
	void show_image(vector <string>& message);
	void heal(int height, int startPoint, player &gracz);
	void sober(int height, int startPoint, player &gracz);
	void remove_nerf(int height, int startPoint, player &gracz, int tryb);
};

class chest
{
public:
	string menu[60];
	int menu_amount[60];
	chest();
	int count_free_fields_usage();
	int count_free_fields_alchemy();
	int count_free_fields_forge();
	int is_in_chest_usage(player gracz, string nazwa);
	int find_free_usage_index();
	int find_selected_usage_index(string nazwa);
	int is_in_chest_alchemy(player gracz, string nazwa);
	int find_free_alchemy_index();
	int find_selected_alchemy_index(string nazwa);
	int is_in_chest_forge(player gracz, string nazwa);
	int find_free_forge_index();
	int find_selected_forge_index(string nazwa);
	void sort_usage();
	void sort_alchemy();
	void sort_forge();
	void move_to_player(int height, int startPoint, int numer, player &gracz);
	void move_to_chest(int height, int startPoint, int numer, player &gracz);
};