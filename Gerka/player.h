#pragma once
#include "biblioteki.h"

class player
{
	public:
		string nazwa;
		int str;							//si�a
		int hp;								//Punkty �ycia
		int max_hp;							//Max punkt�w �ycia
		int agility;						//zwinno��
		int intel;							//inteligencja
		int luck;							//szcz�cie
		int charisma;						//charyzma
		int level;							//poziom postaci
		int exp;							//doswiadczenie
		int exp_to_next_level;				//doswiadczenie do nastepnego poziomu
		long long gold;						//ilo�� z�ota
		int licznik_dnia;					//licznik dnia
		int hour;							//aktualny czas - godziny
		int minute;							//aktualny czas - minuty
		int helmet;							//punkty obrony z helmu
		int chestplate;						//punkty obrony z napiersnika
		int gloves;							//punkty obrony z rekawic
		int pants;							//punkty obrony ze spodni
		int shoes;							//punkty obrony z butow
		int weapon;							//punkty obrony z broni
		string weapon_name;					//nazwa broni
		string skill;						//specjalna umiej�tno��
		int hunger;							//punkty g�odu
		string inventory_usage[20];			//tablica na przedmioty u�ytkowe
		int inventory_usage_amount[20];		//tablica na ilo�ci przedmiot�w u�ytkowych 
		int inventory_usage_price[20];		//tablica na ceny przedmiot�w u�ytkowych 
		string inventory_crafting[40];		//tablica na przedmioty rzemie�lnicze
		int inventory_crafting_amount[40];	//tablica na ilo�ci przedmiot�w rzemie�lniczych 
		int inventory_crafting_price[40];	//tablica na ceny przedmiot�w rzemie�lniczych 
		string pseudonym;					//pseudonim postaci
		int counter_nerf_str;				//licznik_negatywnych_efekt�w_si�y
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
		int quest_complete;			//znacznik czy quest jest zako�czony pozytywnie
		int quest_failed;			//znacznik czy quest jest zako�czony negatywnie
		int fight_complete;
		int fight_failed;
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
		void reset_fight_status();
};