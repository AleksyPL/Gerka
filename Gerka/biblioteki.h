#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<ctime>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<locale.h>
#include<algorithm>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::to_string;
using std::transform;

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
void no_money();
void change_color(int num);
string string_tolower(string data);
void print_info_box_from_file(string text);
void print_info_box_from_string(string text);
void fancy_text(string text);
