#pragma once
//#include "biblioteki.h"
#include "dwellers.h"
#include "player.h"

//class table;
void findANewHighlight(int& highlight, string left_side[20], string right_side[20]);
player tradeModeGeneralStore(player& gracz, generalStoreSeller& handlarz);
player tradeModeBladesmithShop(player& gracz, bladesmith& miecznik);
