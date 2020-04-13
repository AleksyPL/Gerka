#pragma once
#include "player.h"

void addNerfStrenght(player &gracz, int ilosc_godzin, int minus);
void addBoostStrenght(player &gracz, int ilosc_godzin, int plus);
void removeNerfStrenght(player &gracz);
void removeBoostStrenght(player &gracz);
void addNerfAgility(player &gracz, int ilosc_godzin, int minus);
void addBoostAgility(player &gracz, int ilosc_godzin, int plus);
void removeNerfAgility(player &gracz);
void removeBoostAgility(player &gracz);
void addNerfIntelligence(player &gracz, int ilosc_godzin, int minus);
void addBoostIntelligence(player &gracz, int ilosc_godzin, int plus);
void removeNerfIntelligence(player& gracz);
void removeBoostIntelligence(player &gracz);
void addNerfLuck(player &gracz, int ilosc_godzin, int minus);
void addBoostLuck(player &gracz, int ilosc_godzin, int plus);
void removeNerfLuck(player &gracz);
void removeBoostLuck(player &gracz);
void addNerfCharisma(player &gracz, int ilosc_godzin, int minus);
void addBoostCharisma(player &gracz, int ilosc_godzin, int plus);
void removeNerfCharisma(player &gracz);
void removeBoostCharisma(player &gracz);
