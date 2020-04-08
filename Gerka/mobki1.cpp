#include "mobki1.h"

void Mob::isThisMobCanDropTheItem()
{
	srand((unsigned int)time(NULL));
	int random = rand() % 100;
	if (random > this->dropRateForItem)
	{
		this->thisMonsterAreAbleToDropItem = true;
	}
	else
	{
		this->thisMonsterAreAbleToDropItem = false;
	}
}
void Mob::loadData(string path)
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	plik.open(path, ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 2:this->mobName = linia; break;
		case 4:this->HP = atoi(linia.c_str()); break;
		case 6:this->XP = atoi(linia.c_str()); break;
		case 8:this->damage = atoi(linia.c_str()); break;
		case 10:this->defence = atoi(linia.c_str()); break;
		case 12:this->baseDroppedGold = atoi(linia.c_str()); break;
		case 14:this->additionalDroppedGold= atoi(linia.c_str()); break;
		case 16:this->droppedItem = linia; break;
		case 18:this->dropRateForItem = atoi(linia.c_str()); break;
		case 20:this->baseDealingDamageRate= atoi(linia.c_str()); break;
		case 22:this->additionalDealingDamageRate = atoi(linia.c_str()); break;
		case 24:this->baseGettingHitRate = atoi(linia.c_str()); break;
		case 26:this->additionalGettingHitRate = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	plik.close();
	this->maxHP = this->HP;
	{
		this->fightInfo[0] = "Health points: " + to_string(this->HP) + "/" + to_string(this->maxHP);
		this->fightInfo[1] = "Damage: " + to_string(this->damage);
		this->fightInfo[2] = "Defence: " + to_string(this->defence);
		this->fightInfo[3] = "";
		this->fightInfo[4] = "";
		this->fightInfo[5] = "";
		this->fightInfo[6] = "";
		this->fightInfo[7] = "";
		this->fightInfo[8] = "";
		this->fightInfo[9] = "";
		this->fightInfo[10] = "";
		this->fightInfo[11] = "";
		this->fightInfo[12] = "";
		this->fightInfo[13] = "";
		this->fightInfo[14] = "";
		this->fightInfo[15] = "";
		this->fightInfo[16] = "";
		this->fightInfo[17] = "";
	}
}
void Mob::updateFightInfo()
{
	this->fightInfo[0] = "Health points: " + to_string(this->HP) + "/" + to_string(this->maxHP);
	this->fightInfo[1] = "Damage: " + to_string(this->damage);
	this->fightInfo[2] = "Defence: " + to_string(this->defence);
	this->fightInfo[3] = "";
	this->fightInfo[4] = "";
	this->fightInfo[5] = "";
	this->fightInfo[6] = "";
	this->fightInfo[7] = "";
	this->fightInfo[8] = "";
	this->fightInfo[9] = "";
	this->fightInfo[10] = "";
	this->fightInfo[11] = "";
	this->fightInfo[12] = "";
	this->fightInfo[13] = "";
	this->fightInfo[14] = "";
	this->fightInfo[15] = "";
	this->fightInfo[16] = "";
	this->fightInfo[17] = "";
}
int Mob::returnDroppedGold()
{
	return (rand()% this->additionalDroppedGold) + this->baseDroppedGold;
}
int Mob::returnDealingDamageRate()
{
	return (rand() % this->additionalDealingDamageRate) + this->baseDealingDamageRate;
}
int Mob::returnGettingHitRate()
{
	return (rand() % this->additionalGettingHitRate) + this->baseGettingHitRate;
}
