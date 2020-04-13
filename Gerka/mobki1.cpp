#include "mobki1.h"

Mob::Mob(string path)
{
	/*for (int i = 0; i < 18; i++)
	{
		this->fightInfo[i] = "";
	}*/
	loadData(path);
	isThisMobCanDropTheItem();
}
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
		this->fightInfo.push_back("Health points: " + to_string(this->HP) + "/" + to_string(this->maxHP));
		this->fightInfo.push_back("Damage: " + to_string(this->damage));
		this->fightInfo.push_back("Defence: " + to_string(this->defence));
	}
}
void Mob::updateFightInfo()
{
	fightInfo.clear();
	this->fightInfo.push_back("Health points: " + to_string(this->HP) + "/" + to_string(this->maxHP));
	this->fightInfo.push_back("Damage: " + to_string(this->damage));
	this->fightInfo.push_back("Defence: " + to_string(this->defence));
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
