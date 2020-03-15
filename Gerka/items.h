#pragma once
#include "biblioteki.h"
#include "player.h"

void use_hp_potion(player &gracz);
void info_hp_potion(int height, int startPoint);
void use_item(int height, int startPoint, string item, int useDropInfo, player& gracz);
