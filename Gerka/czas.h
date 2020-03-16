#pragma once
#include "biblioteki.h"
#include "player.h"

void boost_nerf(player &gracz);
void hungry_and_sober(int height, int startPoint, player &gracz, int off_hunger = 0, int off_sobering = 0);
void change_time(int height, int startPoint, player &gracz, int hours, int minutes,int off_hunger=0,int off_sobering=0);
int waitingDamage(int height, int startPoint, player gracz, int hour, int minute);
void wait_n_hours(int height, int startPoint, player& gracz);