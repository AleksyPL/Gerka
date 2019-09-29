#include "wait.h"
#include "czas.h"

player wait_n_hours(player &gracz, int hour, int minute)
{
	while (1)
	{
		cout << "Czy chcesz zaczekaæ?" << endl;
		cout << "1. Tak" << endl;
		cout << "2. Nie" << endl;
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			if (gracz.hunger < 5)
			{
				cout << "Jesteœ zbyt g³ody by zasn¹æ" << endl;
				return gracz;
			}
			else
			{
				int h;
				int min;
				cout << "Ile czasu chcesz czekaæ?" << endl;
				cout << "Ile godzin: ";
				cin >> h;
				while (cin.fail() || h < 0 || h>23)
				{
					cout << "Ile godzin: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> h;
				}
				cout << "Ile minut: ";
				cin >> min;
				while (cin.fail() || min < 0 || min>59)
				{
					cout << "Ile minut: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> min;
				}
				if (hour != 0 || minute != 0)
				{
					int pomoc = hour - gracz.hour;
					int pomoc2 = minute - gracz.minute;
					change_time(gracz, pomoc,pomoc2);
				}
				else
				{
					change_time(gracz, h, min);
				}
			}
			return gracz;
			break;
		}
		case '2':
		{
			return gracz;
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}
