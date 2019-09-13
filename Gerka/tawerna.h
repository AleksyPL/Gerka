#pragma once
#include "biblioteki.h"
#include "dwellers.h"
#include "player.h"

void drunked(player &gracz);
void robbery(player &gracz);
void flirting(player &gracz,string info);
player enter_tavern(player gracz,barman bobby, chest &krzynka);