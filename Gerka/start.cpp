#include "start.h"
#include "town square.h"
#include "player.h"
#include "tytul.h"
#include "dwellers.h"
#include "zakres.h"
#include "load.h"


int logo(bool &tryb, WINDOW * win)
{
	wclear(win);
	box(win, 0, 0);
	int nr_linii = 1;
	string linia;
	fstream plik;
	if (tryb == false)
	{
		plik.open("./txt/mix/logo2.txt", ios::in);
		while (!plik.eof())
		{
			getline(plik, linia);
			windowDrawOnCenter(win, nr_linii, 137, linia.c_str());
			nr_linii++;
		}
		plik.close();
		wrefresh(win);
	}
	//INTRO
	else
	{		
		sound_drums();
		{
			plik.open("./txt/mix/logo0.txt", ios::in);
			while (!plik.eof())
			{
				getline(plik, linia);
				windowDrawOnCenter(win, nr_linii, 137, linia.c_str());
				nr_linii++;
			}
			plik.close();
			wrefresh(win);
		}
		Sleep(3000);
		nr_linii = 1;
		wclear(win);
		box(win, 0, 0);
		{
			plik.open("./txt/mix/logo2.txt", ios::in);
			while (!plik.eof())
			{
				getline(plik, linia);
				windowDrawOnCenter(win, nr_linii, 137, linia.c_str());
				nr_linii++;
			}
			plik.close();
			wrefresh(win);
		}
		tryb = 0;
	}
	return nr_linii;
}
void show_credits(WINDOW * win)
{
	wclear(win);
	box(win, 0, 0);
	int nr_linii = 1;
	string linia;
	fstream plik;
	plik.open("./txt/mix/credits.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		windowDrawOnCenter(win, nr_linii, 137, linia.c_str());
		nr_linii++;
	}
	plik.close();
	windowDrawOnCenter(win, nr_linii + 3, 137, "Press any key to continue...");
	wrefresh(win);
	getch();
	wclear(win);
}

int main()
{
	//setlocale(LC_ALL, "polish");
	system("MODE CON COLS=139 LINES=55");
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	player gracz;
	barman bobby;
	seller handlarz;
	blacksmith kowal(gracz);
	alchemist alchemik;
	shaman szaman;
	doctor lekarz;
	chest krzynka;
	initscr();
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW * win = newwin(maxY, maxX, 0, 0);
	noecho();
	refresh();
	bool playIntro = false;
	keypad(win, true);
	string choices[4] = {"New Game ","Load Game","Credits  ","Exit Game"};
	int choice;
	int highlight = 0;
	while (1)
	{
		box(win, 0, 0);
		int line_nr_after_intro = logo(playIntro, win);
		for (int i = 0; i < 4; i++)
		{
			if (i == highlight)
			{
				wattron(win, A_REVERSE);
			}
			windowDrawOnCenter(win, line_nr_after_intro + i + 5, 137, choices[i].c_str());
			wattroff(win, A_REVERSE);
		}
		wrefresh(win);
		choice = wgetch(win);
		switch (choice)
		{
		case KEY_UP:
		{
			highlight--;
			if (highlight == -1)
			{
				highlight = 3;
			}
			break;
		}
		case KEY_DOWN:
		{
			highlight++;
			if (highlight == 4)
			{
				highlight = 0;
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
			if (highlight == 2)
			{
				show_credits(win);
			}
			else
			{
				break;
			}
		}
	}
	if (highlight == 0)
	{
		echo();
		wclear(win);
		box(win, 0, 0);
		wrefresh(win);
		int row_number = 1;
		WINDOW * title = newwin(3, maxX, 0, 0);
		wborder(title, 0, 0, 0, 0, ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE);
		windowDrawOnCenter(title,1,137, "Create your character");
		wrefresh(title);
		row_number += 4;
		windowDrawOnCenter(win, row_number, 137, "Write your name: ", 1,0);
		wrefresh(win);
		char napis[20];
		wgetstr(win,napis);
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
		WINDOW * stats = newwin(8, 137, row_number+4, 1);
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
			string buttons[13] = { "<","<","<","<","<","<",">",">",">",">",">",">","Confirm"};
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
				else if (skills_temp[highlight]!= skills_temp[highlight+6])
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
					else if (highlight<6 && skills_temp[highlight+6]>skills_temp[highlight])
					{
						if (highlight == 0)
						{
							skills_temp[highlight+6] -= 10;
						}
						else
						{
							skills_temp[highlight+6] -=1;
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
		give_the_title(gracz);
		enterTownSquare(gracz, bobby, handlarz, kowal, alchemik, szaman, lekarz, krzynka);
	}
	else if (highlight == 1)
	{
		loadGame(gracz,bobby,handlarz,kowal,alchemik,krzynka);
		krzynka.sort_usage();
		krzynka.sort_alchemy();
		krzynka.sort_forge();
		range(gracz);
		give_the_title(gracz);
		enterTownSquare(gracz, bobby, handlarz, kowal, alchemik, szaman, lekarz, krzynka);
	}
	else if (highlight == 2)
	{
		mvwprintw(win, 20, 2, "Closing game...");
		wrefresh(win);
		Sleep(2000);
		endwin();
		return 0;
	}
	endwin();
	return 0;
}
