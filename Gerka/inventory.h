#pragma once
#include "biblioteki.h"
#include "player.h"

void print_option(string item);
player what_to_do(player &gracz, string menu[60], int menu_amount[60],string info[7], int i);
player enter_inventory(player &gracz);