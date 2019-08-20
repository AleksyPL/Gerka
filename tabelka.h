#pragma once
#include "biblioteki.h"
#include "tawerna.h"
#include "walka.h"
#include "dwellers.h"

void tab(player gracz, string info[8],string menu[100],long ceny[20]);
void tab_items(player gracz,string menu[60]);
void tab_trade(player &gracz, seller &handlarz, string temp_table[80],string info[7], int temp_table_price[80], int temp_table_amount[80]);
void tab_fight(player gracz, string menu[80], Przeciwnik enemy);
void tab_cheat(player gracz, string info[8], string menu[80]);