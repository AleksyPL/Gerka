#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<ctime>
#include<fstream>
#include<algorithm>
#include<curses.h>
#include<vector>
#pragma comment(lib, "winmm.lib")
//#pragma comment(lib,"lib/pdcurses.lib")
//#include "include/curses.h"

using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::to_string;
using std::transform;
using std::vector;

void sound_drums();
void sound_damage();
void sound_drink();
void sound_start_fight();
void sound_hit();
void sound_beer();
void sound_success();
void sound_alchemy();
void sound_cash();
void sound_blacksmith();
void sound_heal_up();
void sound_shaman();
void sound_cheat_activated();
void sound_game_over();
void sound_stop();
void sound_no_money();
void sound_drop_item();
void sound_rejection();
string no_money();
void change_color(int num);
string string_tolower(string data);
void windowDrawOnCenter(WINDOW * win, int y, int how_log, string name, int x = 1, int spaces_on_the_end = 1);
string findItemOnList(string item);
