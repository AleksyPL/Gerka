#include "biblioteki.h"
#include "tabelka.h"
#include "dwellers.h"


player trade_mode(player &gracz, seller &handlarz)
{
	handlarz.load_merch();
	handlarz.add_prices(gracz);
	string temp_table[80];
	int temp_table_price[80];
	int temp_table_amount[80];
	int strona_1 = 0;
	int strona_2 = 0;
	int counter_seller;
	int counter_player;
	for (int i = 0; i < 80; i++)
	{
		temp_table_amount[i] = 0;
		if (temp_table_amount[i] == 0)
		{
			temp_table_price[i] = 0;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		temp_table_price[20 + i] = 0;
		temp_table_price[60 + i] = 0;
		temp_table[20 + i] = handlarz.menu_items[i];
		temp_table_price[20 + i] = handlarz.menu_price[i];
		temp_table[60 + i] = gracz.inventory_usage[i];
		temp_table_price[60 + i] = gracz.inventory_usage_price[i];
		temp_table_amount[60 + i] = gracz.inventory_usage_amount[i];
	}
	string info2[7];
	info2[0] = "";
	info2[1] = "";
	info2[2] = "W: ZAKOÑCZ HANDEL";
	info2[3] = "Z: ZAAKCEPTUJ";
	info2[4] = "";
	info2[5] = "";
	info2[6] = "";
	while (1)
	{
		if (strona_1 == 0)
		{
			info2[0] = "";
			info2[1] = "N1: NASTÊPNA STR";
		}
		else if(strona_1 == 1)
		{
			info2[0] = "P1: POPRZEDNIA STR";
			info2[1] = "N1: NASTÊPNA STR";
		}
		else if (strona_1 == 2)
		{
			info2[0] = "P1: POPRZEDNIA STR";
			info2[1] = "N1: NASTÊPNA STR";
		}
		else if (strona_1 == 3)
		{
			info2[0] = "P1: POPRZEDNIA STR";
			info2[1] = "";
		}
		if (strona_2 == 0)
		{
			info2[5] = "";
			info2[6] = "N2: NASTÊPNA STR";
		}
		else if (strona_2 == 1)
		{
			info2[5] = "P2: POPRZEDNIA STR";
			info2[6] = "";
		}
		int licznik = 0;
		int licznik1 = 0;
		int licznik3 = 0;
		int licznik4 = 0;
		for (int i = 0; i < 20; i++)
		{
			//wybrane itemy do transakcji
			if (temp_table[i] == "" && temp_table_amount[i] == 0 && temp_table_price[i] == 0)
			{
				licznik++;
			}
			if (temp_table[40 + i] == "" && temp_table_amount[40 + i] == 0 && temp_table_price[40 + i] == 0)
			{
				licznik1++;
			}
			if (licznik == 20)
			{
				temp_table[0] = "BRAK WYBRANYCH PRZEDMIOTÓW";
			}
			if (licznik1 == 20)
			{
				temp_table[40] = "BRAK WYBRANYCH PRZEDMIOTÓW";
			}
			//reszta itemów z plecaka
			if (temp_table[20 + i] == "" && temp_table_amount[20 + i] == 0)
			{
				temp_table_price[20 + i] = 0;
				licznik3++;
			}
			if (temp_table[60 + i] == "" && temp_table_amount[60 + i] == 0)
			{
				temp_table_price[60 + i] = 0;
				licznik4++;
			}
			if (licznik3 == 20)
			{
				temp_table[20] = "HANDLARZ NIC NIE SPRZEDAJE";
			}
			if (licznik4 == 20)
			{
				temp_table[60] = "PLECAK JEST PUSTY";
			}
		}
		counter_seller = 0;
		counter_player = 0;
		if (temp_table[0] == "BRAK WYBRANYCH PRZEDMIOTÓW")
		{
			counter_seller = 0;
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (temp_table[i] != "")
				{
					counter_seller++;
				}
			}
		}
		if (temp_table[40 + 0] == "BRAK WYBRANYCH PRZEDMIOTÓW")
		{
			counter_player = 0;
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (temp_table[40 + i] !="")
				{
					counter_player++;
				}
			}
		}
		tab_trade(gracz, handlarz, temp_table, info2, temp_table_price, temp_table_amount);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				break;
			}
			if (wyb[1] == '2')
			{
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '2':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				for (int i = 0; i < 20; i++)
				{
					if (temp_table[i] == temp_table[20])
					{
						temp_table_amount[i]++;
						temp_table_price[i] = temp_table_price[20];
						break;
					}
					else if (temp_table[i] == "BRAK WYBRANYCH PRZEDMIOTÓW")
					{
						temp_table[i] = temp_table[20];
						temp_table_price[i] = temp_table_price[20];
						temp_table_amount[i]++;
						break;
					}
					else if (temp_table[i] == "")
					{
						temp_table[i] = temp_table[20];
						temp_table_price[i] = temp_table_price[20];
						temp_table_amount[i]++;
						break;
					}
				}
				break;
			}
			if (wyb[1] == '2')
			{
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '3':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				break;
			}
			if (wyb[1] == '2')
			{
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '4':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				break;
			}
			if (wyb[1] == '2')
			{
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '5':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				break;
			}
			if (wyb[1] == '2')
			{
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '6':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				for (int i = 0; i < 20; i++)
				{
					if (temp_table[40 + i] == temp_table[60])
					{
						temp_table_amount[40 + i]++;
						temp_table_price[40 + i] = temp_table_price[60];
						temp_table_amount[60]--;
						if (temp_table_amount[60] == 0)
						{
							temp_table[60] = "";
							if (strona_2 == 0)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
							else if (strona_2 == 1)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
						}
						break;
					}
					else if (temp_table[40 + i] == "BRAK WYBRANYCH PRZEDMIOTÓW")
					{
						temp_table[40 + i] = temp_table[60];
						temp_table_price[40 + i] = temp_table_price[60];
						temp_table_amount[40 + i]++;
						temp_table_amount[60]--;
						if (temp_table_amount[60] == 0)
						{
							temp_table[60] = "";
							if (strona_2 == 0)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
							else if (strona_2 == 1)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
						}
						break;
					}
					else if (temp_table[40 + i] == "")
					{
						temp_table[40 + i] = temp_table[60];
						temp_table_price[40 + i] = temp_table_price[60];
						temp_table_amount[40 + i]++;
						temp_table_amount[60]--;
						if (temp_table_amount[60] == 0)
						{
							temp_table[60] = "";
							if (strona_2 == 0)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
							else if (strona_2 == 1)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
						}
						break;
					}
				}
				break;
			}
			if (wyb[1] == '2')
			{
				for (int i = 0; i < 20; i++)
				{
					if (temp_table[40 + i] == temp_table[61])
					{
						temp_table_amount[40 + i]++;
						temp_table_price[40 + i] = temp_table_price[61];
						temp_table_amount[61]--;
						if (temp_table_amount[61] == 0)
						{
							temp_table[61] = "";
							if (strona_2 == 0)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
							else if (strona_2 == 1)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
						}
						break;
					}
					else if (temp_table[40 + i] == "BRAK WYBRANYCH PRZEDMIOTÓW")
					{
						temp_table[40 + i] = temp_table[61];
						temp_table_price[40 + i] = temp_table_price[61];
						temp_table_amount[40 + i]++;
						temp_table_amount[61]--;
						if (temp_table_amount[61] == 0)
						{
							temp_table[61] = "";
							if (strona_2 == 0)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
							else if (strona_2 == 1)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
						}
						break;
					}
					else if (temp_table[40 + i] == "")
					{
						temp_table[40 + i] = temp_table[61];
						temp_table_price[40 + i] = temp_table_price[61];
						temp_table_amount[40 + i]++;
						temp_table_amount[61]--;
						if (temp_table_amount[61] == 0)
						{
							temp_table[61] = "";
							if (strona_2 == 0)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
							else if (strona_2 == 1)
							{
								for (int i = 0; i < 20; i++)
								{
									if (temp_table[60 + i] != "")
									{
										continue;
									}
									else
									{
										for (int j = i + 1; j < 20; j++)
										{
											if (temp_table[60 + j] != "")
											{
												temp_table[60 + i] = temp_table[60 + j];
												temp_table_amount[60 + i] = temp_table_amount[60 + j];
												temp_table_price[60 + i] = temp_table_price[60 + j];
												temp_table[60 + j] = "";
												temp_table_amount[60 + j] = 0;
												temp_table_price[60 + j] = 0;
												break;
											}
										}
									}
								}
							}
						}
						break;
					}
				}
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '7':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			if (wyb[1] == '1')
			{
				break;
			}
			if (wyb[1] == '2')
			{
				break;
			}
			if (wyb[1] == '3')
			{
				break;
			}
			if (wyb[1] == '4')
			{
				break;
			}
			if (wyb[1] == '5')
			{
				break;
			}
			if (wyb[1] == '6')
			{
				break;
			}
			if (wyb[1] == '7')
			{
				break;
			}
			if (wyb[1] == '8')
			{
				break;
			}
			if (wyb[1] == '9')
			{
				break;
			}
			break;
		}
		case '8':
		{
			if (wyb.size() == 1)
			{
				break;
			}
			if (wyb[1] == '0')
			{
				break;
			}
			break;
		}
		case 'w':
		{
			int tryb = 1;
			do
			{
				cout << "Transakcja nie zostanie zaakceptowana" << endl;
				cout << "Czy na pewno chcesz j¹ zakoñczyæ?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				cout << "Twój wybór to: ";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					return gracz;
				}
				case '2':
				{
					tryb = 0;
					break;
				}
				default:
				{
					system("cls");
				}
				}
			} while (tryb = 0);
			break;
		}
		case 'W':
		{
			int tryb = 1;
			do
			{
				cout << "Transakcja nie zostanie zaakceptowana" << endl;
				cout << "Czy na pewno chcesz j¹ zakoñczyæ?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				cout << "Twój wybór to: ";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					return gracz;
				}
				case '2':
				{
					tryb = 0;
					break;
				}
				default:
				{
					system("cls");
				}
				}
			} while (tryb = 0);
			break;
		}
		case 'n':
		{
			if(wyb[1]=='1')
			{
				if (strona_1 == 0)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[20 + i];
						temp_table_price[20 + i] = handlarz.menu_price[20 + i];
					}
					strona_1 = 1;
					break;
				}
				if (strona_1 == 1 && gracz.level > 10)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[40 + i];
						temp_table_price[20 + i] = handlarz.menu_price[40 + i];
					}
					strona_1 = 2;
					break;
				}
				if (strona_1 == 2 && gracz.level > 20)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[60 + i];
						temp_table_price[20 + i] = handlarz.menu_price[60 + i];
					}
					strona_1 = 3;
					break;
				}
			}
			if (wyb[1] == '2')
			{
				if (strona_2 == 0)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[60 + i] = gracz.inventory_crafting[i];
						temp_table_price[60 + i] = gracz.inventory_crafting_price[i];
						temp_table_amount[60 + i] = gracz.inventory_crafting_amount[i];
					}
					strona_2 = 1;
					break;
				}
			}
			break;
		}
		case 'N':
		{
			if (wyb[1] == '1')
			{
				//0 - no_level_req
				//1 - no_level_req
				//2 - 10 level
				//3 - 20 level

				//0-1
				if (strona_1 == 0)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[20 + i];
						temp_table_price[20 + i] = handlarz.menu_price[20 + i];
					}
					strona_1 = 1;
					break;
				}
				//1-2
				if (strona_1 == 1 && gracz.level > 10)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[40 + i];
						temp_table_price[20 + i] = handlarz.menu_price[40 + i];
					}
					strona_1 = 2;
					break;
				}
				//2-3
				if (strona_1 == 2 && gracz.level > 20)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[60 + i];
						temp_table_price[20 + i] = handlarz.menu_price[60 + i];
					}
					strona_1 = 3;
					break;
				}
			}
			if (wyb[1] == '2')
			{
				if (strona_2 == 0)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[60 + i] = gracz.inventory_crafting[i];
						temp_table_price[60 + i] = gracz.inventory_crafting_price[i];
						temp_table_amount[60 + i] = gracz.inventory_crafting_amount[i];
					}
					strona_2 = 1;
					break;
				}
			}
			break;
		}
		case 'p':
		{
			//0 - no_level_req
			//1 - no_level_req
			//2 - 10 level
			//3 - 20 level
			if (wyb[1] == '1')
			{
				if (strona_1 == 3 && gracz.level > 20)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[40 + i];
						temp_table_price[20 + i] = handlarz.menu_price[40 + i];
					}
					strona_1 = 2;
					break;
				}
				if (strona_1 == 2 && gracz.level > 10)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[20 + i];
						temp_table_price[20 + i] = handlarz.menu_price[20 + i];
					}
					strona_1 = 1;
					break;
				}
				if (strona_1 == 1)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[i];
						temp_table_price[20 + i] = handlarz.menu_price[i];
					}
					strona_1 = 0;
					break;
				}
			}
			if (wyb[1] == '2')
			{
				if (strona_2 == 1)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[60 + i] = gracz.inventory_usage[i];
						temp_table_price[60 + i] = gracz.inventory_usage_price[i];
						temp_table_amount[60 + i] = gracz.inventory_usage_amount[i];
					}
					strona_2 = 0;
					break;
				}
			}
		}
		case 'P':
		{
			//0 - no_level_req
			//1 - no_level_req
			//2 - 10 level
			//3 - 20 level
			if (wyb[1] == '1')
			{
				if (strona_1 == 3 && gracz.level > 20)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[40 + i];
						temp_table_price[20 + i] = handlarz.menu_price[40 + i];
					}
					strona_1 = 2;
					break;
				}
				if (strona_1 == 2 && gracz.level > 10)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[20 + i];
						temp_table_price[20 + i] = handlarz.menu_price[20 + i];
					}
					strona_1 = 1;
					break;
				}
				if (strona_1 == 1)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[20 + i] = handlarz.menu_items[i];
						temp_table_price[20 + i] = handlarz.menu_price[i];
					}
					strona_1 = 0;
					break;
				}
			}
			if (wyb[1] == '2')
			{
				if (strona_2 == 1)
				{
					for (int i = 0; i < 20; i++)
					{
						temp_table[60 + i] = gracz.inventory_usage[i];
						temp_table_price[60 + i] = gracz.inventory_usage_price[i];
						temp_table_amount[60 + i] = gracz.inventory_usage_amount[i];
					}
					strona_2 = 0;
					break;
				}
			}
		}
		case 'z':
		{
			int tryb = 1;
			do
			{
				cout << "Czy na pewno chcesz zfinalizowaæ transakcje?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				cout << "Twój wybór to:";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					if (temp_table[40] != "BRAK WYBRANYCH PRZEDMIOTÓW" || temp_table[0] != "BRAK WYBRANYCH PRZEDMIOTÓW")
					{
						cout << endl << "Transakcja zfinalizowana" << endl;
						//sprzeda¿
						{
							for (int i = 0; i < counter_player; i++)
							{
								if (gracz.find_item_usage(temp_table[40 + i]) == 1)
								{
									int index = gracz.find_usage_item_index(temp_table[40 + i]);
									gracz.gold = gracz.gold + (temp_table_price[40 + i] * temp_table_amount[40 + i]);
									if (gracz.inventory_usage_amount[index] == temp_table_amount[40 + i])
									{
										gracz.inventory_usage[index] = "";
										gracz.inventory_usage_price[index] = 0;
										gracz.inventory_usage_amount[index] = 0;
									}
									else
									{
										gracz.inventory_usage_amount[index] = gracz.inventory_usage_amount[index] - temp_table_amount[40 + i];
									}
									temp_table[40 + i] = "";
									temp_table_amount[40 + i] = 0;
									temp_table_price[40 + i] = 0;
									gracz.sort_backpack_usage();
								}
								else if (gracz.find_item_crafting(temp_table[40 + i]) == 1)
								{
									int index = gracz.find_crafting_item_index(temp_table[40 + i]);
									gracz.gold = gracz.gold + (temp_table_price[40 + i] * temp_table_amount[40 + i]);
									if (gracz.inventory_crafting_amount[index] == temp_table_amount[40 + i])
									{
										gracz.inventory_crafting[index] = "";
										gracz.inventory_crafting_amount[index] = 0;
										gracz.inventory_crafting_price[index] = 0;
									}
									else
									{
										gracz.inventory_crafting_amount[index] = gracz.inventory_crafting_amount[index] - temp_table_amount[40 + i];
									}
									temp_table[40 + i] = "";
									temp_table_amount[40 + i] = 0;
									temp_table_price[40 + i] = 0;
									gracz.sort_backpack_crafting();
								}
							}
						}
						//kupno
						{
							for (int i = 0; i < counter_seller; i++)
							{

							}
						}
					}
					else
					{
						cout << endl << "Transakcja nie zfinalizowana" << endl;
					}
					tryb = 0;
					system("PAUSE");
					break;
				}
				case '2':
				{
					cout << endl << "Transakcja nie zfinalizowana" << endl;
					tryb = 0;
					system("PAUSE");
					break;
				}
				default:
				{
					system("cls");
					break;
				}
				}
			} while (tryb = 0);
			break;
		}
		case 'Z':
		{
			break;
		}
		default:
		{
			system("cls");
		}
		}
	}
}