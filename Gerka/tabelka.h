#pragma once
#include "biblioteki.h"
#include "tawerna.h"
#include "walka.h"
#include "dwellers.h"
#include "trade_tab.h"

void tab(player gracz, string info[8],string menu[100],long ceny[20]);
void tab_items(player gracz,string menu[60]);
void tab_trade(player &gracz, seller &handlarz, table &menu);
void tab_fight(player gracz, string menu[80], Przeciwnik enemy);
void tab_cheat(player gracz, string info[8], string menu[80]);