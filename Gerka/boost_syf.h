#pragma once
#include "player.h"

void add_nerf_str(player &gracz, int ilosc_godzin, int minus);
void add_boost_str(player &gracz, int ilosc_godzin, int plus);
void remove_nerf_str(player &gracz);
void remove_boost_str(player &gracz);
void add_nerf_agility(player &gracz, int ilosc_godzin, int minus);
void add_boost_agility(player &gracz, int ilosc_godzin, int plus);
void remove_nerf_agility(player &gracz);
void remove_boost_agility(player &gracz);
void add_nerf_intel(player &gracz, int ilosc_godzin, int minus);
void add_boost_intel(player &gracz, int ilosc_godzin, int plus);
void remove_nerf_intel(player &gracz);
void remove_boost_intel(player &gracz);
void add_nerf_luck(player &gracz, int ilosc_godzin, int minus);
void add_boost_luck(player &gracz, int ilosc_godzin, int plus);
void remove_nerf_luck(player &gracz);
void remove_boost_luck(player &gracz);
void add_nerf_charisma(player &gracz, int ilosc_godzin, int minus);
void add_boost_charisma(player &gracz, int ilosc_godzin, int plus);
void remove_nerf_charisma(player &gracz);
void remove_boost_charisma(player &gracz);
