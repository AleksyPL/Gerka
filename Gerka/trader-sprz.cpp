#include "biblioteki.h"
#include "ui.h"
#include "tabelka.h"

//player sprzedaj(player gracz, string numer)
//{
//	switch (numer[0])
//	{
//	case '1':
//	{
//		if (gracz.item1 == "")
//		{
//			cout << "Na tym miejscu nie masz ¿adnego przedmiotu!" << endl;
//		}
//		else
//		{
//			while (1)
//			{
//				cout << "Czy jesteœ pewien ,¿e chcesz sprzedaæ " << gracz.item1 << " za " << gracz.value_item1 << " z³ota?" << endl;
//				cout << "1.Tak" << endl;
//				cout << "2.Nie" << endl;
//				cout << "Twój wybór to: ";
//				string wyb;
//				cin >> wyb;
//				switch (wyb[0])
//				{
//				case '1':
//				{
//					sound_cash();
//					cout << "Przedmiot zosta³ sprzedany!" << endl;
//					gracz.item1 = "";
//					gracz.gold = gracz.gold + gracz.value_item1;
//					gracz.value_item1 = 0;
//					return gracz;
//				}
//				case '2':
//				{
//					break;
//				}
//				default:
//				{
//					break;
//				}
//				break;
//				}
//			}
//		}
//		break;
//	}
//	case '2':
//	{
//		if (gracz.item2 == "")
//		{
//			cout << "Na tym miejscu nie masz ¿adnego przedmiotu!" << endl;
//		}
//		else
//		{
//			while (1)
//			{
//				cout << "Czy jesteœ pewien ,¿e chcesz sprzedaæ " << gracz.item2 << " za " << gracz.value_item2 << " z³ota?" << endl;
//				cout << "1.Tak" << endl;
//				cout << "2.Nie" << endl;
//				cout << "Twój wybór to: ";
//				string wyb;
//				cin >> wyb;
//				switch (wyb[0])
//				{
//				case '1':
//				{
//					sound_cash();
//					cout << "Przedmiot zosta³ sprzedany!" << endl;
//					gracz.item2 = "";
//					gracz.gold = gracz.gold + gracz.value_item2;
//					gracz.value_item2 = 0;
//					return gracz;
//				}
//				case '2':
//				{
//					break;
//				}
//				default:
//				{
//					break;
//				}
//				break;
//				}
//			}
//		}
//		break;
//	}
//	case '3':
//	{
//		if (gracz.item3 == "")
//		{
//			cout << "Na tym miejscu nie masz ¿adnego przedmiotu!" << endl;
//		}
//		else
//		{
//			while (1)
//			{
//				cout << "Czy jesteœ pewien ,¿e chcesz sprzedaæ " << gracz.item3 << " za " << gracz.value_item3 << " z³ota?" << endl;
//				cout << "1.Tak" << endl;
//				cout << "2.Nie" << endl;
//				cout << "Twój wybór to: ";
//				string wyb;
//				cin >> wyb;
//				switch (wyb[0])
//				{
//				case '1':
//				{
//					sound_cash();
//					cout << "Przedmiot zosta³ sprzedany!" << endl;
//					gracz.item3 = "";
//					gracz.gold = gracz.gold + gracz.value_item3;
//					gracz.value_item3 = 0;
//					return gracz;
//				}
//				case '2':
//				{
//					break;
//				}
//				default:
//				{
//					break;
//				}
//				break;
//				}
//			}
//		}
//		break;
//	}
//	default:
//	{
//		system("cls");
//		break;
//	}
//	}
//	return gracz;
//}
//
//player trade_sprz(player gracz)
//{
//	while (1)
//	{
//		if (gracz.item1 == "" && gracz.item2 == "" && gracz.item3 == "")
//		{
//			cout << endl << "Nie masz przy sobie ¿adnych przedmiotów!!!" << endl;
//			system("PAUSE");
//			return gracz;
//		}
//		system("cls");
//		string menu[80];
//		string info[8];
//		info[0] = "HANDLARZ - SPRZEDAJ PRZEDMIOTY";
//		info[1] = "W: WRÓÆ NA RYNEK";
//		info[2] = "M: MIKSTURA ¯YCIA";
//		info[3] = "";
//		info[4] = "";
//		info[5] = "";
//		info[6] = "";
//		info[7] = "";
//		long ceny[20];
//
//		/* 1*/menu[0] = "IMIÊ POSTACI:";
//		/* 2*/menu[1] = "UMIEJÊTNOŒÆ POSTACI:";
//		/* 3*/menu[2] = "PUNKTY SI£Y:";
//		/* 4*/menu[3] = "PUNKTY ZRÊCZNOŒCI:";
//		/* 5*/menu[4] = "PUNKTY INTELIGENCJI:";
//		/* 6*/menu[5] = "PUNKTY SZCZÊŒCIA:";
//		/* 7*/menu[6] = "SUMA PUNKTÓW ATAKU:";
//		/* 8*/menu[7] = "SUMA PUNKTÓW OBRONY:";
//		/* 9*/menu[8] = "MIKSTURY ¯YCIA:";
//		/*10*/menu[9] = "PRZEDMIOT 1:";
//		/*11*/menu[10] = "PRZEDMIOT 2:";
//		/*12*/menu[11] = "PRZEDMIOT 3:";
//		/*13*/menu[12] = "";
//		/*14*/menu[13] = "";
//		/*15*/menu[14] = "";
//		/*16*/menu[15] = "";
//		/*17*/menu[16] = "";
//		/*18*/menu[17] = "";
//		/*19*/menu[18] = "";
//		/*20*/menu[19] = "";
//
//		//wartosci glownych statow
//		/* 1*/menu[20] = gracz.nazwa;
//		/* 2*/menu[21] = gracz.skill;
//		/* 3*/menu[22] = to_string(gracz.str);
//		/* 4*/menu[23] = to_string(gracz.agility);
//		/* 5*/menu[24] = to_string(gracz.intel);
//		/* 6*/menu[25] = to_string(gracz.luck);
//		/* 7*/menu[26] = to_string(gracz.weapon);
//		/* 8*/menu[27] = to_string(gracz.helmet + gracz.chestplate + gracz.gloves + gracz.pants + gracz.shoes + gracz.shield);
//		/* 9*/menu[28] = to_string(gracz.potion);
//		/*10*/menu[29] = gracz.item1;
//		/*11*/menu[30] = gracz.item2;
//		/*12*/menu[31] = gracz.item3;
//		/*13*/menu[32] = "";
//		/*14*/menu[33] = "";
//		/*15*/menu[34] = "";
//		/*16*/menu[35] = "";
//		/*17*/menu[36] = "";
//		/*18*/menu[37] = "";
//		/*19*/menu[38] = "";
//		/*20*/menu[39] = "";
//
//		//Opcje w lokacji 35 znakow
//		/* 1*/menu[40] = gracz.item1;
//		/* 2*/menu[41] = gracz.item2;
//		/* 3*/menu[42] = gracz.item3;
//		/* 4*/menu[43] = "";
//		/* 5*/menu[44] = "";
//		/* 6*/menu[45] = "";
//		/* 7*/menu[46] = "";
//		/* 8*/menu[47] = "";
//		/* 9*/menu[48] = "";
//		/*10*/menu[49] = "";
//		/*11*/menu[50] = "";
//		/*12*/menu[51] = "";
//		/*13*/menu[52] = "";
//		/*14*/menu[53] = "";
//		/*15*/menu[54] = "";
//		/*16*/menu[55] = "";
//		/*17*/menu[56] = "";
//		/*18*/menu[57] = "";
//		/*19*/menu[58] = "";
//		/*20*/menu[59] = "";
//
//		//Skroty 21 znakow
//		/* 1*/menu[60] = "W: WRÓÆ DO WYBRORU";
//		/* 2*/menu[61] = "M: MIKSTURA ¯YCIA";
//		/* 3*/menu[62] = "";
//		/* 4*/menu[63] = "";
//		/* 5*/menu[64] = "";
//		/* 6*/menu[65] = "";
//		/* 7*/menu[66] = "";
//		/* 8*/menu[67] = "";
//		/* 9*/menu[68] = "";
//		/*10*/menu[69] = "";
//		/*11*/menu[70] = "";
//		/*12*/menu[71] = "";
//		/*13*/menu[72] = "";
//		/*14*/menu[73] = "";
//		/*15*/menu[74] = "";
//		/*16*/menu[75] = "";
//		/*17*/menu[76] = "";
//		/*18*/menu[77] = "";
//		/*19*/menu[78] = "";
//		/*20*/menu[79] = "";
//
//		ceny[0] = gracz.value_item1;
//		ceny[1] = gracz.value_item2;
//		ceny[2] = gracz.value_item3;
//		ceny[3] = 0;
//		ceny[4] = 0;
//		ceny[5] = 0;
//		ceny[6] = 0;
//		ceny[7] = 0;
//		ceny[8] = 0;
//		ceny[9] = 0;
//		ceny[10] = 0;
//		ceny[11] = 0;
//		ceny[12] = 0;
//		ceny[13] = 0;
//		ceny[14] = 0;
//		ceny[15] = 0;
//		ceny[16] = 0;
//		ceny[17] = 0;
//		ceny[18] = 0;
//		ceny[19] = 0;
//
//		for (int i = 0; i < 20; i++)
//		{
//			if (ceny[i] > 10000)
//			{
//				ceny[i] = 10000;
//			}
//			else if (ceny[i] < 0)
//			{
//				ceny[i] = 0;
//			}
//		}
//
//		int tryb = 2;
//		tab_items(gracz, info, menu, ceny, tryb);
//		cout << "Twój wybór to: ";
//		string wyb;
//		cin >> wyb;
//		switch (wyb[0])
//		{
//		case '1':
//		{
//			gracz = sprzedaj(gracz, wyb);
//			system("PAUSE");
//			break;
//		}
//		case '2':
//		{
//			gracz = sprzedaj(gracz, wyb);
//			system("PAUSE");
//			break;
//		}
//		case '3':
//		{
//			gracz = sprzedaj(gracz, wyb);
//			system("PAUSE");
//			break;
//		}
//		case 'M':
//		{
//			gracz.use_hp_potion();
//			break;
//		}
//		case 'm':
//		{
//			gracz.use_hp_potion();
//			break;
//		}
//		case 'W':
//		{
//			return gracz;
//		}
//		case 'w':
//		{
//			return gracz;
//		}
//		default:
//		{
//			system("cls");
//			break;
//		}
//		}
//	}
//}