#include "tawerna.h"
#include "tabelka.h"
#include "zakres.h"
#include "czas.h"
#include "karty.h"
#include "seksik.h"
#include "level_up.h"
#include "chest.h"
#include "sleep.h"
#include "wait.h"

void drunked(player &gracz)
{
	cout << "JESTEŒ TAK PIJANY ,¯E ZASYPIASZ W KARCZMIE!!!" << endl;
	system("PAUSE");
	robbery(gracz);
	change_time(gracz, 8, 0);
}

void robbery(player &gracz)
{
	srand((unsigned int)time(NULL));
	int rand1 = rand() % 100;
	int rand2 = rand() % 100+gracz.luck;
	if (rand2 < rand1 && gracz.gold>0)
	{
		if (gracz.gold > 10000)
		{
			cout << "KTOŒ UKRAD£ CI CZÊŒÆ PIENIÊDZY" << endl;
			gracz.gold=gracz.gold - (0.2*gracz.gold);
		}
		else if (gracz.gold > 1000)
		{
			cout << "KTOŒ UKRAD£ CI CZÊŒÆ PIENIÊDZY" << endl;
			gracz.gold = gracz.gold - (0.1*gracz.gold);
		}
		else
		{
			cout << "KTOŒ UKRAD£ CI CZÊŒÆ PIENIÊDZY" << endl;
			gracz.gold = gracz.gold - (0.05*gracz.gold);
		}
	}
	else
	{
		cout << "Bezpiecznie przesypiasz noc" << endl;
	}
	system("PAUSE");
}

void flirting(player &gracz,string info)
{
	srand((unsigned int)time(NULL));
	int sukces = rand() % 100;
	int sukces2 = rand() % 100+gracz.luck;
	if (sukces2 > sukces)
	{
		cout << "Uda³o ci siê poderwaæ ³adn¹ dziewczynê" << endl;
		cout << "Ma na imiê ";
		string linia;
		int nr_linii = 1;
		fstream plik;
		{
			int rand1 = rand() % 10;
			if (rand1 == 0)
			{
				plik.open("./txt/tawerna/imie0.txt", ios::in);
			}
			else if (rand1 == 1)
			{
				plik.open("./txt/tawerna/imie1.txt", ios::in);
			}
			else if (rand1 == 2)
			{
				plik.open("./txt/tawerna/imie2.txt", ios::in);
			}
			else if (rand1 == 3)
			{
				plik.open("./txt/tawerna/imie3.txt", ios::in);
			}
			else if (rand1 == 4)
			{
				plik.open("./txt/tawerna/imie4.txt", ios::in);
			}
			else if (rand1 == 5)
			{
				plik.open("./txt/tawerna/imie5.txt", ios::in);
			}
			else if (rand1 == 6)
			{
				plik.open("./txt/tawerna/imie6.txt", ios::in);
			}
			else if (rand1 == 7)
			{
				plik.open("./txt/tawerna/imie7.txt", ios::in);
			}
			else if (rand1 == 8)
			{
				plik.open("./txt/tawerna/imie8.txt", ios::in);
			}
			else if (rand1 == 9)
			{
				plik.open("./txt/tawerna/imie9.txt", ios::in);
			}
		}
		while (!plik.eof())
		{
			getline(plik, linia);
			cout << linia << endl;
		}
		plik.close();
		if (gracz.alko != 0)
		{
			cout << "Randka przebiega przyjemnie, oboje jesteœcie trochê pijani" << endl;
		}
		sukces = rand() % 100;
		sukces2 = rand() % 20 + gracz.luck;
		system("PAUSE");
		if (sukces2 < sukces)
		{
			cout << "Okazuje siê, ¿e przysz³a z jakimœ goœciem, zaczynacie siê szarpaæ" << endl;
			system("PAUSE");
			int rand1 = rand() % 3;
			gracz = fight(gracz, rand1);
		}
		while (1)
		{
			cout << "Czy chcesz siê zabawiæ?" << endl;
			cout << "1.Tak" << endl;
			cout << "2.Nie" << endl;
			cout << "Twój wybór to: ";
			string wyb;
			cin >> wyb;
			switch (wyb[0])
			{
				case '1':
				{
					have_sex(gracz,0,info);
					sleep(gracz, 0,8,0);
					break;
				}
				case '2':
				{
					cout << "Szkoda" << endl;
					system("PAUSE");
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
	}
	else
	{
		cout << "Nie uda³o ci siê nikogo poderwaæ, ale nie poddawaj siê!" << endl;
		system("PAUSE");
	}
}

player enter_tavern(player gracz,barman bobby, chest &krzynka)
{
	change_time(gracz, 0, 5);
	int tryb = 0;
	while (1)
	{
		level_up(gracz);
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		system("cls");
		string info[8];
		string menu[60];
		long ceny[20]; 

		//glowne staty 23 znaki
		/* 1*/menu[0] = "PUNKTY SI£Y:";
		/* 2*/menu[1] = "PUNKTY ZRÊCZNOŒCI:";
		/* 3*/menu[2] = "PUNKTY INTELIGENCJI:";
		/* 4*/menu[3] = "PUNKTY CHARYZMY:";
		/* 5*/menu[4] = "PUNKTY SZCZÊŒCIA:";
		/* 6*/menu[5] = "";
		/* 7*/menu[6] = "";
		/* 8*/menu[7] = "";
		/* 9*/menu[8] = "";
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
		/* 1*/menu[20] = to_string(gracz.str);
		/* 2*/menu[21] = to_string(gracz.agility);
		/* 3*/menu[22] = to_string(gracz.intel);
		/* 4*/menu[23] = to_string(gracz.charisma);
		/* 5*/menu[24] = to_string(gracz.luck);
		/* 6*/menu[25] = "";
		/* 7*/menu[26] = "";
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

		if (tryb == 1)
		{
			/* 1*/menu[40] = bobby.menu[0];
			/* 2*/menu[41] = bobby.menu[1];
			/* 3*/menu[42] = bobby.menu[2];
			/* 4*/menu[43] = bobby.menu[3];
			/* 5*/menu[44] = bobby.menu[4];
			/* 6*/menu[45] = bobby.menu[5];
			/* 7*/menu[46] = bobby.menu[6];
			/* 8*/menu[47] = bobby.menu[7];
			/* 9*/menu[48] = bobby.menu[8];
			/*10*/menu[49] = bobby.menu[9];
			/*11*/menu[50] = bobby.menu[10];
			/*12*/menu[51] = bobby.menu[11];
			/*13*/menu[52] = bobby.menu[12];
			/*14*/menu[53] = bobby.menu[13];
			/*15*/menu[54] = bobby.menu[14];
			/*16*/menu[55] = bobby.menu[15];
			/*17*/menu[56] = bobby.menu[16];
			/*18*/menu[57] = bobby.menu[17];
			/*19*/menu[58] = bobby.menu[18];
			/*20*/menu[59] = bobby.menu[19];
			/* 1*/ceny[0] = bobby.ceny[0];
			/* 2*/ceny[1] = bobby.ceny[1];
			/* 3*/ceny[2] = bobby.ceny[2];
			/* 4*/ceny[3] = bobby.ceny[3];
			/* 5*/ceny[4] = bobby.ceny[4];
			/* 6*/ceny[5] = bobby.ceny[5];
			/* 7*/ceny[6] = bobby.ceny[6];
			/* 8*/ceny[7] = bobby.ceny[7];
			/* 9*/ceny[8] = bobby.ceny[8];
			/*10*/ceny[9] = bobby.ceny[9];
			/*11*/ceny[10] = bobby.ceny[10];
			/*12*/ceny[11] = bobby.ceny[11];
			/*13*/ceny[12] = bobby.ceny[12];
			/*14*/ceny[13] = bobby.ceny[13];
			/*15*/ceny[14] = bobby.ceny[14];
			/*16*/ceny[15] = bobby.ceny[15];
			/*17*/ceny[16] = bobby.ceny[16];
			/*18*/ceny[17] = bobby.ceny[17];
			/*19*/ceny[18] = bobby.ceny[18];
			/*20*/ceny[19] = bobby.ceny[19];
			info[0] = bobby.info[0];
			info[1] = bobby.info[1];
			info[2] = bobby.info[2];
			info[3] = bobby.info[3];
			info[4] = bobby.info[4];
			info[5] = bobby.info[5];
			info[6] = bobby.info[6];
			info[7] = bobby.info[7];
		}
		else
		{
			/* 1*/menu[40] = "POROZMAWIAJ Z BARMANEM";
			/* 2*/menu[41] = "SZUKAJ KOGOŒ DO GRY W KARTY";
			/* 3*/menu[42] = "PROWOKUJ WALKÊ";
			/* 4*/menu[43] = "SZUKAJ DRU¯YNY";
			/* 5*/menu[44] = "PODRYWAJ DZIEWCZYNY";
			/* 6*/menu[45] = "PRZECHOWAJ PRZEDMIOTY W SKRZYNI";
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
			ceny[0] = 0;
			ceny[1] = 0;
			ceny[2] = 0;
			ceny[3] = 0;
			ceny[4] = 0;
			ceny[5] = 0;
			ceny[6] = 0;
			ceny[7] = 0;
			ceny[8] = 0;
			ceny[9] = 0;
			ceny[10] = 0;
			ceny[11] = 0;
			ceny[12] = 0;
			ceny[13] = 0;
			ceny[14] = 0;
			ceny[15] = 0;
			ceny[16] = 0;
			ceny[17] = 0;
			ceny[18] = 0;
			ceny[19] = 0;
			info[0] = "TAWERNA";
			info[1] = "W: WRÓÆ NA RYNEK";
			info[2] = "C: CZEKAJ";
			info[3] = "";
			info[4] = "";
			info[5] = "";
			info[6] = "";
			info[7] = "";
		}


		for (int i = 0; i < 20; i++)
		{
			if (ceny[i] > 10000)
			{
				ceny[i] = 10000;
			}
			else if (ceny[i] < 0)
			{
				ceny[i] = 0;
			}
		}
		tab(gracz,info, menu, ceny);
		cout << "Twoj wybor to: ";
		string wyb;
		cin >> wyb;
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case '1':
		{
			if (tryb == 0)
			{
				change_time(gracz, 0, 1);
				tryb = 1;
			}
			else
			{
				bobby.gossip(gracz);
			}
			break;
		}
		case '2':
		{
			if (tryb == 0)
			{
				gambling(gracz);
				range(gracz);
			}
			else
			{
				bobby.give_room(gracz);
			}
			break;
		}
		case '3':
		{
			if (tryb == 0)
			{
				int rand1 = rand() % 3;
				gracz = fight(gracz, rand1);
			}
			else
			{
				bobby.sell_food(gracz, 2);
			}
			break;
		}
		case '4':
		{
			if (gracz.alko == 10 && tryb == 1)
			{
				drunked(gracz);
			}
			else if (tryb == 1)
			{
				bobby.sell_beer(gracz);
			}
			break;
		}
		case '5':
		{
			if (tryb == 0)
			{
				flirting(gracz,info[0]);
			}
			else
			{
				;
			}
			break;
		}
		case '6':
		{
			if (tryb == 0)
			{
				enter_chest_mode(gracz,krzynka);
			}
			else
			{
				;
			}
			break;
		}
		case 'c':
		{
			gracz = wait_n_hours(gracz);
			break;
		}
		case 'w':
		{
			if (gracz.alko == 10 && tryb == 0)
			{
				drunked(gracz);
				break;
			}
			else if (tryb == 0)
			{
				change_time(gracz, 0, 5);
				return gracz;
			}
			else if (tryb == 1)
			{
				tryb = 0;
				change_time(gracz, 0, 1);
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