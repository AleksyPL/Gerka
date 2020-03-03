#pragma once
#include "biblioteki.h"
#include "walka.h"
#include "dwellers.h"
#include "trade_tab.h"
#include "player.h"

string return_progress_bar(int min, int max, int how_long);
int tab(player gracz, int &highlight, string local, string shorty[20], string menu[20], long ceny[20]);
int tabItemsLeftOnly(int highlight, string top_side, string left_side[21], string right_side[21], vector <string> bottom_side);
int tabItemsLeftAndRight(int highlight, string top_side, string left_side[21], string right_side[21], vector <string> bottom_side);
void tabSubmenuTextOnly(int height, int startPoint, vector<string> myDisplay);
void tabSubmenuFancyTextOnly(int height, int startPoint, vector<string> myDisplay, int delay);
int tabSubmenuOneColumnChoice(int height, int startPoint, vector<string> message, vector<string> options);
//int tabSubmenuTwoColumnChoice(int height, int startPoint, int optionsLeftStart, int optionsRightStart, vector<string> message, vector<string> optionsLeft, vector<string> optionsRight);
string tabSubmenuInputField(int height, int startPoint, string message);
int tabTrade(int highlight, string top_side[3], string left_side[21], string right_side[21], vector <string> bottom_side);
int tabDungeon(player gracz, int mode, string local, string shorty[20], char tab[32][114]);
//void tab_fight(player gracz, string menu[80], Przeciwnik enemy);