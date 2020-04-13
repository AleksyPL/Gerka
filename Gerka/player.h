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
		int charisma;						//charyzma
		int luck;							//szcz�cie
		int level;							//poziom postaci
		int exp;							//doswiadczenie
		int exp_to_next_level;				//doswiadczenie do nastepnego poziomu
		__int64 gold;						//ilo�� z�ota
		int licznik_dnia;					//licznik dnia
		int hour;							//aktualny czas - godziny
		int minute;							//aktualny czas - minuty
		int helmet;							//punkty obrony z helmu
		int chestplate;						//punkty obrony z napiersnika
		int gloves;							//punkty obrony z rekawic
		int pants;							//punkty obrony ze spodni
		int shoes;							//punkty obrony z butow
		int weaponDamage;
		bool isTheWeaponRare;
		string weaponName;
		int weaponPrice;
		int availableWeaponUpgradePoints;
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
		int counter_nerf_charisma;
		int counter_boost_charisma;
		int before_nerf_charisma;
		int before_boost_charisma;
		int counter_nerf_luck;
		int counter_boost_luck;
		int before_nerf_luck;
		int before_boost_luck;
		int alko;
		string quest_name;			//nazwa questa
		string quest_id;				//identyfikator questa
		int quest_complete;			//znacznik czy quest jest zako�czony pozytywnie
		int quest_failed;			//znacznik czy quest jest zako�czony negatywnie
		int fight_complete;
		int fight_failed;
		int last_dungeon;
		player();
		void aBitSober();
		void aBitHungry(int height, int startPoint, int number = 0);
		bool findUsageItem(string nazwa);
		bool findCraftingAlchemyItem(string nazwa);
		bool findCraftingSmitheryItem(string nazwa);
		int findUsageItemIndex(string nazwa);
		int findCraftingAlchemyItemIndex(string nazwa);
		int findCraftingSmitheryItemIndex(string nazwa);
		bool removeItem(int height, int startPoint, vector <string> message, string item, int amount);
		bool removeItemWithoutNotification(string item, int amount);
		bool pickUpItemWithNotificationMenu(string itemName, int amount, int height, int startPoint, int price = 0);
		bool addUsageItem(string itemName, int price, int amount, int height, int startPoint);
		bool addCraftingAlchemyItem(string itemName, int price, int amount, int height, int startPoint);
		bool addCraftingSmitheryItem(string itemName, int price, int amount, int height, int startPoint);
		void sortUsageBackpack();
		void sortCraftingAlchemyBackpack();
		void sortCraftingSmitheryBackpack();
		int countFreeFieldsUsage();
		int countFreeFieldsAlchemy();
		int countFreeFieldsSmithery();
		void addQuest(string nazwa,string id);
		void removeQuest();
		void resetFightStatus();
		int returnChancesOfDealingDamage();
		int returnChancesOfGettingHit();
};