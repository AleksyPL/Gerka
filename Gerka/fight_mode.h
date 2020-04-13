#pragma once
//#include "biblioteki.h"
#include "player.h"
#include "mobki1.h"

void victoryCondition(int height, int startPoint, Mob enemy, player& gracz, bool& victory, string& itemName);
void pickUpItemDroppedByEnemy(int height, int startPoint, Mob enemy, player& gracz, string& itemName);
void dealingDamage(int height, int startPoint, player& gracz, Mob& enemy, bool& isItThePlayersTurnNow);
string makeString(int howLong, string function, int chances);
void enterFightMode(player gracz, string monsterName, bool playerGoesFirst, bool& victory, string& itemName);