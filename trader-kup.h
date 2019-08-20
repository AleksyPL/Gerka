#pragma once
#include "biblioteki.h"
#include "trader.h"
#include "player.h"
#include "tabelka.h"

void nadaj_towar_kup(string menu[80], long ceny[20]);
player kup(player gracz, int cenka, string przedmiot);
player trade_kup(player gracz);
