#include "biblioteki.h"
#include "start.h"
#include "ui.h"
#include "save.h"

void save(player gracz,barman bobby,seller handlarz,blacksmith kowal, alchemist alchemik)
{
	while (1)
	{
		cout << "Czy napewno chcesz zapisać grę?" << endl;
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
			plik << "Ilosc złota" << endl << gracz.gold << endl;//5-6
			plik << "Punkty życia" << endl << gracz.hp << endl;//7-8
			plik << "Max punktów życia" << endl << gracz.max_hp << endl;//9-10
			plik << "Punkty siły" << endl << gracz.str << endl;//11-12
			plik << "Punkty zręczności" << endl << gracz.agility << endl;//13-14
			plik << "Punkty inteligencji" << endl << gracz.intel << endl;//15-16
			plik << "Punkty szczęścia" << endl << gracz.luck << endl;//17-18
			plik << "Punkty charyzmy" << endl << gracz.charisma << endl;//19-20
			plik << "Punkty najedzenia" << endl << gracz.hunger << endl;//21-22
			plik << "Punkty upojenia alkoholowego" << endl << gracz.alko << endl;//23-24
			plik << "Punkty doświadczenia" << endl << gracz.exp << endl;//25-26
			plik << "Punkty doświadczenia do następnego poziomu" << endl << gracz.exp_to_next_level << endl;//27-28
			plik << "Licznik dnia" << endl << gracz.licznik_dnia << endl;//29-30
			plik << "Zadanie" << endl << gracz.quest << endl;//31-32
			plik << "Umiejętność" << endl << gracz.skill;//33-34
			plik.close();
			remove("./txt/mix/Zapis_gry_eq.txt");
			plik.open("./txt/mix/Zapis_gry_eq.txt", ios::out);
			plik << "Ilosc mikstur leczących" << endl << gracz.hp_potion << endl;//1-2
			plik << "Ilosc mikstur siły" << endl << gracz.str_potion << endl;//3-4
			plik << "Ilosc mikstur zręczności" << endl << gracz.agility_potion << endl;//5-6
			plik << "Ilosc mikstur inteligencji" << endl << gracz.intel_potion << endl;//7-8
			plik << "Ilosc mikstur charyzmy" << endl << gracz.charisma_potion << endl;//9-10
			plik << "Ilosc mikstur szczęścia" << endl << gracz.luck_potion << endl;//11-12
			plik << "Punkty hełmu" << endl << gracz.helmet << endl;//13-14
			plik << "Punkty napierśnika" << endl << gracz.chestplate << endl;//15-16
			plik << "Punkty rękawic" << endl << gracz.gloves << endl;//17-18
			plik << "Punkty spodni" << endl << gracz.pants << endl;//19-20
			plik << "Punkty butów" << endl << gracz.shoes << endl;//21-22
			plik << "Punkty obrażeń broni" << endl << gracz.weapon << endl;//23-24
			plik << "Nazwa broni" << endl << gracz.weapon_name;//25-26
			plik.close();
			remove("./txt/mix/Zapis_gry_backpack.txt");
			gracz.sort_usage_backpack();
			gracz.sort_crafting_alchemy_backpack();
			gracz.sort_crafting_forge_backpack();
			plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::out);
			plik << "Przedmiot użytkowy numer 1" << endl << gracz.inventory_usage[0] << endl << gracz.inventory_usage_amount[0] << endl;//1-3
			plik << "Przedmiot użytkowy numer 2" << endl << gracz.inventory_usage[1] << endl << gracz.inventory_usage_amount[1] << endl;//4-6
			plik << "Przedmiot użytkowy numer 3" << endl << gracz.inventory_usage[2] << endl << gracz.inventory_usage_amount[2] << endl;//7-9
			plik << "Przedmiot użytkowy numer 4" << endl << gracz.inventory_usage[3] << endl << gracz.inventory_usage_amount[3] << endl;//10-12
			plik << "Przedmiot użytkowy numer 5" << endl << gracz.inventory_usage[4] << endl << gracz.inventory_usage_amount[4] << endl;//13-15
			plik << "Przedmiot użytkowy numer 6" << endl << gracz.inventory_usage[5] << endl << gracz.inventory_usage_amount[5] << endl;//16-18
			plik << "Przedmiot użytkowy numer 7" << endl << gracz.inventory_usage[6] << endl << gracz.inventory_usage_amount[6] << endl;//19-21
			plik << "Przedmiot użytkowy numer 8" << endl << gracz.inventory_usage[7] << endl << gracz.inventory_usage_amount[7] << endl;//22-24
			plik << "Przedmiot użytkowy numer 9" << endl << gracz.inventory_usage[8] << endl << gracz.inventory_usage_amount[8] << endl;//25-27
			plik << "Przedmiot użytkowy numer 10" << endl << gracz.inventory_usage[9] << endl << gracz.inventory_usage_amount[9] << endl;//28-30
			plik << "Przedmiot użytkowy numer 11" << endl << gracz.inventory_usage[10] << endl << gracz.inventory_usage_amount[10] << endl;//31-33
			plik << "Przedmiot użytkowy numer 12" << endl << gracz.inventory_usage[11] << endl << gracz.inventory_usage_amount[11] << endl;//34-36
			plik << "Przedmiot użytkowy numer 13" << endl << gracz.inventory_usage[12] << endl << gracz.inventory_usage_amount[12] << endl;//37-39
			plik << "Przedmiot użytkowy numer 14" << endl << gracz.inventory_usage[13] << endl << gracz.inventory_usage_amount[13] << endl;//40-42
			plik << "Przedmiot użytkowy numer 15" << endl << gracz.inventory_usage[14] << endl << gracz.inventory_usage_amount[14] << endl;//43-45
			plik << "Przedmiot użytkowy numer 16" << endl << gracz.inventory_usage[15] << endl << gracz.inventory_usage_amount[15] << endl;//46-48
			plik << "Przedmiot użytkowy numer 17" << endl << gracz.inventory_usage[16] << endl << gracz.inventory_usage_amount[16] << endl;//49-51
			plik << "Przedmiot użytkowy numer 18" << endl << gracz.inventory_usage[17] << endl << gracz.inventory_usage_amount[17] << endl;//52-54
			plik << "Przedmiot użytkowy numer 19" << endl << gracz.inventory_usage[18] << endl << gracz.inventory_usage_amount[18] << endl;//55-57
			plik << "Przedmiot użytkowy numer 20" << endl << gracz.inventory_usage[19] << endl << gracz.inventory_usage_amount[19] << endl;//58-60
			plik << "Przedmiot rzemieślniczy alchemiczny numer 1" << endl << gracz.inventory_crafting[0] << endl << gracz.inventory_crafting_amount[0] << endl;//61-63
			plik << "Przedmiot rzemieślniczy alchemiczny numer 2" << endl << gracz.inventory_crafting[1] << endl << gracz.inventory_crafting_amount[1] << endl;//64-66
			plik << "Przedmiot rzemieślniczy alchemiczny numer 3" << endl << gracz.inventory_crafting[2] << endl << gracz.inventory_crafting_amount[2] << endl;//67-69
			plik << "Przedmiot rzemieślniczy alchemiczny numer 4" << endl << gracz.inventory_crafting[3] << endl << gracz.inventory_crafting_amount[3] << endl;//70-72
			plik << "Przedmiot rzemieślniczy alchemiczny numer 5" << endl << gracz.inventory_crafting[4] << endl << gracz.inventory_crafting_amount[4] << endl;//73-75
			plik << "Przedmiot rzemieślniczy alchemiczny numer 6" << endl << gracz.inventory_crafting[5] << endl << gracz.inventory_crafting_amount[5] << endl;//76-78
			plik << "Przedmiot rzemieślniczy alchemiczny numer 7" << endl << gracz.inventory_crafting[6] << endl << gracz.inventory_crafting_amount[6] << endl;//79-80
			plik << "Przedmiot rzemieślniczy alchemiczny numer 8" << endl << gracz.inventory_crafting[7] << endl << gracz.inventory_crafting_amount[7] << endl;//82-84
			plik << "Przedmiot rzemieślniczy alchemiczny numer 9" << endl << gracz.inventory_crafting[8] << endl << gracz.inventory_crafting_amount[8] << endl;//85-87
			plik << "Przedmiot rzemieślniczy alchemiczny numer 10" << endl << gracz.inventory_crafting[9] << endl << gracz.inventory_crafting_amount[9] << endl;//88-90
			plik << "Przedmiot rzemieślniczy alchemiczny numer 11" << endl << gracz.inventory_crafting[10] << endl << gracz.inventory_crafting_amount[10] << endl;//91-92
			plik << "Przedmiot rzemieślniczy alchemiczny numer 12" << endl << gracz.inventory_crafting[11] << endl << gracz.inventory_crafting_amount[11] << endl;//94-96
			plik << "Przedmiot rzemieślniczy alchemiczny numer 13" << endl << gracz.inventory_crafting[12] << endl << gracz.inventory_crafting_amount[12] << endl;//97-99
			plik << "Przedmiot rzemieślniczy alchemiczny numer 14" << endl << gracz.inventory_crafting[13] << endl << gracz.inventory_crafting_amount[13] << endl;//100-102
			plik << "Przedmiot rzemieślniczy alchemiczny numer 15" << endl << gracz.inventory_crafting[14] << endl << gracz.inventory_crafting_amount[14] << endl;//103-105
			plik << "Przedmiot rzemieślniczy alchemiczny numer 16" << endl << gracz.inventory_crafting[15] << endl << gracz.inventory_crafting_amount[15] << endl;//106-108
			plik << "Przedmiot rzemieślniczy alchemiczny numer 17" << endl << gracz.inventory_crafting[16] << endl << gracz.inventory_crafting_amount[16] << endl;//109-111
			plik << "Przedmiot rzemieślniczy alchemiczny numer 18" << endl << gracz.inventory_crafting[17] << endl << gracz.inventory_crafting_amount[17] << endl;//112-114
			plik << "Przedmiot rzemieślniczy alchemiczny numer 19" << endl << gracz.inventory_crafting[18] << endl << gracz.inventory_crafting_amount[18] << endl;//115-117
			plik << "Przedmiot rzemieślniczy alchemiczny numer 20" << endl << gracz.inventory_crafting[19] << endl << gracz.inventory_crafting_amount[19] << endl;//118-120
			plik << "Przedmiot rzemieślniczy kowalski numer 1" << endl << gracz.inventory_crafting[20] << endl << gracz.inventory_crafting_amount[20] << endl;//121-123
			plik << "Przedmiot rzemieślniczy kowalski numer 2" << endl << gracz.inventory_crafting[21] << endl << gracz.inventory_crafting_amount[21] << endl;//124-126
			plik << "Przedmiot rzemieślniczy kowalski numer 3" << endl << gracz.inventory_crafting[22] << endl << gracz.inventory_crafting_amount[22] << endl;//127-129
			plik << "Przedmiot rzemieślniczy kowalski numer 4" << endl << gracz.inventory_crafting[23] << endl << gracz.inventory_crafting_amount[23] << endl;//130-132
			plik << "Przedmiot rzemieślniczy kowalski numer 5" << endl << gracz.inventory_crafting[24] << endl << gracz.inventory_crafting_amount[24] << endl;//133-135
			plik << "Przedmiot rzemieślniczy kowalski numer 6" << endl << gracz.inventory_crafting[25] << endl << gracz.inventory_crafting_amount[25] << endl;//136-138
			plik << "Przedmiot rzemieślniczy kowalski numer 7" << endl << gracz.inventory_crafting[26] << endl << gracz.inventory_crafting_amount[26] << endl;//139-141
			plik << "Przedmiot rzemieślniczy kowalski numer 8" << endl << gracz.inventory_crafting[27] << endl << gracz.inventory_crafting_amount[27] << endl;//142-144
			plik << "Przedmiot rzemieślniczy kowalski numer 9" << endl << gracz.inventory_crafting[28] << endl << gracz.inventory_crafting_amount[28] << endl;//145-147
			plik << "Przedmiot rzemieślniczy kowalski numer 10" << endl << gracz.inventory_crafting[29] << endl << gracz.inventory_crafting_amount[29] << endl;//148-150
			plik << "Przedmiot rzemieślniczy kowalski numer 11" << endl << gracz.inventory_crafting[30] << endl << gracz.inventory_crafting_amount[30] << endl;//151-153
			plik << "Przedmiot rzemieślniczy kowalski numer 12" << endl << gracz.inventory_crafting[31] << endl << gracz.inventory_crafting_amount[31] << endl;//154-156
			plik << "Przedmiot rzemieślniczy kowalski numer 13" << endl << gracz.inventory_crafting[32] << endl << gracz.inventory_crafting_amount[32] << endl;//157-159
			plik << "Przedmiot rzemieślniczy kowalski numer 14" << endl << gracz.inventory_crafting[33] << endl << gracz.inventory_crafting_amount[33] << endl;//160-162
			plik << "Przedmiot rzemieślniczy kowalski numer 15" << endl << gracz.inventory_crafting[34] << endl << gracz.inventory_crafting_amount[34] << endl;//163-165
			plik << "Przedmiot rzemieślniczy kowalski numer 16" << endl << gracz.inventory_crafting[35] << endl << gracz.inventory_crafting_amount[35] << endl;//166-168
			plik << "Przedmiot rzemieślniczy kowalski numer 17" << endl << gracz.inventory_crafting[36] << endl << gracz.inventory_crafting_amount[36] << endl;//169-171
			plik << "Przedmiot rzemieślniczy kowalski numer 18" << endl << gracz.inventory_crafting[37] << endl << gracz.inventory_crafting_amount[37] << endl;//172-174
			plik << "Przedmiot rzemieślniczy kowalski numer 19" << endl << gracz.inventory_crafting[38] << endl << gracz.inventory_crafting_amount[38] << endl;//175-177
			plik << "Przedmiot rzemieślniczy kowalski numer 20" << endl << gracz.inventory_crafting[39] << endl << gracz.inventory_crafting_amount[39];//178-180
			plik.close();
			remove("./txt/mix/Zapis_gry_npc.txt");
			plik.open("./txt/mix/Zapis_gry_npc.txt", ios::out);
			plik << "Barman - poziom reputacji" << endl << bobby.rep_level_info() << endl;//1-2
			plik << "Barman - punkty reputacji" << endl << bobby.rep_points_info() << endl;//3-4
			plik << "Barman - punkty reputacji do następnego poziomu" << endl << bobby.rep_points_to_next_level_info() << endl;//5-6
			plik << "Barman - ilość złota" << endl << bobby.gold_info();//7-8
			plik << "Handlarz - poziom reputacji" << endl << handlarz.rep_level_info() << endl;//9-10
			plik << "Handlarz - punkty reputacji" << endl << handlarz.rep_points_info() << endl;//11-12
			plik << "Handlarz - punkty reputacji do następnego poziomu" << endl << handlarz.rep_points_to_next_level_info() << endl;//13-14
			plik << "Handlarz - ilość złota" << endl << handlarz.gold_info();//15-16
			plik << "Kowal - poziom reputacji" << endl << kowal.rep_level_info() << endl;//17-18
			plik << "Kowal - punkty reputacji" << endl << kowal.rep_points_info() << endl;//19-20
			plik << "Kowal - punkty reputacji do następnego poziomu" << endl << kowal.rep_points_to_next_level_info() << endl;//21-22
			plik << "Kowal - ilość złota" << endl << kowal.gold_info();//23-24
			plik << "Alchemik - poziom reputacji" << endl << alchemik.rep_level_info() << endl;//25-26
			plik << "Alchemik - punkty reputacji" << endl << alchemik.rep_points_info() << endl;//27-28
			plik << "Alchemik - punkty reputacji do następnego poziomu" << endl << alchemik.rep_points_to_next_level_info() << endl;//29-30
			plik << "Alchemik - ilość złota" << endl << alchemik.gold_info();//31-32
			plik.close();
			remove("./txt/mix/Zapis_gry_boost.txt");
			plik.open("./txt/mix/Zapis_gry_boost.txt", ios::out);
			plik << "Licznik osłabienia siły" << endl << gracz.counter_nerf_str << endl;//1-2
			plik << "Przed osłabieniem siły" << endl << gracz.before_nerf_str << endl;//3-4
			plik << "Licznik wzmocnienia siły" << endl << gracz.counter_boost_str << endl;//5-6
			plik << "Przed wzmocnieniem siły" << endl << gracz.before_boost_str << endl;//7-8
			plik << "Licznik osłabienia zręczności" << endl << gracz.counter_nerf_agility << endl;//9-10
			plik << "Przed osłabieniem zręczności" << endl << gracz.before_nerf_agility << endl;//11-12
			plik << "Licznik wzmocnienia zręczności" << endl << gracz.counter_boost_agility << endl;//13-14
			plik << "Przed wzmocnieniem zręczności" << endl << gracz.before_boost_agility << endl;//15-16
			plik << "Licznik osłabienia inteligencji" << endl << gracz.counter_nerf_intel << endl;//17-18
			plik << "Przed osłabieniem inteligencji" << endl << gracz.before_nerf_intel << endl;//19-20
			plik << "Licznik wzmocnienia inteligencji" << endl << gracz.counter_boost_intel << endl;//21-22
			plik << "Przed wzmocnieniem inteligencji" << endl << gracz.before_boost_intel << endl;//23-24
			plik << "Licznik osłabienia szczęścia" << endl << gracz.counter_nerf_luck << endl;//25-26
			plik << "Przed osłabieniem szczęścia" << endl << gracz.before_nerf_luck << endl;//27-28
			plik << "Licznik wzmocnienia szczęścia" << endl << gracz.counter_boost_luck << endl;//29-30
			plik << "Przed wzmocnieniem szczęścia" << endl << gracz.before_boost_luck << endl;//31-32
			plik << "Licznik osłabienia charyzmy" << endl << gracz.counter_nerf_charisma << endl;//33-34
			plik << "Przed osłabieniem charyzmy" << endl << gracz.before_nerf_charisma << endl;//35-36
			plik << "Licznik wzmocnienia charyzmy" << endl << gracz.counter_boost_charisma << endl;//37-38
			plik << "Przed wzmocnieniem charyzmy" << endl << gracz.before_boost_charisma;//39-40
			plik.close();
			cout << endl << "Gra zostala zapisana" << endl;
			system("PAUSE");
			break;
		}
		case '2':
		{
			cout << endl << "Gra nie została zapisana" << endl;
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