#pragma once
//#include "biblioteki.h"
#include "player.h"

void boostNerf(player &gracz);
void hungryAndSober(int height, int startPoint, player &gracz, int off_hunger = 0, int off_sobering = 0);
void changeTime(int height, int startPoint, player &gracz, int hours, int minutes,int off_hunger=0,int off_sobering=0);
int waitingDamage(int height, int startPoint, player gracz, int hour, int minute);
void waitNHours(int height, int startPoint, player& gracz);