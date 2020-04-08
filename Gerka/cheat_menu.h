#pragma once
//#include "biblioteki.h"
#include "player.h"

int loadValueInt(int height, int startPoint, bool& succes, string comment, int active0, string mark, int min, int active1=0, string mark1="", int max=0);
__int64 loadValue__int64(int height, int startPoint, bool& succes, string comment, int active0, string mark, int min, int active1 = 0, string mark1 = "", int max = 0);
player enterCheatMenu(player &gracz);