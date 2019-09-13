#pragma once
#include "biblioteki.h"
#include "player.h"

void print_option(string nazwa,int ilosc);
void do_operation(player &gracz, string nazwa, int ilosc, string info[8]);
player enter_inventory(player &gracz);