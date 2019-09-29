#pragma once
#include "biblioteki.h"
#include "player.h"

void boost_nerf(player &gracz);
void hungry_and_sober(player &gracz, int off_hunger = 0, int off_sobering = 0);
void change_time(player &gracz, int hours, int minutes,int off_hunger=0,int off_sobering=0);