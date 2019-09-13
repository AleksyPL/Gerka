#include "walka.h"
#include "mobki1.h"
#include "tabelka.h"
#include "zakres.h"

player fight(player gracz, int nr)
{
	Przeciwnik enemy;
	srand((unsigned int)time(NULL));
	if (nr == 0)
	{
		Mieszkaniec_small cos;
		enemy.hp = cos.hp;
		enemy.max_hp = cos.max_hp;
		enemy.damage = cos.damage;
		enemy.gold = cos.gold;
		enemy.name = cos.name;
		enemy.xp = cos.xp;
	}
	if (nr == 1)
	{
		Mieszkaniec_medium cos;
		enemy.hp = cos.hp;
		enemy.max_hp = cos.max_hp;
		enemy.damage = cos.damage;
		enemy.gold = cos.gold;
		enemy.name = cos.name;
		enemy.xp = cos.xp;
	}
	if (nr == 2)
	{
		Mieszkaniec_big cos;
		enemy.hp = cos.hp;
		enemy.max_hp = cos.max_hp;
		enemy.damage = cos.damage;
		enemy.gold = cos.gold;
		enemy.name = cos.name;
		enemy.xp = cos.xp;
	}
	sound_start_fight();
	while (1)
	{
		system("cls");
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		string menu[80];

		//glowne staty 23 znaki
		/* 1*/menu[0] = "IMIÊ POSTACI:";
		/* 2*/menu[1] = "UMIEJÊTNOŒÆ POSTACI:";
		/* 3*/menu[2] = "PUNKTY SI£Y:";
		/* 4*/menu[3] = "PUNKTY ZRÊCZNOŒCI:";
		/* 5*/menu[4] = "PUNKTY INTELIGENCJI:";
		/* 6*/menu[5] = "PUNKTY SZCZÊŒCIA:";
		/* 7*/menu[6] = "SUMA PUNKTÓW ATAKU:";
		/* 8*/menu[7] = "SUMA PUNKTÓW OBRONY:";
		/* 9*/menu[8] = "MIKSTURY ZDROWIA:";
		/*10*/menu[9] = "";
		/*11*/menu[10] = "";
		/*12*/menu[11] = "";
		/*13*/menu[12] = "";
		/*14*/menu[13] = "";
		/*15*/menu[14] = "";
		/*16*/menu[15] = "";
		/*17*/menu[16] = "";
		/*18*/menu[17] = "";
		/*19*/menu[18] = "";
		/*20*/menu[19] = "";

		//wartosci glownych statow
		/* 1*/menu[20] = gracz.nazwa;
		/* 2*/menu[21] = gracz.skill;
		/* 3*/menu[22] = to_string(gracz.str);
		/* 4*/menu[23] = to_string(gracz.agility);
		/* 5*/menu[24] = to_string(gracz.intel);
		/* 6*/menu[25] = to_string(gracz.luck);
		/* 7*/menu[26] = to_string(gracz.weapon);
		/* 8*/menu[27] = "";
		/* 9*/menu[28] = "";
		/*10*/menu[29] = "";
		/*11*/menu[30] = "";
		/*12*/menu[31] = "";
		/*13*/menu[32] = "";
		/*14*/menu[33] = "";
		/*15*/menu[34] = "";
		/*16*/menu[35] = "";
		/*17*/menu[36] = "";
		/*18*/menu[37] = "";
		/*19*/menu[38] = "";
		/*20*/menu[39] = "";

		//Opcje w lokacji 48 znakow
		/* 1*/menu[40] = "UDERZ";
		/* 2*/menu[41] = "U¯YJ PRZEDMIOTU";
		/* 3*/menu[42] = "U¯YJ UMIEJÊTNOŒCI";
		/* 4*/menu[43] = "";
		/* 5*/menu[44] = "";
		/* 6*/menu[45] = "";
		/* 7*/menu[46] = "";
		/* 8*/menu[47] = "";
		/* 9*/menu[48] = "";
		/*10*/menu[49] = "";
		/*11*/menu[50] = "";
		/*12*/menu[51] = "";
		/*13*/menu[52] = "";
		/*14*/menu[53] = "";
		/*15*/menu[54] = "";
		/*16*/menu[55] = "";
		/*17*/menu[56] = "";
		/*18*/menu[57] = "";
		/*19*/menu[58] = "";
		/*20*/menu[59] = "";

		//Skroty 21 znakow
		/* 1*/menu[60] = "W: UCIEKAJ";
		/* 2*/menu[61] = "";
		/* 3*/menu[62] = "";
		/* 4*/menu[63] = "";
		/* 5*/menu[64] = "";
		/* 6*/menu[65] = "";
		/* 7*/menu[66] = "";
		/* 8*/menu[67] = "";
		/* 9*/menu[68] = "";
		/*10*/menu[69] = "";
		/*11*/menu[70] = "";
		/*12*/menu[71] = "";
		/*13*/menu[72] = "";
		/*14*/menu[73] = "";
		/*15*/menu[74] = "";
		/*16*/menu[75] = "";
		/*17*/menu[76] = "";
		/*18*/menu[77] = "";
		/*19*/menu[78] = "";
		/*20*/menu[79] = "";
		tab_fight(gracz, menu, enemy);
		cout << "Twój wybor to: ";
		string wyb;
		cin >> wyb;
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case '1':
		{
			int random = rand() % 100;
			cout << "Atakujesz przeciwnika" << endl;
			if (random>50)
			{
				sound_hit();
				cout << "Uderzasz swoj¹ broni¹ w przeciwnika" << endl;
				cout << "Uszkodzi³eœ go lecz dalej jest w stanie walczyæ" << endl;
				cout << "Przeciwnik traci " << gracz.weapon << " punktów ¿ycia" << endl;
				system("PAUSE");
				enemy.hp = enemy.hp - gracz.weapon;
				system("cls");
				if (enemy.hp < 0)
				{
					enemy.hp = 0;
				}
				tab_fight(gracz, menu, enemy);
			}
			else
			{
				cout << "Nie trafi³eœ" << endl;
				system("PAUSE");
				system("cls");
				tab_fight(gracz, menu, enemy);
			}
			if (enemy.hp <= 0)
			{
				sound_success();
				cout << "Wygra³eœ!!!" << endl;
				cout << "Przy swoim przeciwniku znajdujesz " << enemy.gold << " sztuk z³ota" << endl;
				cout << "Za walkê dostajesz " << enemy.xp << " punktów doœwiadczenia" << endl;
				gracz.exp = gracz.exp + enemy.xp;
				gracz.gold = gracz.gold + enemy.gold;
				range(gracz);
				system("PAUSE");
				return gracz;
			}
			else
			{
				random = rand() % 100;
				cout << "Przeciwnik atakuje!!!" << endl;
				if (random > 50)
				{
					sound_damage();
					cout << "Trafi³, zadaje ci " << enemy.damage <<" punktów obra¿eñ" << endl;
					gracz.hp = gracz.hp - enemy.damage;
					system("PAUSE");
				}
				else
				{
					cout << "Jesteœ dla niego za szybki, nie trafi³" << endl;
					system("PAUSE");
				}
			}
			break;
		}
		case 'w':
		{
			while (1)
			{
				cout << "Czy napewno uciec od walki, mo¿e to nieœæ ze sob¹ konsekwencje?" << endl;
				cout << "1.Tak" << endl;
				cout << "2.Nie" << endl;
				cout << "Twój wybór to: ";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					cout << "Uciekasz, jesteœ pizda a nie skoczek" << endl;
					system("PAUSE");
					return gracz;
				}
				case '2':
				{
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
		default:
		{
			break;
		}
		}
	}
}