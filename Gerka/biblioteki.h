#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<ctime>
#include<fstream>
#include<algorithm>
#include<curses.h>
#include<vector>
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib,"lib/pdcurses.lib")
//#include "include/curses.h"
//#include <../../Gerka/include/curses.h>

using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::to_string;
using std::transform;
using std::vector;

void soundDrums();
void soundDamage();
void soundDrink();
void soundStartFight();
void soundHit();
void soundBeer();
void soundSuccess();
void soundAlchemy();
void soundCash();
void soundBlacksmith();
void soundHealUp();
void soundShaman();
void soundCheatActivated();
void soundGameOver();
void soundStop();
void soundNoMoney();
void soundDropItem();
void soundRejection();
string noMoney();
void change_color(int num);
string stringToLower(string data);
void windowDrawOnCenter(WINDOW * win, int y, int how_log, string name, int x = 1, int spaces_on_the_end = 1);
string findItemOnList(string item);
bool fileExist(string path);