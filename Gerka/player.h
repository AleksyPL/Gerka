#pragma once
#include "biblioteki.h"

class player
{
	public:
		string nazwa;
		int str;					//sila
		int hp;						//hp
		int max_hp;                 //Max hp
		int agility;				//zwinnosc
		int intel;					//inteligencja
		int luck;					//szczescie
		int charisma;				//charyzma
		int level;					//poziom
		int exp;					//doswiadczenie
		int exp_to_next_level;		//doswiadczenie do nastepnego poziomu
		long long gold;				//gold
		int licznik_dnia;			//licznik dnia
		string quest;				//nazwa questa
		int hp_potion;              //ilosc potionow hp
		int str_potion;				//ilosc potionow si³y
		int agility_potion;			//iloœæ potionow zrêcznoœci
		int intel_potion;			//ilosc potionów inteligencji
		int charisma_potion;		//iloœæ potionów charyzmy
		int luck_potion;			//iloœæ potionów szczêœcia
		int helmet;                 //punkty deff z helmu
		int chestplate;             //punkty deff z napiersnika
		int gloves;                 //punkty deff z rekawic
		int pants;                  //punkty deff ze spodni
		int shoes;                  //punkty deff z butow
		int weapon;                 //punkty att z broni
		string weapon_name;			//nazwa broni
		string skill;
		int hunger;
		string inventory_usage[20];
		int inventory_usage_amount[20];
		int inventory_usage_price[20];
		string inventory_crafting[40];
		int inventory_crafting_amount[40];
		int inventory_crafting_price[40];
		string pseudonym;
		int counter_nerf_str;
		int counter_boost_str;
		int before_nerf_str;
		int before_boost_str;
		int counter_nerf_agility;
		int counter_boost_agility;
		int before_nerf_agility;
		int before_boost_agility;
		int counter_nerf_intel;
		int counter_boost_intel;
		int before_nerf_intel;
		int before_boost_intel;
		int counter_nerf_luck;
		int counter_boost_luck;
		int before_nerf_luck;
		int before_boost_luck;
		int counter_nerf_charisma;
		int counter_boost_charisma;
		int before_nerf_charisma;
		int before_boost_charisma;
		int alko;
		player();
		void use_hp_potion();
		void drop_hp_potion();
		int find_usage_item(string nazwa);
		int find_crafting_alchemy_item(string nazwa);
		int find_crafting_forge_item(string nazwa);
		int find_usage_item_index(string nazwa);
		int find_crafting_alchemy_item_index(string nazwa);
		int find_crafting_forge_item_index(string nazwa);
		void add_usage_item(string nazwa, int ilosc, int tryb=0);
		void add_crafting_alchemy_item(string nazwa, int ilosc, int tryb = 0);
		void add_crafting_forge_item(string nazwa, int ilosc, int tryb = 0);
		void sort_usage_backpack();
		void sort_crafting_alchemy_backpack();
		void sort_crafting_forge_backpack();
		int count_free_fields_usage();
		int count_free_fields_alchemy();
		int count_free_fields_forge();
		string return_amount_of_hp_potions();
		string return_amount_of_str_potions();
		string return_amount_of_agility_potions();
		string return_amount_of_intel_potions();
		string return_amount_of_charisma_potions();
		string return_amount_of_luck_potions();
};