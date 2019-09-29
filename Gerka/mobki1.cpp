#include "mobki1.h"

Mieszkaniec_small::Mieszkaniec_small()
{
	hp = 20;
	max_hp = hp;
	xp = 10;
	damage = 3;
	gold = (rand() % 10) + 1;
	name = "MIESZKANIEC";
	drop_item = "Ludzki z¹b";
	drop_rate = 30;
}
Mieszkaniec_medium::Mieszkaniec_medium()
{
	hp = 25;
	max_hp = hp;
	xp = 15;
	damage = 4;
	gold = (rand() % 10) + 5;
	name = "MIESZKANIEC";
	drop_item = "Ludzki z¹b";
	drop_rate = 30;
}
Mieszkaniec_big::Mieszkaniec_big()
{
	hp = 30;
	max_hp = hp;
	xp = 20;
	damage = 5;
	gold = (rand() % 10) + 10;
	name = "MIESZKANIEC";
	drop_item = "Ludzki z¹b";
	drop_rate = 30;
}