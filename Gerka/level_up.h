#pragma once
#include "biblioteki.h"
#include "player.h"

void removeNegativeEffects(player& gracz);
void levelUp(int height, int startPoint, player& gracz, int skipCheckingXP=0);
