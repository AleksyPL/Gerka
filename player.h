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
		string inventory_crafting[20];
		int inventory_crafting_amount[20];
		int inventory_crafting_price[20];
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
		player()
		{
			nazwa = "";
			str = 5;
			hp = 50;
			max_hp = hp;
			agility = 5;
			intel = 5;
			luck = 5;
			charisma = 5;
			level = 1;
			exp = 0;
			exp_to_next_level = 50;
			gold = 0;
			licznik_dnia = 1;
			quest = "";
			hp_potion = 0;
			str_potion = 0;
			agility_potion = 0;
			intel_potion = 0;
			charisma_potion = 0;
			luck_potion = 0;
			helmet = 0;
			chestplate = 0;
			gloves = 0;
			pants = 0;
			shoes = 0;
			weapon = 5;
			weapon_name = "SZTYLET";
			skill = "";
			hunger = 10;
			pseudonym = "";
			counter_nerf_str = 0;
			counter_boost_str = 0;
			before_nerf_str = 0;
			before_boost_str = 0;
			counter_nerf_agility = 0;
			counter_boost_agility = 0;
			before_nerf_agility = 0;
			before_boost_agility = 0;
			counter_nerf_intel = 0;
			counter_boost_intel = 0;
			before_nerf_intel = 0;
			before_boost_intel = 0;
			counter_nerf_luck = 0;
			counter_boost_luck = 0;
			before_nerf_luck = 0;
			before_boost_luck = 0;
			counter_nerf_charisma = 0;
			counter_boost_charisma = 0;
			before_nerf_charisma = 0;
			before_boost_charisma = 0;
			alko = 0;
			for (int i = 0; i < 20; i++)
			{
				inventory_usage[i] = "";
				inventory_usage_amount[i] = 0;
				inventory_usage_price[i] = 0;
				inventory_crafting[i] = "";
				inventory_crafting_amount[i] = 0;
				inventory_crafting_price[i] = 0;
			}
		}
		void use_hp_potion()
		{
			if (hp == max_hp)
			{
				cout << "Nie potrzebujesz siê leczyæ" << endl;
			}
			else if (hp_potion > 0)
			{
				sound_drink();
				hp_potion = hp_potion - 1;
				hp = hp + (0.1*max_hp);
				if (hp > max_hp)
				{
					hp = max_hp;
				}
				cout << "Leczysz siê" << endl;
			}
			else
			{
				cout << "Nie masz przy sobie ¿adnych mikstur lecz¹cych" << endl;
			}
			system("PAUSE");
		}
		void drop_hp_potion()
		{
			if (hp_potion > 0)
			{
				cout << "Wyrzucasz jedn¹ miksturê lecz¹c¹" << endl;
				hp_potion = hp_potion - 1;
				system("PAUSE");
			}
		}
		int find_item_usage(string nazwa)
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_usage[i] == nazwa)
				{
					return 1;
				}
				else if(inventory_usage[i] != nazwa)
				{
					continue;
				}
				else
				{
					return 0;
				}
			}
		}
		int find_item_crafting(string nazwa)
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_crafting[i] == nazwa)
				{
					return 1;
				}
				else if (inventory_crafting[i] != nazwa)
				{
					continue;
				}
				else
				{
					return 0;
				}
			}
		}
		int find_usage_item_index(string nazwa)
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_usage[i] == nazwa)
				{
					return i;
				}
			}
		}
		int find_crafting_item_index(string nazwa)
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_crafting[i] == nazwa)
				{
					return i;
				}
			}
		}
		void add_item_usage(string nazwa, int ilosc)
		{
			int i = 0;
			for (i; i < 20; i++)
			{
				if (inventory_usage[i] == nazwa)
				{
					inventory_usage_amount[i] = inventory_usage_amount[i] + ilosc;
					break;
				}
				else if (inventory_usage[i] == "")
				{
					inventory_usage[i] = nazwa;
					inventory_usage_amount[i] = ilosc;
					break;
				}
			}
			if(inventory_usage[19]!="")
			{
				cout << "TWÓJ PLECAK JEST PE£EN, NIE MO¯ESZ WZI¥Æ TEGO PRZEDMIOTU" << endl;
				system("PAUSE");
			}
		}
		void add_item_crafting(string nazwa, int ilosc)
		{
			int i = 0;
			for (i; i < 20; i++)
			{
				if (inventory_crafting[i] == nazwa)
				{
					inventory_crafting_amount[i] = inventory_crafting_amount[i] + ilosc;
					break;
				}
				else if (inventory_crafting[i] == "")
				{
					inventory_crafting[i] = nazwa;
					inventory_crafting_amount[i] = ilosc;
					break;
				}
			}
			if (inventory_crafting[19] != "")
			{
				cout << "TWÓJ PLECAK JEST PE£EN, NIE MO¯ESZ WZI¥Æ TEGO PRZEDMIOTU" << endl;
				system("PAUSE");
			}
		}
		void sort_backpack_usage()
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_usage[i] != "")
				{
					continue;
				}
				else
				{
					for (int j = i+1; j < 20; j++)
					{
						if (inventory_usage[j] != "")
						{
							inventory_usage[i] = inventory_usage[j];
							inventory_usage_amount[i] = inventory_usage_amount[j];
							inventory_usage_price[i] = inventory_usage_price[j];
							inventory_usage[j] = "";
							inventory_usage_amount[j] = 0;
							inventory_usage_price[j] = 0;
							break;
						}
					}
				}
			}
		}
		void sort_backpack_crafting()
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_crafting[i] != "")
				{
					continue;
				}
				else
				{
					for (int j = i + 1; j < 20; j++)
					{
						if (inventory_crafting[j] != "")
						{
							inventory_crafting[i] = inventory_crafting[j];
							inventory_crafting_amount[i] = inventory_crafting_amount[j];
							inventory_crafting_price[i] = inventory_crafting_price[j];
							inventory_crafting[j] = "";
							inventory_crafting_amount[j] = 0;
							inventory_crafting_price[j] = 0;
							break;
						}
					}
				}
			}
		}
		string return_amount_of_hp_potions()
		{
			string pomoc = "";
			if (hp_potion != 0)
			{
				pomoc = "MIKSTURY ¯YCIA x" + to_string(hp_potion);
				return pomoc;
			}
			else
			{
				return pomoc;
			}
		}
		string return_amount_of_str_potions()
		{
			string pomoc = "";
			if (str_potion != 0)
			{
				pomoc = "MIKSTURY SI£Y x" + to_string(str_potion);
			}
			return pomoc;
		}
		string return_amount_of_agility_potions()
		{
			string pomoc = "";
			if (agility_potion != 0)
			{
				pomoc = "MIKSTURY ZRÊCZNOŒCI x" + to_string(agility_potion);
			}
			return pomoc;
		}
		string return_amount_of_intel_potions()
		{
			string pomoc = "";
			if (intel_potion != 0)
			{
				pomoc = "MIKSTURY INTELIGENCJI x" + to_string(intel_potion);
			}
			return pomoc;
		}
		string return_amount_of_charisma_potions()
		{
			string pomoc = "";
			if (charisma_potion != 0)
			{
				pomoc = "MIKSTURY CHARYZMY x" + to_string(charisma_potion);
			}
			return pomoc;
		}
		string return_amount_of_luck_potions()
		{
			string pomoc = "";
			if (luck_potion != 0)
			{
				pomoc = "MIKSTURY SZCZÊŒCIA x" + to_string(luck_potion);
			}
			return pomoc;
		}
};