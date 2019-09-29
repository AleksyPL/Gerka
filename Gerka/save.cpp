#include "save.h"

void save(player gracz,barman bobby,seller handlarz,blacksmith kowal, alchemist alchemik, chest krzynka)
{
	while (1)
	{
		cout << "Czy napewno chcesz zapisaæ grê?" << endl;
		cout << "1.Tak" << endl;
		cout << "2.Nie" << endl;
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			fstream plik;
			remove("./txt/mix/Zapis_gry_basic.txt");
			plik.open("./txt/mix/Zapis_gry_basic.txt", ios::out);
			plik << "Nazwa postaci" << endl << gracz.nazwa << endl;//1-2
			plik << "Poziom gracza" << endl << gracz.level << endl;//3-4
			plik << "Ilosc z³ota" << endl << gracz.gold << endl;//5-6
			plik << "Punkty ¿ycia" << endl << gracz.hp << endl;//7-8
			plik << "Max punktów ¿ycia" << endl << gracz.max_hp << endl;//9-10
			plik << "Punkty si³y" << endl << gracz.str << endl;//11-12
			plik << "Punkty zrêcznoœci" << endl << gracz.agility << endl;//13-14
			plik << "Punkty inteligencji" << endl << gracz.intel << endl;//15-16
			plik << "Punkty szczêœcia" << endl << gracz.luck << endl;//17-18
			plik << "Punkty charyzmy" << endl << gracz.charisma << endl;//19-20
			plik << "Punkty najedzenia" << endl << gracz.hunger << endl;//21-22
			plik << "Punkty upojenia alkoholowego" << endl << gracz.alko << endl;//23-24
			plik << "Punkty doœwiadczenia" << endl << gracz.exp << endl;//25-26
			plik << "Punkty doœwiadczenia do nastêpnego poziomu" << endl << gracz.exp_to_next_level << endl;//27-28
			plik << "Licznik dnia" << endl << gracz.licznik_dnia << endl;//29-30
			plik << "Aktualny czas - godznia" << endl << gracz.hour << endl;//31-32
			plik << "Aktualny czas - minuta" << endl << gracz.minute << endl;//33-34
			plik << "Zadanie" << endl << gracz.quest_name << endl;//35-36
			plik << "Umiejêtnoœæ" << endl << gracz.skill;//37-38
			plik.close();
			remove("./txt/mix/Zapis_gry_eq.txt");
			plik.open("./txt/mix/Zapis_gry_eq.txt", ios::out);
			plik << "Punkty he³mu" << endl << gracz.helmet << endl;//1-2
			plik << "Punkty napierœnika" << endl << gracz.chestplate << endl;//3-4
			plik << "Punkty rêkawic" << endl << gracz.gloves << endl;//5-6
			plik << "Punkty spodni" << endl << gracz.pants << endl;//7-8
			plik << "Punkty butów" << endl << gracz.shoes << endl;//9-10
			plik << "Punkty obra¿eñ broni" << endl << gracz.weapon << endl;//11-12
			plik << "Nazwa broni" << endl << gracz.weapon_name;//13-14
			plik.close();
			remove("./txt/mix/Zapis_gry_backpack.txt");
			gracz.sort_usage_backpack();
			gracz.sort_crafting_alchemy_backpack();
			gracz.sort_crafting_forge_backpack();
			plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::out);
			plik << "Przedmiot u¿ytkowy numer 1" << endl << gracz.inventory_usage[0] << endl << gracz.inventory_usage_amount[0] << endl;//1-3
			plik << "Przedmiot u¿ytkowy numer 2" << endl << gracz.inventory_usage[1] << endl << gracz.inventory_usage_amount[1] << endl;//4-6
			plik << "Przedmiot u¿ytkowy numer 3" << endl << gracz.inventory_usage[2] << endl << gracz.inventory_usage_amount[2] << endl;//7-9
			plik << "Przedmiot u¿ytkowy numer 4" << endl << gracz.inventory_usage[3] << endl << gracz.inventory_usage_amount[3] << endl;//10-12
			plik << "Przedmiot u¿ytkowy numer 5" << endl << gracz.inventory_usage[4] << endl << gracz.inventory_usage_amount[4] << endl;//13-15
			plik << "Przedmiot u¿ytkowy numer 6" << endl << gracz.inventory_usage[5] << endl << gracz.inventory_usage_amount[5] << endl;//16-18
			plik << "Przedmiot u¿ytkowy numer 7" << endl << gracz.inventory_usage[6] << endl << gracz.inventory_usage_amount[6] << endl;//19-21
			plik << "Przedmiot u¿ytkowy numer 8" << endl << gracz.inventory_usage[7] << endl << gracz.inventory_usage_amount[7] << endl;//22-24
			plik << "Przedmiot u¿ytkowy numer 9" << endl << gracz.inventory_usage[8] << endl << gracz.inventory_usage_amount[8] << endl;//25-27
			plik << "Przedmiot u¿ytkowy numer 10" << endl << gracz.inventory_usage[9] << endl << gracz.inventory_usage_amount[9] << endl;//28-30
			plik << "Przedmiot u¿ytkowy numer 11" << endl << gracz.inventory_usage[10] << endl << gracz.inventory_usage_amount[10] << endl;//31-33
			plik << "Przedmiot u¿ytkowy numer 12" << endl << gracz.inventory_usage[11] << endl << gracz.inventory_usage_amount[11] << endl;//34-36
			plik << "Przedmiot u¿ytkowy numer 13" << endl << gracz.inventory_usage[12] << endl << gracz.inventory_usage_amount[12] << endl;//37-39
			plik << "Przedmiot u¿ytkowy numer 14" << endl << gracz.inventory_usage[13] << endl << gracz.inventory_usage_amount[13] << endl;//40-42
			plik << "Przedmiot u¿ytkowy numer 15" << endl << gracz.inventory_usage[14] << endl << gracz.inventory_usage_amount[14] << endl;//43-45
			plik << "Przedmiot u¿ytkowy numer 16" << endl << gracz.inventory_usage[15] << endl << gracz.inventory_usage_amount[15] << endl;//46-48
			plik << "Przedmiot u¿ytkowy numer 17" << endl << gracz.inventory_usage[16] << endl << gracz.inventory_usage_amount[16] << endl;//49-51
			plik << "Przedmiot u¿ytkowy numer 18" << endl << gracz.inventory_usage[17] << endl << gracz.inventory_usage_amount[17] << endl;//52-54
			plik << "Przedmiot u¿ytkowy numer 19" << endl << gracz.inventory_usage[18] << endl << gracz.inventory_usage_amount[18] << endl;//55-57
			plik << "Przedmiot u¿ytkowy numer 20" << endl << gracz.inventory_usage[19] << endl << gracz.inventory_usage_amount[19] << endl;//58-60
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 1" << endl << gracz.inventory_crafting[0] << endl << gracz.inventory_crafting_amount[0] << endl;//61-63
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 2" << endl << gracz.inventory_crafting[1] << endl << gracz.inventory_crafting_amount[1] << endl;//64-66
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 3" << endl << gracz.inventory_crafting[2] << endl << gracz.inventory_crafting_amount[2] << endl;//67-69
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 4" << endl << gracz.inventory_crafting[3] << endl << gracz.inventory_crafting_amount[3] << endl;//70-72
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 5" << endl << gracz.inventory_crafting[4] << endl << gracz.inventory_crafting_amount[4] << endl;//73-75
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 6" << endl << gracz.inventory_crafting[5] << endl << gracz.inventory_crafting_amount[5] << endl;//76-78
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 7" << endl << gracz.inventory_crafting[6] << endl << gracz.inventory_crafting_amount[6] << endl;//79-80
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 8" << endl << gracz.inventory_crafting[7] << endl << gracz.inventory_crafting_amount[7] << endl;//82-84
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 9" << endl << gracz.inventory_crafting[8] << endl << gracz.inventory_crafting_amount[8] << endl;//85-87
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 10" << endl << gracz.inventory_crafting[9] << endl << gracz.inventory_crafting_amount[9] << endl;//88-90
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 11" << endl << gracz.inventory_crafting[10] << endl << gracz.inventory_crafting_amount[10] << endl;//91-92
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 12" << endl << gracz.inventory_crafting[11] << endl << gracz.inventory_crafting_amount[11] << endl;//94-96
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 13" << endl << gracz.inventory_crafting[12] << endl << gracz.inventory_crafting_amount[12] << endl;//97-99
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 14" << endl << gracz.inventory_crafting[13] << endl << gracz.inventory_crafting_amount[13] << endl;//100-102
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 15" << endl << gracz.inventory_crafting[14] << endl << gracz.inventory_crafting_amount[14] << endl;//103-105
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 16" << endl << gracz.inventory_crafting[15] << endl << gracz.inventory_crafting_amount[15] << endl;//106-108
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 17" << endl << gracz.inventory_crafting[16] << endl << gracz.inventory_crafting_amount[16] << endl;//109-111
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 18" << endl << gracz.inventory_crafting[17] << endl << gracz.inventory_crafting_amount[17] << endl;//112-114
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 19" << endl << gracz.inventory_crafting[18] << endl << gracz.inventory_crafting_amount[18] << endl;//115-117
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 20" << endl << gracz.inventory_crafting[19] << endl << gracz.inventory_crafting_amount[19] << endl;//118-120
			plik << "Przedmiot rzemieœlniczy kowalski numer 1" << endl << gracz.inventory_crafting[20] << endl << gracz.inventory_crafting_amount[20] << endl;//121-123
			plik << "Przedmiot rzemieœlniczy kowalski numer 2" << endl << gracz.inventory_crafting[21] << endl << gracz.inventory_crafting_amount[21] << endl;//124-126
			plik << "Przedmiot rzemieœlniczy kowalski numer 3" << endl << gracz.inventory_crafting[22] << endl << gracz.inventory_crafting_amount[22] << endl;//127-129
			plik << "Przedmiot rzemieœlniczy kowalski numer 4" << endl << gracz.inventory_crafting[23] << endl << gracz.inventory_crafting_amount[23] << endl;//130-132
			plik << "Przedmiot rzemieœlniczy kowalski numer 5" << endl << gracz.inventory_crafting[24] << endl << gracz.inventory_crafting_amount[24] << endl;//133-135
			plik << "Przedmiot rzemieœlniczy kowalski numer 6" << endl << gracz.inventory_crafting[25] << endl << gracz.inventory_crafting_amount[25] << endl;//136-138
			plik << "Przedmiot rzemieœlniczy kowalski numer 7" << endl << gracz.inventory_crafting[26] << endl << gracz.inventory_crafting_amount[26] << endl;//139-141
			plik << "Przedmiot rzemieœlniczy kowalski numer 8" << endl << gracz.inventory_crafting[27] << endl << gracz.inventory_crafting_amount[27] << endl;//142-144
			plik << "Przedmiot rzemieœlniczy kowalski numer 9" << endl << gracz.inventory_crafting[28] << endl << gracz.inventory_crafting_amount[28] << endl;//145-147
			plik << "Przedmiot rzemieœlniczy kowalski numer 10" << endl << gracz.inventory_crafting[29] << endl << gracz.inventory_crafting_amount[29] << endl;//148-150
			plik << "Przedmiot rzemieœlniczy kowalski numer 11" << endl << gracz.inventory_crafting[30] << endl << gracz.inventory_crafting_amount[30] << endl;//151-153
			plik << "Przedmiot rzemieœlniczy kowalski numer 12" << endl << gracz.inventory_crafting[31] << endl << gracz.inventory_crafting_amount[31] << endl;//154-156
			plik << "Przedmiot rzemieœlniczy kowalski numer 13" << endl << gracz.inventory_crafting[32] << endl << gracz.inventory_crafting_amount[32] << endl;//157-159
			plik << "Przedmiot rzemieœlniczy kowalski numer 14" << endl << gracz.inventory_crafting[33] << endl << gracz.inventory_crafting_amount[33] << endl;//160-162
			plik << "Przedmiot rzemieœlniczy kowalski numer 15" << endl << gracz.inventory_crafting[34] << endl << gracz.inventory_crafting_amount[34] << endl;//163-165
			plik << "Przedmiot rzemieœlniczy kowalski numer 16" << endl << gracz.inventory_crafting[35] << endl << gracz.inventory_crafting_amount[35] << endl;//166-168
			plik << "Przedmiot rzemieœlniczy kowalski numer 17" << endl << gracz.inventory_crafting[36] << endl << gracz.inventory_crafting_amount[36] << endl;//169-171
			plik << "Przedmiot rzemieœlniczy kowalski numer 18" << endl << gracz.inventory_crafting[37] << endl << gracz.inventory_crafting_amount[37] << endl;//172-174
			plik << "Przedmiot rzemieœlniczy kowalski numer 19" << endl << gracz.inventory_crafting[38] << endl << gracz.inventory_crafting_amount[38] << endl;//175-177
			plik << "Przedmiot rzemieœlniczy kowalski numer 20" << endl << gracz.inventory_crafting[39] << endl << gracz.inventory_crafting_amount[39];//178-180
			plik.close();
			remove("./txt/mix/Zapis_gry_npc.txt");
			plik.open("./txt/mix/Zapis_gry_npc.txt", ios::out);
			plik << "Barman - poziom reputacji" << endl << bobby.rep_level_info() << endl;//1-2
			plik << "Barman - punkty reputacji" << endl << bobby.rep_points_info() << endl;//3-4
			plik << "Barman - punkty reputacji do nastêpnego poziomu" << endl << bobby.rep_points_to_next_level_info() << endl;//5-6
			plik << "Barman - iloœæ z³ota" << endl << bobby.gold_info();//7-8
			plik << "Handlarz - poziom reputacji" << endl << handlarz.rep_level_info() << endl;//9-10
			plik << "Handlarz - punkty reputacji" << endl << handlarz.rep_points_info() << endl;//11-12
			plik << "Handlarz - punkty reputacji do nastêpnego poziomu" << endl << handlarz.rep_points_to_next_level_info() << endl;//13-14
			plik << "Handlarz - iloœæ z³ota" << endl << handlarz.gold_info();//15-16
			plik << "Kowal - poziom reputacji" << endl << kowal.rep_level_info() << endl;//17-18
			plik << "Kowal - punkty reputacji" << endl << kowal.rep_points_info() << endl;//19-20
			plik << "Kowal - punkty reputacji do nastêpnego poziomu" << endl << kowal.rep_points_to_next_level_info() << endl;//21-22
			plik << "Kowal - iloœæ z³ota" << endl << kowal.gold_info();//23-24
			plik << "Alchemik - poziom reputacji" << endl << alchemik.rep_level_info() << endl;//25-26
			plik << "Alchemik - punkty reputacji" << endl << alchemik.rep_points_info() << endl;//27-28
			plik << "Alchemik - punkty reputacji do nastêpnego poziomu" << endl << alchemik.rep_points_to_next_level_info() << endl;//29-30
			plik << "Alchemik - iloœæ z³ota" << endl << alchemik.gold_info();//31-32
			plik.close();
			remove("./txt/mix/Zapis_gry_boost.txt");
			plik.open("./txt/mix/Zapis_gry_boost.txt", ios::out);
			plik << "Licznik os³abienia si³y" << endl << gracz.counter_nerf_str << endl;//1-2
			plik << "Przed os³abieniem si³y" << endl << gracz.before_nerf_str << endl;//3-4
			plik << "Licznik wzmocnienia si³y" << endl << gracz.counter_boost_str << endl;//5-6
			plik << "Przed wzmocnieniem si³y" << endl << gracz.before_boost_str << endl;//7-8
			plik << "Licznik os³abienia zrêcznoœci" << endl << gracz.counter_nerf_agility << endl;//9-10
			plik << "Przed os³abieniem zrêcznoœci" << endl << gracz.before_nerf_agility << endl;//11-12
			plik << "Licznik wzmocnienia zrêcznoœci" << endl << gracz.counter_boost_agility << endl;//13-14
			plik << "Przed wzmocnieniem zrêcznoœci" << endl << gracz.before_boost_agility << endl;//15-16
			plik << "Licznik os³abienia inteligencji" << endl << gracz.counter_nerf_intel << endl;//17-18
			plik << "Przed os³abieniem inteligencji" << endl << gracz.before_nerf_intel << endl;//19-20
			plik << "Licznik wzmocnienia inteligencji" << endl << gracz.counter_boost_intel << endl;//21-22
			plik << "Przed wzmocnieniem inteligencji" << endl << gracz.before_boost_intel << endl;//23-24
			plik << "Licznik os³abienia szczêœcia" << endl << gracz.counter_nerf_luck << endl;//25-26
			plik << "Przed os³abieniem szczêœcia" << endl << gracz.before_nerf_luck << endl;//27-28
			plik << "Licznik wzmocnienia szczêœcia" << endl << gracz.counter_boost_luck << endl;//29-30
			plik << "Przed wzmocnieniem szczêœcia" << endl << gracz.before_boost_luck << endl;//31-32
			plik << "Licznik os³abienia charyzmy" << endl << gracz.counter_nerf_charisma << endl;//33-34
			plik << "Przed os³abieniem charyzmy" << endl << gracz.before_nerf_charisma << endl;//35-36
			plik << "Licznik wzmocnienia charyzmy" << endl << gracz.counter_boost_charisma << endl;//37-38
			plik << "Przed wzmocnieniem charyzmy" << endl << gracz.before_boost_charisma;//39-40
			plik.close();
			remove("./txt/mix/Zapis_gry_chest.txt");
			krzynka.sort_usage();
			krzynka.sort_alchemy();
			krzynka.sort_forge();
			plik.open("./txt/mix/Zapis_gry_chest.txt", ios::out);
			plik << "Przedmiot u¿ytkowy numer 1" << endl << krzynka.menu[0] << endl << krzynka.menu_amount[0] << endl;//1-3
			plik << "Przedmiot u¿ytkowy numer 2" << endl << krzynka.menu[1] << endl << krzynka.menu_amount[1] << endl;//4-6
			plik << "Przedmiot u¿ytkowy numer 3" << endl << krzynka.menu[2] << endl << krzynka.menu_amount[2] << endl;//7-9
			plik << "Przedmiot u¿ytkowy numer 4" << endl << krzynka.menu[3] << endl << krzynka.menu_amount[3] << endl;//10-12
			plik << "Przedmiot u¿ytkowy numer 5" << endl << krzynka.menu[4] << endl << krzynka.menu_amount[4] << endl;//13-15
			plik << "Przedmiot u¿ytkowy numer 6" << endl << krzynka.menu[5] << endl << krzynka.menu_amount[5] << endl;//16-18
			plik << "Przedmiot u¿ytkowy numer 7" << endl << krzynka.menu[6] << endl << krzynka.menu_amount[6] << endl;//19-21
			plik << "Przedmiot u¿ytkowy numer 8" << endl << krzynka.menu[7] << endl << krzynka.menu_amount[7] << endl;//22-24
			plik << "Przedmiot u¿ytkowy numer 9" << endl << krzynka.menu[8] << endl << krzynka.menu_amount[8] << endl;//25-27
			plik << "Przedmiot u¿ytkowy numer 10" << endl << krzynka.menu[9] << endl << krzynka.menu_amount[9] << endl;//28-30
			plik << "Przedmiot u¿ytkowy numer 11" << endl << krzynka.menu[10] << endl << krzynka.menu_amount[10] << endl;//31-33
			plik << "Przedmiot u¿ytkowy numer 12" << endl << krzynka.menu[11] << endl << krzynka.menu_amount[11] << endl;//34-36
			plik << "Przedmiot u¿ytkowy numer 13" << endl << krzynka.menu[12] << endl << krzynka.menu_amount[12] << endl;//37-39
			plik << "Przedmiot u¿ytkowy numer 14" << endl << krzynka.menu[13] << endl << krzynka.menu_amount[13] << endl;//40-42
			plik << "Przedmiot u¿ytkowy numer 15" << endl << krzynka.menu[14] << endl << krzynka.menu_amount[14] << endl;//43-45
			plik << "Przedmiot u¿ytkowy numer 16" << endl << krzynka.menu[15] << endl << krzynka.menu_amount[15] << endl;//46-48
			plik << "Przedmiot u¿ytkowy numer 17" << endl << krzynka.menu[16] << endl << krzynka.menu_amount[16] << endl;//49-51
			plik << "Przedmiot u¿ytkowy numer 18" << endl << krzynka.menu[17] << endl << krzynka.menu_amount[17] << endl;//52-54
			plik << "Przedmiot u¿ytkowy numer 19" << endl << krzynka.menu[18] << endl << krzynka.menu_amount[18] << endl;//55-57
			plik << "Przedmiot u¿ytkowy numer 20" << endl << krzynka.menu[19] << endl << krzynka.menu_amount[19] << endl;//58-60
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 1" << endl << krzynka.menu[20] << endl << krzynka.menu_amount[20] << endl;//61-63
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 2" << endl << krzynka.menu[21] << endl << krzynka.menu_amount[21] << endl;//64-66
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 3" << endl << krzynka.menu[22] << endl << krzynka.menu_amount[22] << endl;//67-69
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 4" << endl << krzynka.menu[23] << endl << krzynka.menu_amount[23] << endl;//70-72
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 5" << endl << krzynka.menu[24] << endl << krzynka.menu_amount[24] << endl;//73-75
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 6" << endl << krzynka.menu[25] << endl << krzynka.menu_amount[25] << endl;//76-78
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 7" << endl << krzynka.menu[26] << endl << krzynka.menu_amount[26] << endl;//79-80
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 8" << endl << krzynka.menu[27] << endl << krzynka.menu_amount[27] << endl;//82-84
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 9" << endl << krzynka.menu[28] << endl << krzynka.menu_amount[28] << endl;//85-87
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 10" << endl << krzynka.menu[29] << endl << krzynka.menu_amount[29] << endl;//88-90
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 11" << endl << krzynka.menu[30] << endl << krzynka.menu_amount[30] << endl;//91-92
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 12" << endl << krzynka.menu[31] << endl << krzynka.menu_amount[31] << endl;//94-96
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 13" << endl << krzynka.menu[32] << endl << krzynka.menu_amount[32] << endl;//97-99
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 14" << endl << krzynka.menu[33] << endl << krzynka.menu_amount[33] << endl;//100-102
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 15" << endl << krzynka.menu[34] << endl << krzynka.menu_amount[34] << endl;//103-105
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 16" << endl << krzynka.menu[35] << endl << krzynka.menu_amount[35] << endl;//106-108
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 17" << endl << krzynka.menu[36] << endl << krzynka.menu_amount[36] << endl;//109-111
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 18" << endl << krzynka.menu[37] << endl << krzynka.menu_amount[37] << endl;//112-114
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 19" << endl << krzynka.menu[38] << endl << krzynka.menu_amount[38] << endl;//115-117
			plik << "Przedmiot rzemieœlniczy alchemiczny numer 20" << endl << krzynka.menu[39] << endl << krzynka.menu_amount[39] << endl;//118-120
			plik << "Przedmiot rzemieœlniczy kowalski numer 1" << endl << krzynka.menu[40] << endl << krzynka.menu_amount[40] << endl;//121-123
			plik << "Przedmiot rzemieœlniczy kowalski numer 2" << endl << krzynka.menu[41] << endl << krzynka.menu_amount[41] << endl;//124-126
			plik << "Przedmiot rzemieœlniczy kowalski numer 3" << endl << krzynka.menu[42] << endl << krzynka.menu_amount[42] << endl;//127-129
			plik << "Przedmiot rzemieœlniczy kowalski numer 4" << endl << krzynka.menu[43] << endl << krzynka.menu_amount[43] << endl;//130-132
			plik << "Przedmiot rzemieœlniczy kowalski numer 5" << endl << krzynka.menu[44] << endl << krzynka.menu_amount[44] << endl;//133-135
			plik << "Przedmiot rzemieœlniczy kowalski numer 6" << endl << krzynka.menu[45] << endl << krzynka.menu_amount[45] << endl;//136-138
			plik << "Przedmiot rzemieœlniczy kowalski numer 7" << endl << krzynka.menu[46] << endl << krzynka.menu_amount[46] << endl;//139-141
			plik << "Przedmiot rzemieœlniczy kowalski numer 8" << endl << krzynka.menu[47] << endl << krzynka.menu_amount[47] << endl;//142-144
			plik << "Przedmiot rzemieœlniczy kowalski numer 9" << endl << krzynka.menu[48] << endl << krzynka.menu_amount[48] << endl;//145-147
			plik << "Przedmiot rzemieœlniczy kowalski numer 10" << endl << krzynka.menu[49] << endl << krzynka.menu_amount[49] << endl;//148-150
			plik << "Przedmiot rzemieœlniczy kowalski numer 11" << endl << krzynka.menu[50] << endl << krzynka.menu_amount[50] << endl;//151-153
			plik << "Przedmiot rzemieœlniczy kowalski numer 12" << endl << krzynka.menu[51] << endl << krzynka.menu_amount[51] << endl;//154-156
			plik << "Przedmiot rzemieœlniczy kowalski numer 13" << endl << krzynka.menu[52] << endl << krzynka.menu_amount[52] << endl;//157-159
			plik << "Przedmiot rzemieœlniczy kowalski numer 14" << endl << krzynka.menu[53] << endl << krzynka.menu_amount[53] << endl;//160-162
			plik << "Przedmiot rzemieœlniczy kowalski numer 15" << endl << krzynka.menu[54] << endl << krzynka.menu_amount[54] << endl;//163-165
			plik << "Przedmiot rzemieœlniczy kowalski numer 16" << endl << krzynka.menu[55] << endl << krzynka.menu_amount[55] << endl;//166-168
			plik << "Przedmiot rzemieœlniczy kowalski numer 17" << endl << krzynka.menu[56] << endl << krzynka.menu_amount[56] << endl;//169-171
			plik << "Przedmiot rzemieœlniczy kowalski numer 18" << endl << krzynka.menu[57] << endl << krzynka.menu_amount[57] << endl;//172-174
			plik << "Przedmiot rzemieœlniczy kowalski numer 19" << endl << krzynka.menu[58] << endl << krzynka.menu_amount[58] << endl;//175-177
			plik << "Przedmiot rzemieœlniczy kowalski numer 20" << endl << krzynka.menu[59] << endl << krzynka.menu_amount[59];//178-180
			plik.close();
			cout << endl << "Gra zostala zapisana" << endl;
			system("PAUSE");
			break;
		}
		case '2':
		{
			cout << endl << "Gra nie zosta³a zapisana" << endl;
			system("PAUSE");
			break;
		}
		default:
		{
			break;
		}
		break;
		}
		break;
	}
}