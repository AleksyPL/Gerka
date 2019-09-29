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
	string info[8];
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
};

class barman : public dweller
{
public:
	barman();
	void gossip(player &gracz);
	void give_room(player &gracz);
	void sell_food(player &gracz, int ilosc);
	void sell_beer(player &gracz);
};

class seller : public dweller
{
public:
	string menu_items[120];
	int menu_price[120];
	seller();
	void load_merch();
	int find_item_index(string nazwa);
	void add_prices(player &gracz);
	int search_on_lists(string nazwa);
};

class blacksmith : public dweller
{
public:
	blacksmith();
	void print_image();
	void power_up(player &gracz, int tryb);
};

class alchemist : public dweller
{
public:
	alchemist();
	void show_image();
	void buy_new_level_potion(player &gracz);
	void buy_hp_potion(player &gracz);
};

class shaman : public dweller
{
public:
	shaman();
	void show_image();
	void add_boost(player &gracz, int tryb);
	void reject_quest_giving();
	int dialog_box();
	void everything_about_quests(player &gracz);
};

class doctor : public dweller
{
public:
	doctor();
	void show_image();
	void heal(player &gracz);
	void sober(player &gracz);
	void remove_nerf(player &gracz, int tryb);
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
	void move_to_player(int numer, player &gracz);
	void move_to_chest(int numer, player &gracz);
};