#include "biblioteki.h"

void sound_drums()
{
	PlaySound(TEXT("./wav/drums.wav"), NULL, SND_ASYNC);
}
void sound_damage()
{
	PlaySound(TEXT("./wav/damage.wav"), NULL, SND_ASYNC);
}
void sound_drink()
{
	PlaySound(TEXT("./wav/picie.wav"), NULL, SND_ASYNC);
}
void sound_start_fight()
{
	PlaySound(TEXT("./wav/start_fight.wav"), NULL, SND_ASYNC);
}
void sound_hit()
{
	PlaySound(TEXT("./wav/hit.wav"), NULL, SND_ASYNC);
}
void sound_beer()
{
	PlaySound(TEXT("./wav/beer.wav"), NULL, SND_ASYNC);
}
void sound_success()
{
	PlaySound(TEXT("./wav/sukces.wav"), NULL, SND_ASYNC);
}
void sound_alchemy()
{
	PlaySound(TEXT("./wav/alchemik.wav"), NULL, SND_ASYNC);
}
void sound_cash()
{
	PlaySound(TEXT("./wav/cash.wav"), NULL, SND_ASYNC);
}
void sound_blacksmith()
{
	PlaySound(TEXT("./wav/kowal_up.wav"), NULL, SND_ASYNC);
}
void sound_heal_up()
{
	PlaySound(TEXT("./wav/heal_up.wav"), NULL, SND_ASYNC);
}
void sound_shaman()
{
	PlaySound(TEXT("./wav/shaman.wav"), NULL, SND_ASYNC);
}
void sound_cheat_activated()
{
	PlaySound(TEXT("./wav/cheat_activated.wav"), NULL, SND_ASYNC);
}
void sound_game_over()
{
	PlaySound(TEXT("./wav/hugo.wav"), NULL, SND_SYNC);
}
void sound_stop()
{
	PlaySound(NULL, NULL, 0);
}
void sound_no_money()
{
	PlaySound(TEXT("./wav/no_money.wav"), NULL, SND_ASYNC);
}
void no_money()
{
	sound_no_money();
	cout << "Nie staæ ciê na to!!!" << endl;
}
void change_color(int num)
{
	HANDLE cz;
	cz = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cz, num);
	//0 - czarny
	//1 - niebieski
	//2 - zielony
	//3 - b³êkitny
	//4 - czerwony
	//5 - purpurowy
	//6 - ¿ó³ty
	//7 - bia³y
	//8 - szary
	//9 - jasnoniebieski
	//10 - jasnozielony
	//11 - jasnob³êkitny
	//12 - jasnoczerwony
	//13 - jasnopurpurowy
	//14 - jasno¿ó³ty
	//15 - jaskrawobia³y
}