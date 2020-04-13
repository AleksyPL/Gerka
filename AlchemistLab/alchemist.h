#pragma once
#define DLLFUNCEX __declspec(dllexport)
#define DLLFUNCIM __declspec(dllimport)

extern "C" DLLFUNCEX void enterAlchemistLab();
