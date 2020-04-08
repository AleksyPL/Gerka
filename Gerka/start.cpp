#include "start.h"
#include "town square.h"
#include "player.h"
#include "tytul.h"
#include "dwellers.h"
#include "zakres.h"
#include "load.h"
#include "hero_creator.h"


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
		soundDrums();
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
void showCredits(WINDOW * win)
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
	generalStoreSeller handlarz;
	blacksmith kowal;
	bladesmith miecznik;
	alchemist alchemik;
	shaman szaman;
	doctor lekarz;
	chest krzynka;
	initscr();
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(maxY, maxX, 0, 0);
	int highlight = 0;
	bool playIntro = false;
	while (1)
	{
		noecho();
		refresh();
		keypad(win, true);
		string choices[4] = { "New Game ","Load Game","Credits  ","Exit Game" };
		int choice;
		while (1)
		{
			box(win, 0, 0);
			int line_nr_after_intro = logo(playIntro, win);
			playIntro = false;
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
				break;
			}
		}
		if (highlight == 0)
		{
			enterHeroCreator(gracz);
			giveTheTitle(gracz);
			enterTownSquare(gracz, bobby, handlarz, kowal, miecznik, alchemik, szaman, lekarz, krzynka);
		}
		else if (highlight == 1)
		{
			loadGame(gracz, bobby, handlarz, kowal, alchemik, krzynka);
			krzynka.sortUsage();
			krzynka.sortAlchemy();
			krzynka.sortForge();
			range(gracz);
			giveTheTitle(gracz);
			enterTownSquare(gracz, bobby, handlarz, kowal, miecznik, alchemik, szaman, lekarz, krzynka);
		}
		else if (highlight == 2)
		{
			showCredits(win);
		}
		else if (highlight == 3)
		{
			windowDrawOnCenter(win, 27, 136, "Closing game...");
			wrefresh(win);
			Sleep(2000);
			endwin();
			return 0;
		}
	}
	endwin();
	return 0;
}
