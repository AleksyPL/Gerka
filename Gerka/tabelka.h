#pragma once
#include "biblioteki.h"
#include "walka.h"
#include "dwellers.h"
#include "trade_tab.h"
#include "player.h"

void draw_progress_bar(int min, int max, int how_long, int color);
void draw_spaces(int i);
void draw_on_center(int how_log, string name);
void draw_to_right_with_parameter_and_space_before(string name0, int how_long0, string name1, int how_long1);
void tab(player gracz, string info[8],string menu[100],long ceny[20]);
void tab_items(player gracz,string menu[100], int menu_amount[60], string info[7]);
void tab_trade(player &gracz, seller &handlarz, table &menu);
void tab_fight(player gracz, string menu[80], Przeciwnik enemy);
void tab_cheat(player gracz, string info[8], string menu[80]);