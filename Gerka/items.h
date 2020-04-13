#pragma once
//#include "biblioteki.h"
#include "player.h"

void rejection_use(int height, int startPoint);
bool useHpPotion(int height, int startPoint, player &gracz);
bool useLockpick(int height, int startPoint, player& gracz);
void infoHpPotion(int height, int startPoint);
void infoLockpick(int height, int startPoint);
bool useItem(int height, int startPoint, string item, int useDropInfo, player& gracz);
