#pragma once
//#include "biblioteki.h"
#include "dwellers.h"
#include "player.h"

void drunked(int height, int startPoint, player& gracz);
void robbery(int height, int startPoint, player &gracz, vector <string> message);
void flirting(int height, int startPoint, player &gracz);
player enterTavern(player gracz,barman bobby, chest &krzynka);