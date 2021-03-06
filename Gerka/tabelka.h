#pragma once
#include "player.h"

string return_progress_bar(int min, int max, int how_long);
void findANewHighlight(int& highlight, string left_side[20], string right_side[20]);
int tab(player gracz, int &highlight, string local, string shorty[20], string menu[20], __int64 ceny[20]);
int tabItemsLeftOnly(int highlight, string top_side, string left_side[21], string right_side[21], vector <string> bottom_side);
int tabItemsLeftAndRight(int highlight, string top_side, string left_side[21], string right_side[21], vector <string> bottom_side);
void tabSubmenuTextOnly(int height, int startPoint, vector<string> myDisplay);
void tabSubmenuFancyTextOnly(int height, int startPoint, vector<string> myDisplay, int delay);
int tabSubmenuOneColumnChoice(int height, int startPoint, vector<string> message, vector<string> options);
string tabSubmenuInputField(int height, int startPoint, string message);
int tabTrade(int highlight, string top_side[3], string left_side[21], string right_side[21], vector <string> bottom_side);
int tabDungeon(player gracz, bool &mode, string local, string shorty[20], char tab[32][114], vector <char> levelMonstersSymbols);
int tabFight(player gracz, string mobName, vector <string> monsterInfo, int& highlight, string playerInfo[18], string shortcuts[20], string actions[20]);