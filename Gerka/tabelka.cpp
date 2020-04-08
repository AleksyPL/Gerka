#include "tabelka.h"

string return_progress_bar(int min, int max, int how_long)
{
	string temp = "[";
	int pos = how_long * min / max;
	for (int i = 0; i < how_long; ++i) {
		if (i < pos)
		{
			temp += "#";
		}
		else
		{
			temp += " ";
		}
	}
	temp += "]";
	return temp;
}
int tab(player gracz, int &highlight, string local, string shorty[20], string menu[20], __int64 ceny[20])
{
	int context_menu_border = 0;
	int go_to_places_border = 0;
	{
		for (int i = 0; i < 20; i++)
		{
			if (shorty[i] != "")
			{
				context_menu_border++;
			}
			if (menu[i] != "")
			{
				go_to_places_border++;
			}
		}
	}
	string citymap[18];
	citymap[0] = "Town square";
	citymap[1] = "Tavern";
	citymap[2] = "Forge";
	citymap[3] = "Bladesmith Shop";
	citymap[4] = "Alchemist lab";
	citymap[5] = "Brothel";
	citymap[6] = "General store";
	citymap[7] = "Shaman's house";
	citymap[8] = "Hospital";
	citymap[9] = "";
	citymap[10] = "";
	citymap[11] = "";
	citymap[12] = "";
	citymap[13] = "";
	citymap[14] = "";
	citymap[15] = "";
	citymap[16] = "";
	citymap[17] = "";
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW * win = newwin(maxY, maxX, 0, 0);
	WINDOW * topbar = newwin(3, maxX, 0, 0);
	WINDOW * bars = newwin(9,93,2,46);
	WINDOW * stats = newwin(9, 47, 2, 0);
	WINDOW * map = newwin(22, 47, 10, 0);
	WINDOW * contextmenu = newwin(22, 93, 10, 46);
	WINDOW * shortcuts = newwin(22, 24, 10, 23);
	int choice;
	keypad(win, true);
	while (1)
	{
		box(win, 0, 0);
		//stats
		{
			wborder(stats, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_LRCORNER);
			mvwprintw(stats, 1, 2, "Character name:");
			mvwprintw(stats, 1, 25, gracz.nazwa.c_str());
			mvwprintw(stats, 2, 2, "Level:");
			mvwprintw(stats, 2, 25, to_string(gracz.level).c_str());
			mvwprintw(stats, 3, 2, "Alias:");
			mvwprintw(stats, 3, 25, gracz.pseudonym.c_str());
			mvwprintw(stats, 4, 2, "Health points:");
			string temp = to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
			mvwprintw(stats, 4, 25, temp.c_str());
			mvwprintw(stats, 5, 2, "Experience points:");
			temp = to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level);
			mvwprintw(stats, 5, 25, temp.c_str());
			mvwprintw(stats, 6, 2, "Nutrition points:");
			temp = to_string(gracz.hunger) + "/10";
			mvwprintw(stats, 6, 25, temp.c_str());
			mvwprintw(stats, 7, 2, "Drunk level:");
			temp = to_string(gracz.alko) + "/10";
			mvwprintw(stats, 7, 25, temp.c_str());
		}
		//bars
		{
			wborder(bars, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_PLUS, ACS_RTEE);
			start_color();
			init_pair(1, COLOR_RED, COLOR_BLACK);
			init_pair(2, COLOR_YELLOW, COLOR_BLACK);
			init_pair(3, COLOR_GREEN, COLOR_BLACK);
			init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
			string temp = return_progress_bar(gracz.hp, gracz.max_hp, 89);
			wattron(bars, COLOR_PAIR(1));
			mvwprintw(bars, 4, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(1));
			temp = return_progress_bar(gracz.exp, gracz.exp_to_next_level, 89);
			wattron(bars, COLOR_PAIR(2));
			mvwprintw(bars, 5, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(2));
			temp = return_progress_bar(gracz.hunger, 10, 89);
			wattron(bars, COLOR_PAIR(3));
			mvwprintw(bars, 6, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(3));
			temp = return_progress_bar(gracz.alko, 10, 89);
			wattron(bars, COLOR_PAIR(4));
			mvwprintw(bars, 7, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(4));
		}
		//topbar
		{
			wborder(topbar, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
			mvwaddch(topbar, 0, 46, ACS_TTEE);
			mvwaddch(topbar, 1, 46, ACS_VLINE);
			mvwaddch(topbar, 2, 46, ACS_PLUS);
			windowDrawOnCenter(topbar, 1, 44, "Character Statistics");
			mvwaddch(topbar, 0, 92, ACS_TTEE);
			mvwaddch(topbar, 1, 92, ACS_VLINE);
			mvwaddch(topbar, 2, 92, ACS_BTEE);
			{
				string temp = "Day " + to_string(gracz.licznik_dnia) + " - ";
				if (gracz.hour < 10)
				{
					temp += "0" + to_string(gracz.hour);
				}
				else
				{
					temp += to_string(gracz.hour);
				}
				temp += ":";
				if (gracz.minute < 10)
				{
					temp += "0" + to_string(gracz.minute);
				}
				else
				{
					temp += to_string(gracz.minute);
				}
				windowDrawOnCenter(topbar, 1, 44, temp.c_str(),47);
			}
			{
				string temp = "Gold: " + to_string(gracz.gold);
				windowDrawOnCenter(topbar, 1, 44, temp.c_str(), 93);
			}
		}
		//map
		{
			wborder(map, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_BTEE);
			windowDrawOnCenter(map, 1, 22, "City Map");
			mvwaddch(map, 2, 0, ACS_LTEE);
			for (int i = 0; i < 22; i++)
			{
				mvwaddch(map, 2, i + 1, ACS_HLINE);
			}
			for (int i = 0; i < 18; i++)
			{
				if (local == citymap[i])
				{
					wattron(map, A_REVERSE);
				}
				mvwprintw(map,i+3,2,citymap[i].c_str());
				wattroff(map, A_REVERSE);
			}
		}
		wborder(shortcuts, 0, 0, 0, 0, ACS_TTEE, ACS_PLUS, ACS_BTEE, ACS_BTEE);
		wborder(contextmenu, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_BTEE, ACS_RTEE);
		mvwaddch(shortcuts, 2, 0, ACS_RTEE);
		for (int i = 0; i < 20; i++)
		{
			if (i == highlight && highlight <20)
			{
				wattron(shortcuts, A_REVERSE);
			}
			else if (i == (highlight - 20) && highlight >= 20)
			{
				wattron(contextmenu, A_REVERSE);
			}
			mvwprintw(shortcuts, i + 1, 2, shorty[i].c_str());
			if(ceny[i]==0)
			{
				string temp = menu[i];
				int loop_max = 89 - temp.size();
				for (int i = 0; i < loop_max; i++)
				{
					temp += " ";
				}
				mvwprintw(contextmenu, i + 1, 2, temp.c_str());
			}
			else
			{
				string temp = menu[i];
				string temp2 = "[" + to_string(ceny[i]) + " GOLD]";
				int loop_max = 89 - temp.size() - temp2.size();
				for (int i = 0; i < loop_max; i++)
				{
					temp += " ";
				}
				temp += temp2;
				mvwprintw(contextmenu, i + 1, 2, temp.c_str());
			}
			
			wattroff(shortcuts, A_REVERSE);
			wattroff(contextmenu, A_REVERSE);
		}
		wrefresh(win);
		wrefresh(stats);
		wrefresh(bars);
		wrefresh(topbar);
		wrefresh(map);
		wrefresh(shortcuts);
		wrefresh(contextmenu);
		choice = wgetch(win);
		switch (choice)
		{
		case KEY_UP:
		{
			highlight--;
			if (highlight < 20 && highlight > context_menu_border)
			{
				highlight = context_menu_border - 1;
			}
			if (highlight < 0)
			{
				highlight = 0;
			}
			break;
		}
		case KEY_DOWN:
		{
			highlight++;
			if (highlight < 20 && highlight > context_menu_border - 1)
			{
				highlight = 20;
			}
			if (highlight >= 20 && highlight == 20 + go_to_places_border)
			{
				highlight = 20 + go_to_places_border - 1;
			}
			break;
		}
		case KEY_LEFT:
		{
			highlight -= 20;
			if (highlight<20 && highlight>=context_menu_border)
			{
				highlight = context_menu_border - 1;
			}
			if (highlight < 0)
			{
				highlight +=20;
			}
			break;
		}
		case KEY_RIGHT:
		{
			highlight += 20;
			if (highlight >= 20 && highlight >= (20 + go_to_places_border))
			{
				highlight = 20 + go_to_places_border - 1;
			}
			if (highlight > 40)
			{
				highlight -= 20;
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
			return 0;
		}
	}
}
int tabItemsLeftOnly(int highlight, string top_side, string left_side[21], string right_side[21], vector <string> bottom_side)
{
	int leftSideBorder = 0;
	int rightSideBorder = 0;
	for (int i = 0; i < 20; i++)
	{
		if (left_side[i] != "")
		{
			leftSideBorder++;
		}
		if (right_side[i] != "")
		{
			rightSideBorder++;
		}
	}
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	WINDOW* topbar = newwin(5, maxX, 0, 0);
	WINDOW* eq = newwin(22, 70, 4, 0);
	WINDOW* stats = newwin(22, 70, 4, 69);
	WINDOW* bottombar = newwin(3, maxX, 25, 0);
	int choice;
	keypad(win, true);
	while (1)
	{
		box(win, 0, 0);
		//topbar
		{
			wborder(topbar, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
			windowDrawOnCenter(topbar, 1, 136, top_side);
			for (int i = 1; i < 138; i++)
			{
				mvwaddch(topbar, 2, i, ACS_HLINE);
			}
			mvwaddch(topbar, 2, 0, ACS_LTEE);
			mvwaddch(topbar, 2, 138, ACS_RTEE);
			mvwaddch(topbar, 2, 69, ACS_TTEE);
			mvwaddch(topbar, 3, 69, ACS_VLINE);
			mvwaddch(topbar, 4, 69, ACS_BTEE);
			windowDrawOnCenter(topbar, 3, 67, left_side[20]);
			windowDrawOnCenter(topbar, 3, 67, right_side[20], 70);
		}
		//equipment
		{
			wborder(eq, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_BTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight == i && highlight < 20)
				{
					wattron(eq, A_REVERSE);
				}
				windowDrawOnCenter(eq, i + 1, 68, left_side[i]);
				wattroff(eq, A_REVERSE);
			}
		}
		//stats
		{
			wborder(stats, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_BTEE, ACS_RTEE);
			for (int i = 0; i < 20; i++)
			{
				windowDrawOnCenter(stats, i + 1, 68, right_side[i]);
			}
		}
		//bottombar
		{
			if (bottom_side.size()==3)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				for (int i = 0; i < 3; i++)
				{
					if (highlight >= 20 && highlight - 20 == i)
					{
						wattron(bottombar, A_REVERSE);
					}
					windowDrawOnCenter(bottombar, 1, 45, bottom_side[i], (i*46)+1);
					wattroff(bottombar, A_REVERSE);
				}
			}
			else if (bottom_side.size() == 5)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 23, ACS_TTEE);
				mvwaddch(bottombar, 1, 23, ACS_VLINE);
				mvwaddch(bottombar, 2, 23, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				mvwaddch(bottombar, 0, 115, ACS_TTEE);
				mvwaddch(bottombar, 1, 115, ACS_VLINE);
				mvwaddch(bottombar, 2, 115, ACS_BTEE);
				for (int i = 0; i < 5; i++)
				{
					if (highlight >= 20 && highlight - 20 == i)
					{
						wattron(bottombar, A_REVERSE);
					}
					if (i == 0)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[0]);
					}
					else if (i == 1)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[1], 24);
					}
					else if (i == 2)
					{
						windowDrawOnCenter(bottombar, 1, 45, bottom_side[2], 47);
					}
					else if (i == 3)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[3], 93);
					}
					else
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[4], 116);
					}
					wattroff(bottombar, A_REVERSE);
				}
			}
		}
		wrefresh(win);
		wrefresh(topbar);
		wrefresh(eq);
		wrefresh(stats);
		wrefresh(bottombar);
		choice = wgetch(win);
		switch (choice)
		{
		case KEY_UP:
		{
			if (highlight == 20 || highlight == 21)
			{
				highlight = leftSideBorder -1;
			}
			else if (highlight < 20)
			{
				highlight--;
			}
			if (highlight < 0)
			{
				highlight = 0;
			}
			break;
		}
		case KEY_DOWN:
		{
			if (highlight < 20)
			{
				highlight++;
				if (highlight < 20 && highlight > leftSideBorder - 1)
				{
					highlight = 20;
				}
			}
			break;
		}
		case KEY_LEFT:
		{
			if (highlight >= 20 && highlight < 25)
			{
				highlight--;
				if (highlight < 20)
				{
					highlight = 20;
				}
			}
			break;
		}
		case KEY_RIGHT:
		{
			if (highlight >= 20 && highlight < 25)
			{
				highlight++;
				if (highlight >= 25)
				{
					highlight = 24;
				}
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
			return highlight;
		}

	}
}
int tabItemsLeftAndRight(int highlight, string top_side, string left_side[21], string right_side[21], vector <string> bottom_side)
{
	int leftSideBorder = 19;
	int rightSideBorder = 19;
	for (int i = 0; i < 20; i++)
	{
		if (left_side[i] == "")
		{
			leftSideBorder--;
		}
		if (right_side[i] == "")
		{
			rightSideBorder--;
		}
	}
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	WINDOW* topbar = newwin(5, maxX, 0, 0);
	WINDOW* eq = newwin(22, 70, 4, 0);
	WINDOW* stats = newwin(22, 70, 4, 69);
	WINDOW* bottombar = newwin(3, maxX, 25, 0);
	int choice;
	keypad(win, true);
	while (1)
	{
		box(win, 0, 0);
		//topbar
		{
			wborder(topbar, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
			windowDrawOnCenter(topbar, 1, 136, top_side);
			for (int i = 1; i < 138; i++)
			{
				mvwaddch(topbar, 2, i, ACS_HLINE);
			}
			mvwaddch(topbar, 2, 0, ACS_LTEE);
			mvwaddch(topbar, 2, 138, ACS_RTEE);
			mvwaddch(topbar, 2, 69, ACS_TTEE);
			mvwaddch(topbar, 3, 69, ACS_VLINE);
			mvwaddch(topbar, 4, 69, ACS_BTEE);
			windowDrawOnCenter(topbar, 3, 67, left_side[20]);
			windowDrawOnCenter(topbar, 3, 67, right_side[20], 70);
		}
		//Left
		{
			wborder(eq, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_BTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight == i && highlight < 20)
				{
					wattron(eq, A_REVERSE);
				}
				windowDrawOnCenter(eq, i + 1, 68, left_side[i]);
				wattroff(eq, A_REVERSE);
			}
		}
		//Right
		{
			wborder(stats, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_BTEE, ACS_RTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight - 20 == i && highlight >= 20 && highlight < 40)
				{
					wattron(stats, A_REVERSE);
				}
				windowDrawOnCenter(stats, i + 1, 68, right_side[i]);
				wattroff(stats, A_REVERSE);
			}
		}
		//bottombar
		{
			if (bottom_side.size() == 3)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				for (int i = 0; i < 3; i++)
				{
					if (highlight >= 40 && highlight - 40 == i)
					{
						wattron(bottombar, A_REVERSE);
					}
					windowDrawOnCenter(bottombar, 1, 45, bottom_side[i], (i * 46) + 1);
					wattroff(bottombar, A_REVERSE);
				}
			}
			else if (bottom_side.size() == 5)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 23, ACS_TTEE);
				mvwaddch(bottombar, 1, 23, ACS_VLINE);
				mvwaddch(bottombar, 2, 23, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				mvwaddch(bottombar, 0, 115, ACS_TTEE);
				mvwaddch(bottombar, 1, 115, ACS_VLINE);
				mvwaddch(bottombar, 2, 115, ACS_BTEE);
				for (int i = 0; i < 5; i++)
				{
					if (highlight >= 40 && highlight - 40 == i)
					{
						wattron(bottombar, A_REVERSE);
					}
					if (i == 0)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[0]);
					}
					else if (i == 1)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[1], 24);
					}
					else if (i == 2)
					{
						windowDrawOnCenter(bottombar, 1, 45, bottom_side[2], 47);
					}
					else if (i == 3)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[3], 93);
					}
					else
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[4], 116);
					}
					wattroff(bottombar, A_REVERSE);
				}
			}
		}
		wrefresh(win);
		wrefresh(topbar);
		wrefresh(eq);
		wrefresh(stats);
		wrefresh(bottombar);
		choice = wgetch(win);
		switch (choice)
		{
			if (bottom_side.size() == 3)
			{
			case KEY_UP:
			{
				if (highlight > 0 && highlight < 20 && highlight <= leftSideBorder)
				{
					highlight--;
				}
				else if (highlight > 20 && highlight < 40 && highlight <= 20 + rightSideBorder)
				{
					highlight--;
				}
				else if (highlight == 40)
				{
					highlight = leftSideBorder;
				}
				else if (highlight == 42)
				{
					highlight = 20 + rightSideBorder;
				}
				break;
			}
			case KEY_DOWN:
			{
				if (highlight < 20 && highlight < leftSideBorder)
				{
					highlight++;
				}
				else if (highlight >= 20 && highlight < 40 && highlight < 20 + rightSideBorder)
				{
					highlight++;
				}
				else if (highlight < 20 && highlight == leftSideBorder)
				{
					highlight = 40;
				}
				else if (highlight >= 20 && highlight < 40 && highlight == 20 + rightSideBorder)
				{
					highlight = 42;
				}

				break;
			}
			case KEY_LEFT:
			{
				if (highlight >= 20 && highlight < 40)
				{
					highlight -= 20;
					if (highlight > leftSideBorder)
					{
						highlight = leftSideBorder;
					}
				}
				else if (highlight > 40)
				{
					highlight--;
				}
				break;
			}
			case KEY_RIGHT:
			{
				if (highlight < 20)
				{
					highlight += 20;
					if (highlight >= 20 + rightSideBorder)
					{
						highlight = 20 + rightSideBorder;
					}
				}
				else if (highlight >= 40 && highlight < 42)
				{
					highlight++;
				}
				break;
			}
			default:
			{
				break;
			}
			}
		}
		if (choice == 10)
		{
			return highlight;
		}

	}
}
void tabSubmenuTextOnly(int height, int startPoint, vector<string> myDisplay)
{
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(height, maxX, startPoint, 0);
	wborder(win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
	if (myDisplay.size() >= (height - 4))
	{
		myDisplay.resize(height - 4);
	}
	for (int i = 0; i < myDisplay.size(); i++)
	{
		mvwprintw(win, i + 1, 2, myDisplay[i].c_str());
	}
	windowDrawOnCenter(win, height - 2, 136, "Press any key to continue...");
	wrefresh(win);
	getch();
}
void tabSubmenuFancyTextOnly(int height, int startPoint, vector<string> myDisplay, int delay)
{
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(height, maxX, startPoint, 0);
	wborder(win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
	if (myDisplay.size() >= (height - 4))
	{
		myDisplay.resize(height - 4);
	}
	for (int i = 0; i < myDisplay.size(); i++)
	{
		for (int j = 0; j < myDisplay[i].length(); j++)
		{
			char temp = (char)(myDisplay[i])[j];
			mvwprintw(win, i + 1, 2 + j, "%c", temp);
			wrefresh(win);
			Sleep(delay);
		}
	}
	windowDrawOnCenter(win, height - 2, 136, "Press any key to continue...");
	wrefresh(win);
	getch();
}
int tabSubmenuOneColumnChoice(int height, int startPoint, vector<string> message, vector<string> options)
{
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(height, maxX, startPoint, 0);
	wborder(win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
	int highlight = 0;
	int choice;
	int lineHelper = message.size() + 2;
	keypad(win, true);
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i].empty())
		{
			options.erase(options.begin()+i);
			i--;
		}
	}
	if (message.size() + options.size() + 1 > height)
	{
		options.resize(height - message.size() - 3);
	}
	while (1)
	{
		for (int i = 0; i < message.size(); i++)
		{
			mvwprintw(win, i + 1, 2, message[i].c_str());
		}
		for (int i = 0; i < options.size(); i++)
		{
			if (highlight == i)
			{
				wattron(win, A_REVERSE);
			}
			mvwprintw(win, lineHelper + i, 2, options[i].c_str());
			wattroff(win, A_REVERSE);
		}
		wrefresh(win);
		choice = wgetch(win);
		switch (choice)
		{
		case KEY_UP:
		{
			highlight--;
			if (highlight < 0)
			{
				highlight = 0;
			}
			break;
		}
		case KEY_DOWN:
		{
			highlight++;
			if (highlight > options.size() - 1)
			{
				highlight = options.size() - 1;
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
			return highlight;
		}
	}
	
}
int tabTrade(int highlight, string top_side[3], string left_side[21], string right_side[21], vector <string> bottom_side)
{
	int leftSideBorder = 19;
	int rightSideBorder = 19;
	for (int i = 0; i < 20; i++)
	{
		if (left_side[i] == "")
		{
			leftSideBorder--;
		}
		if (right_side[i] == "")
		{
			rightSideBorder--;
		}
	}
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	WINDOW* topbar = newwin(5, maxX, 0, 0);
	WINDOW* eq = newwin(22, 70, 4, 0);
	WINDOW* stats = newwin(22, 70, 4, 69);
	WINDOW* bottombar = newwin(3, maxX, 25, 0);
	int choice;
	keypad(win, true);
	while (1)
	{
		box(win, 0, 0);
		//topbar
		{
			wborder(topbar, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
			for (int i = 1; i < 138; i++)
			{
				mvwaddch(topbar, 2, i, ACS_HLINE);
			}
			windowDrawOnCenter(topbar, 1, 45, top_side[0], 1);
			windowDrawOnCenter(topbar, 1, 45, top_side[1], 47);
			windowDrawOnCenter(topbar, 1, 45, top_side[2], 93);
			mvwaddch(topbar, 0, 46, ACS_TTEE);
			mvwaddch(topbar, 1, 46, ACS_VLINE);
			mvwaddch(topbar, 2, 46, ACS_BTEE);
			mvwaddch(topbar, 0, 92, ACS_TTEE);
			mvwaddch(topbar, 1, 92, ACS_VLINE);
			mvwaddch(topbar, 2, 92, ACS_BTEE);
			mvwaddch(topbar, 2, 0, ACS_LTEE);
			mvwaddch(topbar, 2, 138, ACS_RTEE);
			mvwaddch(topbar, 2, 69, ACS_TTEE);
			mvwaddch(topbar, 3, 69, ACS_VLINE);
			mvwaddch(topbar, 4, 69, ACS_BTEE);
			windowDrawOnCenter(topbar, 3, 67, left_side[20]);
			windowDrawOnCenter(topbar, 3, 67, right_side[20], 70);
		}
		//Left
		{
			wborder(eq, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_BTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight == i && highlight < 20)
				{
					wattron(eq, A_REVERSE);
				}
				windowDrawOnCenter(eq, i + 1, 68, left_side[i]);
				wattroff(eq, A_REVERSE);
			}
		}
		//Right
		{
			wborder(stats, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_BTEE, ACS_RTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight - 20 == i && highlight >= 20 && highlight < 40)
				{
					wattron(stats, A_REVERSE);
				}
				windowDrawOnCenter(stats, i + 1, 68, right_side[i]);
				wattroff(stats, A_REVERSE);
			}
		}
		//bottombar
		{
			if (bottom_side.size() == 1)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				if (highlight >= 40 && highlight - 40 == 0)
				{
					wattron(bottombar, A_REVERSE);
				}
				windowDrawOnCenter(bottombar, 1, 45, bottom_side[0], 47);
				wattroff(bottombar, A_REVERSE);
			}
			if (bottom_side.size() == 3)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				for (int i = 0; i < 3; i++)
				{
					if (highlight >= 40 && highlight - 40 == i)
					{
						wattron(bottombar, A_REVERSE);
					}
					windowDrawOnCenter(bottombar, 1, 45, bottom_side[i], (i * 46) + 1);
					wattroff(bottombar, A_REVERSE);
				}
			}
			else if (bottom_side.size() == 5)
			{
				wborder(bottombar, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_RTEE);
				mvwaddch(bottombar, 0, 69, ACS_BTEE);
				mvwaddch(bottombar, 0, 23, ACS_TTEE);
				mvwaddch(bottombar, 1, 23, ACS_VLINE);
				mvwaddch(bottombar, 2, 23, ACS_BTEE);
				mvwaddch(bottombar, 0, 46, ACS_TTEE);
				mvwaddch(bottombar, 1, 46, ACS_VLINE);
				mvwaddch(bottombar, 2, 46, ACS_BTEE);
				mvwaddch(bottombar, 0, 92, ACS_TTEE);
				mvwaddch(bottombar, 1, 92, ACS_VLINE);
				mvwaddch(bottombar, 2, 92, ACS_BTEE);
				mvwaddch(bottombar, 0, 115, ACS_TTEE);
				mvwaddch(bottombar, 1, 115, ACS_VLINE);
				mvwaddch(bottombar, 2, 115, ACS_BTEE);
				for (int i = 0; i < 5; i++)
				{
					if (highlight >= 40 && highlight - 40 == i)
					{
						wattron(bottombar, A_REVERSE);
					}
					if (i == 0)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[0]);
					}
					else if (i == 1)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[1], 24);
					}
					else if (i == 2)
					{
						windowDrawOnCenter(bottombar, 1, 45, bottom_side[2], 47);
					}
					else if (i == 3)
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[3], 93);
					}
					else
					{
						windowDrawOnCenter(bottombar, 1, 22, bottom_side[4], 116);
					}
					wattroff(bottombar, A_REVERSE);
				}
			}
		}
		wrefresh(win);
		wrefresh(topbar);
		wrefresh(eq);
		wrefresh(stats);
		wrefresh(bottombar);
		choice = wgetch(win);
		switch (choice)
		{
		case KEY_UP:
		{
			if (highlight > 0 && highlight < 20 && highlight <= leftSideBorder)
			{
				highlight--;
			}
			else if (highlight > 20 && highlight < 40 && highlight <= 20 + rightSideBorder)
			{
				highlight--;
			}
			else if (highlight == 40 || highlight == 41)
			{
				highlight = leftSideBorder;
			}
			else if (highlight == 43 || highlight == 44)
			{
				highlight = 20 + rightSideBorder;
			}
			break;
		}
		case KEY_DOWN:
		{
			if (highlight < 20 && highlight < leftSideBorder)
			{
				highlight++;
			}
			else if (highlight >= 20 && highlight < 40 && highlight < 20 + rightSideBorder)
			{
				highlight++;
			}
			else if (highlight < 20 && highlight == leftSideBorder)
			{
				highlight = 40;
			}
			else if (highlight >= 20 && highlight < 40 && highlight == 20 + rightSideBorder)
			{
				highlight = 43;
			}
			break;
		}
		case KEY_LEFT:
		{
			if (highlight >= 20 && highlight < 40)
			{
				highlight -= 20;
				if (highlight > leftSideBorder)
				{
					highlight = leftSideBorder;
				}
			}
			else if (highlight > 40)
			{
				highlight--;
			}
			break;
		}
		case KEY_RIGHT:
		{
			if (highlight < 20)
			{
				highlight += 20;
				if (highlight >= 20 + rightSideBorder)
				{
					highlight = 20 + rightSideBorder;
				}
			}
			else if (highlight >= 40 && highlight < 45)
			{
				highlight++;
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
			return highlight;
		}
	}
}
string tabSubmenuInputField(int height, int startPoint, string message)
{
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(height, maxX, startPoint, 0);
	wborder(win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(win, 1, 2, message.c_str());
	echo();
	char s[136];
	wgetstr(win, s);
	noecho();
	string temp = s;
	return temp;
}
int tabDungeon(player gracz, bool &mode, string local, string shorty[20], char tab[32][114], vector <char> levelMonstersSymbols)
{
	int shortyBorder = 19;
	{
		for (int i = 0; i < 20; i++)
		{
			if (shorty[i] == "")
			{
				shortyBorder--;
			}
		}
	}
	string citymap[10];
	for (int i = 0; i < 10; i++)
	{
		citymap[i] = "Level " + to_string(i+1);
	}
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	WINDOW* topbar = newwin(3, maxX, 0, 0);
	WINDOW* bars = newwin(9, 93, 2, 46);
	WINDOW* stats = newwin(9, 47, 2, 0);
	WINDOW* map = newwin(13, 24, 10, 0);
	WINDOW* shortcuts = newwin(22, 24, 22, 0);
	WINDOW* display = newwin(34, 116, 10, 23);
	int highlight = 0;
	int choice;
	keypad(win, true);
	while (1)
	{
		box(win, 0, 0);
		//stats
		{
			wborder(stats, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_LRCORNER);
			mvwprintw(stats, 1, 2, "Character name:");
			mvwprintw(stats, 1, 25, gracz.nazwa.c_str());
			mvwprintw(stats, 2, 2, "Level:");
			mvwprintw(stats, 2, 25, to_string(gracz.level).c_str());
			mvwprintw(stats, 3, 2, "Alias:");
			mvwprintw(stats, 3, 25, gracz.pseudonym.c_str());
			mvwprintw(stats, 4, 2, "Health points:");
			string temp = to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
			mvwprintw(stats, 4, 25, temp.c_str());
			mvwprintw(stats, 5, 2, "Experience points:");
			temp = to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level);
			mvwprintw(stats, 5, 25, temp.c_str());
			mvwprintw(stats, 6, 2, "Nutrition points:");
			temp = to_string(gracz.hunger) + "/10";
			mvwprintw(stats, 6, 25, temp.c_str());
			mvwprintw(stats, 7, 2, "Drunk level:");
			temp = to_string(gracz.alko) + "/10";
			mvwprintw(stats, 7, 25, temp.c_str());
		}
		//bars
		{
			wborder(bars, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_BTEE, ACS_RTEE);
			start_color();
			init_pair(1, COLOR_RED, COLOR_BLACK);
			init_pair(2, COLOR_YELLOW, COLOR_BLACK);
			init_pair(3, COLOR_GREEN, COLOR_BLACK);
			init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
			string temp = return_progress_bar(gracz.hp, gracz.max_hp, 89);
			wattron(bars, COLOR_PAIR(1));
			mvwprintw(bars, 4, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(1));
			temp = return_progress_bar(gracz.exp, gracz.exp_to_next_level, 89);
			wattron(bars, COLOR_PAIR(2));
			mvwprintw(bars, 5, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(2));
			temp = return_progress_bar(gracz.hunger, 10, 89);
			wattron(bars, COLOR_PAIR(3));
			mvwprintw(bars, 6, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(3));
			temp = return_progress_bar(gracz.alko, 10, 89);
			wattron(bars, COLOR_PAIR(4));
			mvwprintw(bars, 7, 1, temp.c_str());
			wattroff(bars, COLOR_PAIR(4));
		}
		//topbar
		{
			wborder(topbar, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
			mvwaddch(topbar, 0, 46, ACS_TTEE);
			mvwaddch(topbar, 1, 46, ACS_VLINE);
			mvwaddch(topbar, 2, 46, ACS_PLUS);
			windowDrawOnCenter(topbar, 1, 44, "Character Statistics");
			mvwaddch(topbar, 0, 92, ACS_TTEE);
			mvwaddch(topbar, 1, 92, ACS_VLINE);
			mvwaddch(topbar, 2, 92, ACS_BTEE);
			{
				string temp = "Day " + to_string(gracz.licznik_dnia) + " - ";
				if (gracz.hour < 10)
				{
					temp += "0" + to_string(gracz.hour);
				}
				else
				{
					temp += to_string(gracz.hour);
				}
				temp += ":";
				if (gracz.minute < 10)
				{
					temp += "0" + to_string(gracz.minute);
				}
				else
				{
					temp += to_string(gracz.minute);
				}
				windowDrawOnCenter(topbar, 1, 44, temp.c_str(), 47);
			}
			{
				string temp = "Gold: " + to_string(gracz.gold);
				windowDrawOnCenter(topbar, 1, 44, temp.c_str(), 93);
			}
		}
		//map
		{
			wborder(map, 0, 0, 0, 0, ACS_LTEE, ACS_TTEE, ACS_LTEE, ACS_RTEE);
			windowDrawOnCenter(map, 1, 22, "Dungeon");
			mvwaddch(map, 2, 0, ACS_LTEE);
			for (int i = 0; i < 22; i++)
			{
				mvwaddch(map, 2, i + 1, ACS_HLINE);
			}
			mvwaddch(map, 2, 23, ACS_RTEE);
			for (int i = 0; i < 10; i++)
			{
				if (local == citymap[i])
				{
					wattron(map, A_REVERSE);
				}
				mvwprintw(map, i + 3, 2, citymap[i].c_str());
				wattroff(map, A_REVERSE);
			}
		}
		//options
		{
			wborder(shortcuts, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LTEE, ACS_LRCORNER);
			for (int i = 0; i < shortyBorder; i++)
			{
				if (mode == true && highlight == i)
				{
					wattron(shortcuts, A_REVERSE);
				}
				mvwprintw(shortcuts, i + 1, 2, shorty[i].c_str());
				wattroff(shortcuts, A_REVERSE);
			}
		}
		//display
		{
			wborder(display, 0, 0, 0, 0, ACS_TTEE, ACS_RTEE, ACS_BTEE, ACS_RTEE);
			mvwaddch(display, 0, 23, ACS_BTEE);
			mvwaddch(display, 2, 0, ACS_RTEE);
			mvwaddch(display, 12, 0, ACS_RTEE);
			for (int i = 0; i < 32; i++)
			{
				for (int j = 0; j < sizeof(tab[i]); j++)
				{
					char temp = (char)tab[i][j];
					if (std::find(levelMonstersSymbols.begin(), levelMonstersSymbols.end(), temp) != levelMonstersSymbols.end())
					{
						wattron(display, COLOR_PAIR(1));
						mvwprintw(display, i + 1, j + 1, "%c", temp);
						wattroff(display, COLOR_PAIR(1));
					}
					else
					{
						switch (temp)
						{
						case '1':
						{
							mvwaddch(display, i + 1, j + 1, ACS_ULCORNER);
							break;
						}
						case '2':
						{
							mvwaddch(display, i + 1, j + 1, ACS_URCORNER);
							break;
						}
						case '3':
						{
							mvwaddch(display, i + 1, j + 1, ACS_LLCORNER);
							break;
						}
						case '4':
						{
							mvwaddch(display, i + 1, j + 1, ACS_LRCORNER);
							break;
						}
						case '5':
						{
							if (j == 0)
							{
								mvwaddch(display, i + 1, j, ACS_LTEE);
								mvwaddch(display, i + 1, j + 1, ACS_HLINE);
							}
							else
							{
								mvwaddch(display, i + 1, j + 1, ACS_LTEE);
							}
							break;
						}
						case '6':
						{
							if (j == sizeof(tab[i]))
							{
								mvwaddch(display, i + 1, j + 2, ACS_TTEE);
								mvwaddch(display, i + 1, j + 1, ACS_HLINE);
							}
							else
							{
								mvwaddch(display, i + 1, j + 1, ACS_RTEE);
							}
							break;
						}
						case '7':
						{
							if (i == 0)
							{
								mvwaddch(display, i, j + 1, ACS_TTEE);
								mvwaddch(display, i + 1, j + 1, ACS_VLINE);
							}
							else
							{
								mvwaddch(display, i + 1, j + 1, ACS_TTEE);
							}
							break;
						}
						case '8':
						{
							if (i == 31)
							{
								mvwaddch(display, i + 2, j + 1, ACS_BTEE);
								mvwaddch(display, i + 1, j + 1, ACS_VLINE);
							}
							else
							{
								mvwaddch(display, i + 1, j + 1, ACS_BTEE);
							}
							break;
						}
						case '9':
						{
							mvwaddch(display, i + 1, j + 1, ACS_DIAMOND);
							break;
						}
						case '0':
						{
							mvwprintw(display, i + 1, j + 1, "%c", '&');
							break;
						}
						case '-':
						{
							mvwaddch(display, i + 1, j + 1, ACS_HLINE);
							break;
						}
						case '|':
						{
							mvwaddch(display, i + 1, j + 1, ACS_VLINE);
							break;
						}
						case 'X':
						{
							mvwaddch(display, i + 1, j + 1, ACS_CKBOARD);
							break;
						}
						case 'x':
						{
							mvwaddch(display, i + 1, j + 1, ACS_CKBOARD);
							break;
						}
						case '!':
						{
							mvwprintw(display, i + 1, j + 1, "%c", '!');
							break;
						}
						case 'E':
						{
							wattron(display, COLOR_PAIR(3));
							mvwprintw(display, i + 1, j + 1, "%c", 'E');
							wattroff(display, COLOR_PAIR(3));
							break;
						}
						case 'l':
						{
							wattron(display, COLOR_PAIR(2));
							mvwaddch(display, i + 1, j + 1, ACS_LANTERN);
							wattroff(display, COLOR_PAIR(2));
							break;
						}
						case 'e':
						{
							wattron(display, COLOR_PAIR(3));
							mvwprintw(display, i + 1, j + 1, "%c", 'e');
							wattroff(display, COLOR_PAIR(3));
							break;
						}
						default:
						{
							mvwprintw(display, i + 1, j + 1, "%c", temp);
							break;
						}
						}
					}
				}
			}
		}
		wrefresh(win);
		wrefresh(stats);
		wrefresh(bars);
		wrefresh(topbar);
		wrefresh(map);
		wrefresh(shortcuts);
		wrefresh(display);
		choice = wgetch(win);
		if (choice == 27)
		{
			mode = true;
		}
		else
		{
			switch (choice)
			{
			case KEY_UP:
			{
				if (mode == 0)
				{
					return 28;
				}
				else
				{
					if (highlight > 0)
					{
						highlight--;
					}
				}
				break;
			}
			case KEY_DOWN:
			{
				if (mode == 0)
				{
					return 22;
				}
				else
				{
					if (highlight < shortyBorder)
					{
						highlight++;
					}
				}
				break;
			}
			case KEY_LEFT:
			{
				if (mode == 0)
				{
					return 24;
				}
				break;
			}
			case KEY_RIGHT:
			{
				if (mode == 0)
				{
					return 26;
				}
				break;
			}
			default:
			{
				break;
			}
			}
		}
		if (choice == 10 and mode == true)
		{
			return highlight;
		}
	}
}
int tabFight(player gracz, Mob enemy, int& highlight, string playerInfo[18], string shortcuts[20], string actions[20])
{
	int shortcutsBorder = 19;
	int actionsBorder = 19;
	for (int i = 0; i < 20; i++)
	{
		if (shortcuts[i] == "")
		{
			shortcutsBorder--;
		}
		if (actions[i] == "")
		{
			actionsBorder--;
		}
	}
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	WINDOW* topBar = newwin(3, maxX, 0, 0);
	WINDOW* playerSide = newwin(20, 70, 2, 0);
	WINDOW* enemySide = newwin(20, 70, 2, 69);
	WINDOW* shortcutsTab = newwin(22, 24, 21, 0);
	WINDOW* display = newwin(22, 116, 21, 23);
	int choice;
	keypad(win, true);
	while (1)
	{
		wborder(win, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		wrefresh(win);
		//topbar
		{
			wborder(topBar, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
			windowDrawOnCenter(topBar, 1, 67, gracz.nazwa);
			windowDrawOnCenter(topBar, 1, 67, enemy.mobName, 70);
			mvwaddch(topBar, 0, 69, ACS_TTEE);
			mvwaddch(topBar, 1, 69, ACS_VLINE);
			mvwaddch(topBar, 2, 69, ACS_BTEE);
			wrefresh(topBar);
		}
		//player info
		{
			wborder(playerSide, 0, 0, 0, 0, ACS_LTEE, ACS_PLUS, ACS_LTEE, ACS_BTEE);
			for (int i = 0; i < 18; i++)
			{
				windowDrawOnCenter(playerSide, i + 1, 68, playerInfo[i]);
			}
			wrefresh(playerSide);
		}
		//monster info
		{
			wborder(enemySide, 0, 0, 0, 0, ACS_PLUS, ACS_RTEE, ACS_LTEE, ACS_BTEE);
			for (int i = 0; i < 18; i++)
			{
				windowDrawOnCenter(enemySide, i + 1, 68, enemy.fightInfo[i]);
			}
			wrefresh(enemySide);
		}
		//shortcuts
		{
			wborder(shortcutsTab, 0, 0, 0, 0, ACS_LTEE, ACS_TTEE, ACS_LTEE, ACS_BTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight < 20 && highlight == i)
				{
					wattron(shortcutsTab, A_REVERSE);
				}
				mvwprintw(shortcutsTab, i + 1, 2, shortcuts[i].c_str());
				wattroff(shortcutsTab, A_REVERSE);
			}
			wrefresh(shortcutsTab);
		}
		//main display
		{
			wborder(display, 0, 0, 0, 0, ACS_TTEE, ACS_RTEE, ACS_BTEE, ACS_RTEE);
			mvwaddch(display, 0, 46, ACS_BTEE);
			for (int i = 0; i < 20; i++)
			{
				if (highlight - 20 == i && highlight >= 20)
				{
					wattron(display, A_REVERSE);
				}
				string temp = actions[i];
				int loop_max = 113 - temp.size();
				for (int i = 0; i < loop_max; i++)
				{
					temp += " ";
				}
				mvwprintw(display, i + 1, 2, temp.c_str());
				wattroff(display, A_REVERSE);
			}
			wrefresh(display);
		}
		choice = wgetch(win);
		switch (choice)
		{
		case KEY_UP:
		{
			if (highlight > 0 && highlight < 20 && highlight < shortcutsBorder)
			{
				highlight--;
			}
			else if (highlight > 20 && highlight < 40 && highlight <= 20 + actionsBorder)
			{
				highlight--;
			}
			else if (highlight == 20)
			{
				highlight = shortcutsBorder;
			}
			break;
		}
		case KEY_DOWN:
		{
			if (highlight < 20 && highlight < shortcutsBorder)
			{
				highlight++;
			}
			else if (highlight >= 20 && highlight < 40 && highlight < 20 + actionsBorder)
			{
				highlight++;
			}
			else if (highlight < 20 && highlight == shortcutsBorder)
			{
				highlight = 20 + actionsBorder;
			}
			break;
		}
		case KEY_LEFT:
		{
			if (highlight >= 20 && highlight < 40)
			{
				highlight -= 20;
				if (highlight > actionsBorder)
				{
					highlight = shortcutsBorder;
				}
			}
			else if (highlight > 40)
			{
				highlight--;
			}
			break;
		}
		case KEY_RIGHT:
		{
			if (highlight < 20)
			{
				highlight += 20;
				if (highlight >= 20 + shortcutsBorder)
				{
					highlight = 20 + actionsBorder;
				}
			}
			else if (highlight >= 40 && highlight < 42)
			{
				highlight++;
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
			return 0;
		}
	}
}