#pragma once
#include "biblioteki.h"
#include "player.h"

void drunked(int height, int startPoint, player& gracz);
void robbery(int height, int startPoint, player& gracz, vector <string> message);
void flirting(int height, int startPoint, player& gracz);
#define DLLFUNCEX __declspec(dllexport)
#define DLLFUNCIM __declspec(dllimport)

extern "C" DLLFUNCEX void enterTavern();