#include "boost_syf.h"

void addNerfStrenght(player &gracz,int ilosc_godzin,int minus)
{
	gracz.before_nerf_str = gracz.str;
	gracz.str = gracz.str -minus;
	gracz.counter_nerf_str = gracz.counter_nerf_str + ilosc_godzin;
}
void addBoostStrenght(player &gracz, int ilosc_godzin, int plus)
{
	gracz.before_boost_str = gracz.str;
	gracz.str =gracz.str +plus;
	gracz.counter_boost_str = gracz.counter_boost_str + ilosc_godzin;
}
void removeNerfStrenght(player &gracz)
{
	gracz.str = gracz.before_nerf_str;
	gracz.counter_nerf_str = 0;
	gracz.before_nerf_str = 0;
}
void removeBoostStrenght(player &gracz)
{
	gracz.str = gracz.before_boost_str;
	gracz.counter_boost_str = 0;
	gracz.before_boost_str = 0;
}
void addNerfAgility(player &gracz, int ilosc_godzin, int minus)
{
	gracz.before_nerf_agility = gracz.agility;
	gracz.agility = gracz.agility - minus;
	gracz.counter_nerf_agility = gracz.counter_nerf_agility + ilosc_godzin;
}
void addBoostAgility(player &gracz, int ilosc_godzin, int plus)
{
	gracz.before_boost_agility = gracz.agility;
	gracz.agility = gracz.agility + plus;
	gracz.counter_boost_agility = gracz.counter_boost_agility + ilosc_godzin;
}
void removeNerfAgility(player &gracz)
{
	gracz.agility = gracz.before_nerf_agility;
	gracz.counter_nerf_agility = 0;
	gracz.before_nerf_agility = 0;
}
void removeBoostAgility(player &gracz)
{
	gracz.agility = gracz.before_boost_agility;
	gracz.counter_boost_agility = 0;
	gracz.before_boost_agility = 0;
}
void addNerfIntelligence(player &gracz, int ilosc_godzin, int minus)
{
	gracz.before_nerf_intel = gracz.intel;
	gracz.intel = gracz.intel - minus;
	gracz.counter_nerf_intel = gracz.counter_nerf_intel +ilosc_godzin;
}
void addBoostIntelligence(player &gracz, int ilosc_godzin, int plus)
{
	gracz.before_boost_intel = gracz.intel;
	gracz.intel = gracz.intel + plus;
	gracz.counter_boost_intel = gracz.counter_boost_intel + ilosc_godzin;
}
void removeNerfIntelligence(player &gracz)
{
	gracz.intel = gracz.before_nerf_intel;
	gracz.counter_nerf_intel = 0;
	gracz.before_nerf_intel = 0;
}
void removeBoostIntelligence(player &gracz)
{
	gracz.intel = gracz.before_boost_intel;
	gracz.counter_boost_intel = 0;
	gracz.before_boost_intel = 0;
}
void addNerfLuck(player &gracz, int ilosc_godzin, int minus)
{
	gracz.before_nerf_luck = gracz.luck;
	gracz.luck = gracz.luck - minus;
	gracz.counter_nerf_luck = gracz.counter_nerf_luck + ilosc_godzin;
}
void addBoostLuck(player &gracz, int ilosc_godzin, int plus)
{
	gracz.before_boost_luck = gracz.luck;
	gracz.luck = gracz.luck + plus;
	gracz.counter_boost_luck = gracz.counter_boost_luck + ilosc_godzin;
}
void removeNerfLuck(player &gracz)
{
	gracz.luck = gracz.before_nerf_luck;
	gracz.counter_nerf_luck = 0;
	gracz.before_nerf_luck = 0;
}
void removeBoostLuck(player &gracz)
{
	gracz.luck = gracz.before_boost_luck;
	gracz.counter_boost_luck = 0;
	gracz.before_boost_luck = 0;
}
void addNerfCharisma(player &gracz, int ilosc_godzin, int minus)
{
	gracz.before_nerf_charisma = gracz.charisma;
	gracz.charisma = gracz.charisma - minus;
	gracz.counter_nerf_charisma = gracz.counter_nerf_charisma + ilosc_godzin;
}
void addBoostCharisma(player &gracz, int ilosc_godzin, int plus)
{
	gracz.before_boost_charisma = gracz.charisma;
	gracz.charisma = gracz.charisma + plus;
	gracz.counter_boost_charisma = gracz.counter_boost_charisma + ilosc_godzin;
}
void removeNerfCharisma(player &gracz)
{
	gracz.charisma = gracz.before_nerf_charisma;
	gracz.counter_nerf_charisma = 0;
	gracz.before_nerf_charisma = 0;
}
void removeBoostCharisma(player &gracz)
{
	gracz.charisma = gracz.before_boost_charisma;
	gracz.counter_boost_charisma = 0;
	gracz.before_boost_charisma = 0;
}
