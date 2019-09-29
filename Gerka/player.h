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
		int hour;					//aktualny czas - godziny
		int minute;					//aktualny czas - minuty
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
		string quest_name;			//nazwa questa
		string quest_id;				//identyfikator questa
		int quest_complete;			//znacznik czy quest jest zakoñczony pozytywnie
		int quest_failed;			//znacznik czy quest jest zakoñczony negatywnie
		player();
		void a_bit_sober();
		void a_bit_hungry(int number = 0);
		int find_usage_item(string nazwa);
		int find_crafting_alchemy_item(string nazwa);
		int find_crafting_forge_item(string nazwa);
		int find_usage_item_index(string nazwa);
		int find_crafting_alchemy_item_index(string nazwa);
		int find_crafting_forge_item_index(string nazwa);
		void drop_item(string nazwa, string ending);
		void use_item(string nazwa, string komunikat);
		void add_usage_item(string nazwa, int cena, int ilosc, int tryb=0);
		void add_crafting_alchemy_item(string nazwa, int cena, int ilosc, int tryb = 0);
		void add_crafting_forge_item(string nazwa, int cena, int ilosc, int tryb = 0);
		void remove_usage_item(string nazwa, int ilosc);
		void sort_usage_backpack();
		void sort_crafting_alchemy_backpack();
		void sort_crafting_forge_backpack();
		int count_free_fields_usage();
		int count_free_fields_alchemy();
		int count_free_fields_forge();
		void add_quest(string nazwa,string id);
		void remove_quest();
};