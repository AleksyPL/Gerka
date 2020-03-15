#include "game_over.h"
#include "tabelka.h"

void game_over(int height, int startPoint)
{
	int maxX, maxY;
	getyx(stdscr, maxY, maxX);
	WINDOW* win = newwin(height, maxX, startPoint, 0);
	wborder(win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, ACS_LLCORNER, ACS_LRCORNER);
	string linia;
	fstream plik;
	int nr_linii = 2;
	plik.open("./txt/mix/game_over0.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		windowDrawOnCenter(win, nr_linii, 136, linia);
		nr_linii++;
	}
	plik.close();
	nr_linii += 3;
	plik.open("./txt/mix/game_over1.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		windowDrawOnCenter(win, nr_linii, 136, linia);
		nr_linii++;
	}
	plik.close();
	windowDrawOnCenter(win, height - 2, 136, "Press any key to continue...");
	wrefresh(win);
	sound_game_over();
	getch();
	
}