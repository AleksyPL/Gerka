#pragma once
#include "biblioteki.h"
#include "player.h"
#include "mobki1.h"

void victoryCondition(int height, int startPoint, Mob enemy, player& gracz, bool& victory, string& itemName);
void pickUpItemDroppedByEnemy(int height, int startPoint, Mob enemy, player& gracz, string& itemName);
player enterFightMode(player gracz, string monsterName, bool playerGoesFirst, bool& victory, string& itemName);