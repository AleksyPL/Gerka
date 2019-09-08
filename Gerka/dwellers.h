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
	dweller();
};

class barman : private dweller
{
public:
	string menu[20];
	int ceny[20];
	string info[8];
	barman();
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void gossip();
	void sleep(player &gracz);
	void sell_food(player &gracz, int ilosc);
	void sell_beer(player &gracz);
};

class seller : private dweller
{
public:
	string menu[20];
	string menu_items[120];
	int menu_price[120];
	int ceny[20];
	string info[8];
	seller();
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void load_merch();
	void add_prices(player &gracz);
	int search_on_lists(string nazwa);
};

class blacksmith : private dweller
{
public:
	string menu[20];
	int ceny[20];
	string info[8];
	blacksmith();
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void print_image();
	void power_up(player &gracz, int tryb);
};

class alchemist : private dweller
{
public:
	string menu[20];
	int ceny[20];
	string info[8];
	alchemist();
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void show_image();
	void buy_hp_potion(player &gracz);
};

class shaman : private dweller
{
public:
	string menu[20];
	int ceny[20];
	string info[8];
	shaman();
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void show_image();
	void add_boost(player &gracz, int tryb);
};

class doctor : private dweller
{
public:
	string menu[20];
	int ceny[20];
	string info[8];
	doctor();
	int gold_info();
	int rep_level_info();
	int rep_points_info();
	int rep_points_to_next_level_info();
	void gold_set(int a);
	void rep_level_set(int a);
	void rep_points_set(int a);
	void rep_points_to_next_level_set(int a);
	void show_image();
	void heal(player &gracz);
	void sober(player &gracz);
	void remove_nerf(player &gracz, int tryb);
};