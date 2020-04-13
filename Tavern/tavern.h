#pragma once
#include "player.h"
#define DLLFUNCEX __declspec(dllexport)
#define DLLFUNCIM __declspec(dllimport)

void drunked(int height, int startPoint, player& gracz);
void robbery(int height, int startPoint, player& gracz, vector <string> message);
void flirting(int height, int startPoint, player& gracz);
extern "C" DLLFUNCEX void enterTavern();