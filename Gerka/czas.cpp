#include "czas.h"
#include "boost_syf.h"
#include "tabelka.h"

void boost_nerf(player &gracz)
{
	if (gracz.counter_nerf_str != 0)
	{
		gracz.counter_nerf_str--;
		if (gracz.counter_nerf_str == 0)
		{
			remove_nerf_str(gracz);
		}
	}
	if (gracz.counter_boost_str != 0)
	{
		gracz.counter_boost_str--;
		if (gracz.counter_boost_str == 0)
		{
			remove_boost_str(gracz);
		}
	}
	if (gracz.counter_nerf_agility != 0)
	{
		gracz.counter_nerf_agility--;
		if (gracz.counter_nerf_agility == 0)
		{
			remove_nerf_agility(gracz);
		}
	}
	if (gracz.counter_boost_agility != 0)
	{
		gracz.counter_boost_agility--;
		if (gracz.counter_boost_agility == 0)
		{
			remove_boost_agility(gracz);
		}
	}
	if (gracz.counter_nerf_intel != 0)
	{
		gracz.counter_nerf_intel--;
		if (gracz.counter_nerf_intel == 0)
		{
			remove_nerf_intel(gracz);
		}
	}
	if (gracz.counter_boost_intel != 0)
	{
		gracz.counter_boost_intel--;
		if (gracz.counter_boost_intel == 0)
		{
			remove_boost_intel(gracz);
		}
	}
	if (gracz.counter_nerf_charisma != 0)
	{
		gracz.counter_nerf_charisma--;
		if (gracz.counter_nerf_charisma == 0)
		{
			remove_nerf_charisma(gracz);
		}
	}
	if (gracz.counter_boost_charisma != 0)
	{
		gracz.counter_boost_charisma--;
		if (gracz.counter_boost_charisma == 0)
		{
			remove_boost_charisma(gracz);
		}
	}
	if (gracz.counter_nerf_luck != 0)
	{
		gracz.counter_nerf_luck--;
		if (gracz.counter_nerf_luck == 0)
		{
			remove_nerf_luck(gracz);
		}
	}
	if (gracz.counter_boost_luck != 0)
	{
		gracz.counter_boost_luck--;
		if (gracz.counter_boost_luck == 0)
		{
			remove_boost_luck(gracz);
		}
	}
}
void hungry_and_sober(int height, int startPoint, player &gracz, int off_hunger, int off_sobering)
{
	if (gracz.hour % 2 == 0)
	{
		if (off_sobering == 0)
		{
			gracz.a_bit_sober();
		}
		if (off_hunger == 0)
		{
			gracz.a_bit_hungry(height, startPoint, 1);
		}
	}
	else
	{
		if (off_sobering == 0)
		{
			gracz.a_bit_sober();
		}
	}
}
void change_time(int height, int startPoint, player &gracz, int hours, int minutes, int off_hunger, int off_sobering)
{
	gracz.minute = gracz.minute + minutes;
	while (gracz.minute >= 60)
	{
		hours++;
		gracz.minute = gracz.minute - 60;
	}
	for (int i = 0; i < hours; i++)
	{
		gracz.hour++;
		if (gracz.hour == 24)
		{
			gracz.licznik_dnia = gracz.licznik_dnia + 1;
			gracz.hour = 0;
		}
		hungry_and_sober(height, startPoint, gracz, off_hunger, off_sobering);
		boost_nerf(gracz);
	}
}
int waitingDamage(int height, int startPoint, player gracz, int hour, int minute)
{
	int nutrition_points = 0;
	if (gracz.hour % 2 == 0 && gracz.minute != 0)
	{
		nutrition_points = (gracz.hunger * 60 * 2) + (60 - gracz.minute) - 60;
	}
	else
	{
		nutrition_points = (gracz.hunger * 60 * 2) + (60 - gracz.minute) - 120;
	}
	int wasted_calories = hour * 60 + minute;
	if (wasted_calories >= nutrition_points)
	{
		vector <string> message;
		vector <string> options;
		string temp = "You want to wait ";
		if (hour != 0)
		{
			temp += to_string(hour) + " hour";
			if (hour > 1)
			{
				temp += "s";
			}
		}
		else if (hour == 0)
		{
			temp += to_string(minute) + " minute";
			if (minute > 1)
			{
				temp += "s";
			}
		}
		else if (minute != 0)
		{
			temp += " " + to_string(minute) + " minute";
			if (minute > 1)
			{
				temp += "s";
			}
		}
		temp += ".";
		message.push_back(temp);
		message.push_back("During such a long wait you will feel hungry, do you want to continue?");
		options.push_back("Yes");
		options.push_back("No");
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		return highlight;
	}
	else
	{
		return 0;
	}
}
void wait_n_hours(int height, int startPoint, player& gracz)
{
	vector <string> message;
	vector <string> options;
	message.push_back("Do you want to wait?");
	options.push_back("Yes");
	options.push_back("No");
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	if (highlight == 0)
	{
		int maxX, maxY;
		getyx(stdscr, maxY, maxX);
		WINDOW* win = newwin(height, maxX, startPoint, 0);
		wborder(win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
		windowDrawOnCenter(win, 2, 136, "How much time do you want to wait?");
		int tempH = 0;
		int tempM = 0;
		string buttons[5] = { "<-","<-","->","->","Confirm" };
		int highlight = 0;
		int choice;
		while (1)
		{
			mvwprintw(win, 4, 69, to_string(tempH).c_str());
			mvwprintw(win, 5, 69, to_string(tempM).c_str());
			for (int i = 0; i < 5; i++)
			{
				if (i == highlight)
				{
					wattron(win, A_REVERSE);
				}
				if (i < 2)
				{
					mvwprintw(win, 4 + i, 64, buttons[i].c_str());
				}
				if (i >= 2 && i < 4)
				{
					mvwprintw(win, 2 + i, 74, buttons[i].c_str());
				}
				if (i == 4)
				{
					windowDrawOnCenter(win, 7, 137, buttons[i]);
				}
				wattroff(win, A_REVERSE);
			}
			wrefresh(win);
			keypad(win, true);
			choice = wgetch(win);
			switch (choice)
			{
			case KEY_UP:
			{
				if (highlight == 4 || highlight == 1 || highlight == 3)
				{
					highlight--;
				}
				break;
			}
			case KEY_DOWN:
			{
				if (highlight == 1 || highlight == 3)
				{
					highlight = 4;
				}
				else if (highlight == 0 || highlight == 2)
				{
					highlight++;
				}
				break;
			}
			case KEY_LEFT:
			{
				if (highlight == 2 || highlight == 3)
				{
					highlight -= 2;
				}
				break;
			}
			case KEY_RIGHT:
			{
				if (highlight == 0 || highlight == 1)
				{
					highlight += 2;
				}
				break;
			}
			default:
			{
				break;
			}
			}
			if (choice == 10)
			{
				if (highlight == 4)
				{
					break;
				}
				else if (highlight == 0 && tempH != 0)
				{
					tempH--;
				}
				if (highlight == 1 && tempM != 0)
				{
					tempM--;
				}
				if (highlight == 2 && tempH < 23)
				{
					tempH++;
				}
				if (highlight == 3 && tempM < 59)
				{
					tempM++;
				}
			}
		}
		highlight = waitingDamage(height, startPoint, gracz, tempH, tempM);
		if (highlight == 0)
		{
			change_time(height, startPoint, gracz, tempH, tempM);
		}
	}
}