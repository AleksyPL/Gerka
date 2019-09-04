#include "player.h"
#include "boost-syf.h"

void add_nerf_str(player &gracz,int ilosc_tur,int minus)
{
	gracz.before_nerf_str = gracz.str;
	gracz.str = gracz.str -minus;
	gracz.counter_nerf_str = gracz.counter_nerf_str + ilosc_tur;
}
void add_boost_str(player &gracz, int ilosc_tur, int plus)
{
	gracz.before_boost_str = gracz.str;
	gracz.str =gracz.str +plus;
	gracz.counter_boost_str = gracz.counter_boost_str + ilosc_tur;
}
void remove_nerf_str(player &gracz)
{
	gracz.str = gracz.before_nerf_str;
	gracz.counter_nerf_str = 0;
	gracz.before_nerf_str = 0;
}
void remove_boost_str(player &gracz)
{
	gracz.str = gracz.before_boost_str;
	gracz.counter_boost_str = 0;
	gracz.before_boost_str = 0;
}
void add_nerf_agility(player &gracz, int ilosc_tur, int minus)
{
	gracz.before_nerf_agility = gracz.agility;
	gracz.agility = gracz.agility - minus;
	gracz.counter_nerf_agility = gracz.counter_nerf_agility + ilosc_tur;
}
void add_boost_agility(player &gracz, int ilosc_tur, int plus)
{
	gracz.before_boost_agility = gracz.agility;
	gracz.agility = gracz.agility + plus;
	gracz.counter_boost_agility = gracz.counter_boost_agility + ilosc_tur;
}
void remove_nerf_agility(player &gracz)
{
	gracz.agility = gracz.before_nerf_agility;
	gracz.counter_nerf_agility = 0;
	gracz.before_nerf_agility = 0;
}
void remove_boost_agility(player &gracz)
{
	gracz.agility = gracz.before_boost_agility;
	gracz.counter_boost_agility = 0;
	gracz.before_boost_agility = 0;
}
void add_nerf_intel(player &gracz, int ilosc_tur, int minus)
{
	gracz.before_nerf_intel = gracz.intel;
	gracz.intel = gracz.intel - minus;
	gracz.counter_nerf_intel = gracz.counter_nerf_intel +ilosc_tur;
}
void add_boost_intel(player &gracz, int ilosc_tur, int plus)
{
	gracz.before_boost_intel = gracz.intel;
	gracz.intel = gracz.intel + plus;
	gracz.counter_boost_intel = gracz.counter_boost_intel + ilosc_tur;
}
void remove_nerf_intel(player &gracz)
{
	gracz.intel = gracz.before_nerf_intel;
	gracz.counter_nerf_intel = 0;
	gracz.before_nerf_intel = 0;
}
void remove_boost_intel(player &gracz)
{
	gracz.intel = gracz.before_boost_intel;
	gracz.counter_boost_intel = 0;
	gracz.before_boost_intel = 0;
}
void add_nerf_luck(player &gracz, int ilosc_tur, int minus)
{
	gracz.before_nerf_luck = gracz.luck;
	gracz.luck = gracz.luck - minus;
	gracz.counter_nerf_luck = gracz.counter_nerf_luck + ilosc_tur;
}
void add_boost_luck(player &gracz, int ilosc_tur, int plus)
{
	gracz.before_boost_luck = gracz.luck;
	gracz.luck = gracz.luck + plus;
	gracz.counter_boost_luck = gracz.counter_boost_luck + ilosc_tur;
}
void remove_nerf_luck(player &gracz)
{
	gracz.luck = gracz.before_nerf_luck;
	gracz.counter_nerf_luck = 0;
	gracz.before_nerf_luck = 0;
}
void remove_boost_luck(player &gracz)
{
	gracz.luck = gracz.before_boost_luck;
	gracz.counter_boost_luck = 0;
	gracz.before_boost_luck = 0;
}
void add_nerf_charisma(player &gracz, int ilosc_tur, int minus)
{
	gracz.before_nerf_charisma = gracz.charisma;
	gracz.charisma = gracz.charisma - minus;
	gracz.counter_nerf_charisma = gracz.counter_nerf_charisma + ilosc_tur;
}
void add_boost_charisma(player &gracz, int ilosc_tur, int plus)
{
	gracz.before_boost_charisma = gracz.charisma;
	gracz.charisma = gracz.charisma + plus;
	gracz.counter_boost_charisma = gracz.counter_boost_charisma + ilosc_tur;
}
void remove_nerf_charisma(player &gracz)
{
	gracz.charisma = gracz.before_nerf_charisma;
	gracz.counter_nerf_charisma = 0;
	gracz.before_nerf_charisma = 0;
}
void remove_boost_charisma(player &gracz)
{
	gracz.charisma = gracz.before_boost_charisma;
	gracz.counter_boost_charisma = 0;
	gracz.before_boost_charisma = 0;
}
