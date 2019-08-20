#include "biblioteki.h"
#include "trader.h"
#include "player.h"
#include "tabelka.h"

void nadaj_towar_kup(string menu[80], long ceny[20])
{
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/mix/przedmioty.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1:
		{
			menu[40] = linia;
			break;
		}
		case 2:ceny[0] = atoi(linia.c_str()); break;
		case 3:
		{
			menu[41] = linia;
			break;
		}
		case 4:ceny[1] = atoi(linia.c_str()); break;
		case 5:
		{
			menu[42] = linia;
			break;
		}
		case 6:ceny[2] = atoi(linia.c_str()); break;
		case 7:
		{
			menu[43] = linia;
			break;
		}
		case 8:ceny[3] = atoi(linia.c_str()); break;
		case 9:
		{
			menu[44] = linia;
			break;
		}
		case 10:ceny[4] = atoi(linia.c_str()); break;
		case 11:
		{
			menu[45] = linia;
			break;
		}
		case 12:ceny[5] = atoi(linia.c_str()); break;
		case 13:
		{
			menu[46] = linia;
			break;
		}
		case 14:ceny[6] = atoi(linia.c_str()); break;
		case 15:
		{
			menu[47] = linia;
			break;
		}
		case 16:ceny[7] = atoi(linia.c_str()); break;
		case 17:
		{
			menu[48] = linia;
			break;
		}
		case 18:ceny[8] = atoi(linia.c_str()); break;
		case 19:
		{
			menu[49] = linia;
			break;
		}
		case 20:ceny[9] = atoi(linia.c_str()); break;
		case 21:
		{
			menu[50] = linia;
			break;
		}
		case 22:ceny[10] = atoi(linia.c_str()); break;
		case 23:
		{
			menu[51] = linia;
			break;
		}
		case 24:ceny[11] = atoi(linia.c_str()); break;
		case 25:
		{
			menu[52] = linia;
			break;
		}
		case 26:ceny[12] = atoi(linia.c_str()); break;
		case 27:
		{
			menu[53] = linia;
			break;
		}
		case 28:ceny[13] = atoi(linia.c_str()); break;
		case 29:
		{
			menu[54] = linia;
			break;
		}
		case 30:ceny[14] = atoi(linia.c_str()); break;
		case 31:
		{
			menu[55] = linia;
			break;
		}
		case 32:ceny[15] = atoi(linia.c_str()); break;
		case 33:
		{
			menu[56] = linia;
			break;
		}
		case 34:ceny[16] = atoi(linia.c_str()); break;
		case 35:
		{
			menu[57] = linia;
			break;
		}
		case 36:ceny[17] = atoi(linia.c_str()); break;
		case 37:
		{
			menu[58] = linia;
			break;
		}
		case 38:ceny[18] = atoi(linia.c_str()); break;
		case 39:
		{
			menu[59] = linia;
			break;
		}
		case 40:ceny[19] = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	plik.close();
}

//player kup(player gracz, int cenka, string przedmiot)
//{
//	if (gracz.item1 == przedmiot || gracz.item2 == przedmiot || gracz.item3 == przedmiot)
//	{
//		cout << endl << "Masz ju¿ ten przedmiot!!!" << endl;
//	}
//	else if (gracz.gold >= cenka)
//	{
//		if (gracz.item1 != "" && gracz.item2 != "" && gracz.item3 != "")
//		{
//			cout << endl << "Nie masz miejsca na ten przedmiot, musisz coœ sprzedaæ!" << endl;
//		}
//		else
//		{
//			while (1)
//			{
//				cout << "Na którym miejscu chcesz umieœciæ przedmiot?: ";
//				string wyb;
//				cin >> wyb;
//				switch (wyb[0])
//				{
//				case '1':
//				{
//					if (gracz.item1 != "")
//					{
//						cout << "To miejsce jest zajête!" << endl;
//
//					}
//					else
//					{
//						sound_cash();
//						cout << "Przedmiot zosta³ zakupiony" << endl;
//						gracz.item1 = przedmiot;
//						gracz.gold = gracz.gold - cenka;
//						gracz.value_item1 = cenka;
//						return gracz;
//					}
//					break;
//				}
//				case '2':
//				{
//					if (gracz.item2 != "")
//					{
//						cout << "To miejsce jest zajête!" << endl;
//
//					}
//					else
//					{
//						sound_cash();
//						cout << "Przedmiot zosta³ zakupiony" << endl;
//						gracz.item2 = przedmiot;
//						gracz.gold = gracz.gold - cenka;
//						gracz.value_item2 = cenka;
//						return gracz;
//					}
//					break;
//				}
//				case '3':
//				{
//					if (gracz.item3 != "")
//					{
//						cout << "To miejsce jest zajête!" << endl;
//
//					}
//					else
//					{
//						sound_cash();
//						cout << "Przedmiot zosta³ zakupiony" << endl;
//						gracz.item3 = przedmiot;
//						gracz.gold = gracz.gold - cenka;
//						gracz.value_item3 = cenka;
//						return gracz;
//					}
//					break;
//				}
//				default:
//				{
//					break;
//				}
//				}
//			}
//		}
//	}
//	else
//	{
//		cout << endl << "Masz za ma³o pieniêdzy!!!" << endl;
//	}
//	return gracz;
//}

player trade_kup(player gracz)
{
	while (1)
	{
		system("cls");
		string menu[80];
		string info[8];
		info[0] = "HANDLARZ - KUP PRZEDMIOTY";
		info[1] = "W: WRÓÆ NA RYNEK";
		info[2] = "M: MIKSTURA ¯YCIA";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[7] = "";
		long ceny[20];
		int tryb = 0;

		/* 1*/menu[0] = "IMIÊ POSTACI:";
		/* 2*/menu[1] = "UMIEJÊTNOŒÆ POSTACI:";
		/* 3*/menu[2] = "PUNKTY SI£Y:";
		/* 4*/menu[3] = "PUNKTY ZRÊCZNOŒCI:";
		/* 5*/menu[4] = "PUNKTY INTELIGENCJI:";
		/* 6*/menu[5] = "PUNKTY SZCZÊŒCIA:";
		/* 7*/menu[6] = "SUMA PUNKTÓW ATAKU:";
		/* 8*/menu[7] = "SUMA PUNKTÓW OBRONY:";
		/* 9*/menu[8] = "MIKSTURY ¯YCIA:";
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

		//Opcje w lokacji 35 znakow
		/* 1*/menu[40] = "";
		/* 2*/menu[41] = "";
		/* 3*/menu[42] = "";
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
		/* 1*/menu[60] = "W: WRÓÆ DO WYBRORU";
		/* 2*/menu[61] = "M: MIKSTURA ¯YCIA";
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
		tryb = 1;
		nadaj_towar_kup(menu, ceny);
		//tab_items(gracz, info, menu, ceny,tryb);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		if (wyb[0] == '1' && wyb[1] == '\0')
		{
			if (menu[40] != "")
			{
				//gracz = kup(gracz, ceny[0], menu[40]);
				system("PAUSE");
			}
		}
		else if (wyb[0] == '2' && wyb[1] == '\0')
		{
			if (menu[41] != "")
			{
				//gracz = kup(gracz, ceny[1], menu[41]);
				system("PAUSE");
			}
		}
		else if (wyb[0] == '2' && wyb[1] == '0')
		{
			if (menu[59] != "")
			{
				//gracz = kup(gracz, ceny[19], menu[59]);
				system("PAUSE");
			}
		}
		else if (wyb[0] == '1')
		{
			switch (wyb[1])
			{
			case '0':
			{
				if (menu[49] != "")
				{
					//gracz = kup(gracz, ceny[9], menu[49]);
					system("PAUSE");
				}
				break;
			}
			case '1':
			{
				if (menu[50] != "")
				{
					//gracz = kup(gracz, ceny[10], menu[50]);
					system("PAUSE");
				}
				break;
			}
			case '2':
			{
				if (menu[51] != "")
				{
					//gracz = kup(gracz, ceny[11], menu[51]);
					system("PAUSE");
				}
				break;
			}
			case '3':
			{
				if (menu[52] != "")
				{
					//gracz = kup(gracz, ceny[12], menu[52]);
					system("PAUSE");
				}
				break;
			}
			case '4':
			{
				if (menu[53] != "")
				{
					//gracz = kup(gracz, ceny[13], menu[53]);
					system("PAUSE");
				}
				break;
			}
			case '5':
			{
				if (menu[54] != "")
				{
					//gracz = kup(gracz, ceny[14], menu[54]);
					system("PAUSE");
				}
				break;
			}
			case '6':
			{
				if (menu[55] != "")
				{
					//gracz = kup(gracz, ceny[15], menu[55]);
					system("PAUSE");
				}
				break;
			}
			case '7':
			{
				if (menu[56] != "")
				{
					//gracz = kup(gracz, ceny[16], menu[56]);
					system("PAUSE");
				}
				break;
			}
			case '8':
			{
				if (menu[57] != "")
				{
					//gracz = kup(gracz, ceny[17], menu[57]);
					system("PAUSE");
				}
				break;
			}
			case '9':
			{
				if (menu[58] != "")
				{
					//gracz = kup(gracz, ceny[18], menu[58]);
					system("PAUSE");
				}
				break;
			}
			case 'M':
			{
				gracz.use_hp_potion();
				break;
			}
			case 'm':
			{
				gracz.use_hp_potion();
				break;
			}
			case 'W':
			{
				return gracz;
			}
			case 'w':
			{
				return gracz;
			}
			default:
			{
				system("cls");
				break;
			}
			}
		}
		else
		{
			switch (wyb[0])
			{
			case '3':
			{
				if (menu[42] != "")
				{
					//gracz = kup(gracz, ceny[2], menu[42]);
					system("PAUSE");
				}
				break;
			}
			case '4':
			{
				if (menu[43] != "")
				{
					//gracz = kup(gracz, ceny[3], menu[43]);
					system("PAUSE");
				}
				break;
			}
			case '5':
			{
				if (menu[44] != "")
				{
					//gracz = kup(gracz, ceny[4], menu[44]);
					system("PAUSE");
				}
				break;
			}
			case '6':
			{
				if (menu[45] != "")
				{
					//gracz = kup(gracz, ceny[5], menu[45]);
					system("PAUSE");
				}
				break;
			}
			case '7':
			{
				if (menu[46] != "")
				{
					//gracz = kup(gracz, ceny[6], menu[46]);
					system("PAUSE");
				}
				break;
			}
			case '8':
			{
				if (menu[47] != "")
				{
					//gracz = kup(gracz, ceny[7], menu[47]);
					system("PAUSE");
				}
				break;
			}
			case '9':
			{
				if (menu[48] != "")
				{
					//gracz = kup(gracz, ceny[8], menu[48]);
					system("PAUSE");
				}
				break;
			}
			case 'W':
			{
				return gracz;
			}
			case 'w':
			{
				return gracz;
			}
			default:
			{
				system("cls");
				break;
			}
		}
		}
	}
}