#include "hero_creator.h"

void enterHeroCreator(player& gracz)
{
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	int choice;
	int highlight = 0;
	echo();
	wclear(win);
	box(win, 0, 0);
	wrefresh(win);
	int row_number = 1;
	WINDOW* title = newwin(3, maxX, 0, 0);
	wborder(title, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
	windowDrawOnCenter(title, 1, 137, "Create your character");
	wrefresh(title);
	row_number += 4;
	windowDrawOnCenter(win, row_number, 137, "Write your name: ", 1, 0);
	wrefresh(win);
	char napis[20];
	wgetstr(win, napis);
	mvwprintw(win, 1, 1, napis);
	gracz.nazwa = napis;
	if (gracz.nazwa.size() == 0)
	{
		gracz.nazwa = "Nameless";
	}
	wrefresh(win);
	noecho();
	int skills_temp[12];
	skills_temp[0] = skills_temp[6] = gracz.max_hp;
	skills_temp[1] = skills_temp[7] = gracz.str;
	skills_temp[2] = skills_temp[8] = gracz.agility;
	skills_temp[3] = skills_temp[9] = gracz.intel;
	skills_temp[4] = skills_temp[10] = gracz.charisma;
	skills_temp[5] = skills_temp[11] = gracz.luck;
	int skill_points = 5;
	string temp;
	wborder(title, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
	windowDrawOnCenter(title, 1, 137, "Create your character");
	box(win, 0, 0);
	temp = "You can spend " + to_string(skill_points) + " points, choose wisely.";
	windowDrawOnCenter(win, row_number, 137, temp);
	wrefresh(win);
	wrefresh(title);
	WINDOW* stats = newwin(8, 137, row_number + 4, 1);
	while (1)
	{
		wclear(stats);
		temp = "Health points:         " + to_string(skills_temp[6]);
		windowDrawOnCenter(stats, 0, 101, temp, 1, 0);
		temp = "Strength points:       " + to_string(skills_temp[7]);
		windowDrawOnCenter(stats, 1, 100, temp, 1, 0);
		temp = "Agility points:        " + to_string(skills_temp[8]);
		windowDrawOnCenter(stats, 2, 100, temp, 1, 0);
		temp = "Intelligence points:   " + to_string(skills_temp[9]);
		windowDrawOnCenter(stats, 3, 100, temp, 1, 0);
		temp = "Charisma points:       " + to_string(skills_temp[10]);
		windowDrawOnCenter(stats, 4, 100, temp, 1, 0);
		temp = "Luck points:           " + to_string(skills_temp[11]);
		windowDrawOnCenter(stats, 5, 100, temp, 1, 0);
		string buttons[13] = { "<","<","<","<","<","<",">",">",">",">",">",">","Confirm" };
		for (int i = 0; i < 13; i++)
		{
			if (i == highlight)
			{
				wattron(stats, A_REVERSE);
			}
			if (i < 6)
			{
				mvwprintw(stats, i, 80, buttons[i].c_str());
			}
			else if (i >= 6)
			{
				if (i == 12)
				{
					windowDrawOnCenter(stats, 7, 137, buttons[12]);
				}
				else
				{
					mvwprintw(stats, i - 6, 85, buttons[i].c_str());
				}
			}
			wattroff(stats, A_REVERSE);
		}
		wrefresh(stats);
		keypad(stats, true);
		choice = wgetch(stats);
		switch (choice)
		{
		case KEY_UP:
		{
			highlight--;
			if (highlight == -1)
			{
				highlight = 12;
			}
			break;
		}
		case KEY_DOWN:
		{
			highlight++;
			if (highlight == 6)
			{
				highlight = 12;
			}
			if (highlight == 13)
			{
				highlight = 0;
			}
			break;
		}
		case KEY_LEFT:
		{
			highlight -= 6;
			if (highlight < 0)
			{
				highlight += 6;
			}
			break;
		}
		case KEY_RIGHT:
		{
			highlight += 6;
			if (highlight > 12)
			{
				highlight -= 6;
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
			if (highlight == 12 && skill_points == 0)
			{
				break;
			}
			else if (skills_temp[highlight] != skills_temp[highlight + 6])
			{
				if (highlight >= 6 && skill_points != 0)
				{
					if (highlight == 6)
					{
						skills_temp[highlight] += 10;
					}
					else
					{
						skills_temp[highlight]++;
					}
					skill_points--;
				}
				else if (highlight<6 && skills_temp[highlight + 6]>skills_temp[highlight])
				{
					if (highlight == 0)
					{
						skills_temp[highlight + 6] -= 10;
					}
					else
					{
						skills_temp[highlight + 6] -= 1;
					}
					skill_points++;
				}
				if (skill_points != 0)
				{
					temp = "You can spend " + to_string(skill_points) + " points, choose wisely.";
					windowDrawOnCenter(win, row_number, 137, temp);
					wrefresh(win);
				}
				else
				{
					temp = "No points remaining";
					windowDrawOnCenter(win, row_number, 137, temp);
					wrefresh(win);
				}
			}
		}
	}
	gracz.hp = gracz.max_hp = skills_temp[6];
	gracz.str = skills_temp[7];
	gracz.agility = skills_temp[8];
	gracz.intel = skills_temp[9];
	gracz.charisma = skills_temp[10];
	gracz.luck = skills_temp[11];
}
