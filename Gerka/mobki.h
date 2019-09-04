#pragma once
#include "biblioteki.h"

class Mob {
private:
	string nazwa;		// Nazwa mobka

	int __dmg;			// Obra¿enia zadawane przez mobka
	int __hp;			// Iloœæ hp mobka

	int __exp_per_kill;	// Exp za zabicei tego mobka

public:
	Mob();
public:
	int dmg;
	int hp;
	int exp_per_kill;

	int get_base_hp();
	int get_base_dmg();
	int get_base_xp_per_kill();
};


/*MOBY LEVEL 1 - 10*/

class L01_goblin : public Mob {
private:
	string nazwa = "Golbin ";
	
	int dmg = 2;
	int hp = 7;
	
	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L01_goblin();
};

class L01_wolf : public Mob {
private:
	string nazwa = "Wolf ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L01_wolf();
};

class L01_cow : public Mob {
private:
	string nazwa = "Cow ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L01_cow();
};

class L01_chicken : public Mob {
private:
	string nazwa = "Chicken ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L01_chicken();
};

class L01_rat : public Mob {
private:
	string nazwa = "Rat ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L01_rat();
};

class L10_gigant_spider : public Mob {
private:
	string nazwa = "Gigant Spider ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L10_gigant_spider();
};

class L10_zombie_rat : public Mob {
private:
	string nazwa = "Zombie Rat ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L10_zombie_rat();
};

class L10_bat : public Mob {
private:
	string nazwa = "Bat ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L10_bat();
};

class L10_snake : public Mob {
private:
	string nazwa = "Snake ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L10_snake();
};

class L10_scorpion : public Mob {
private:
	string nazwa = "Scorpion ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L10_scorpion();
};

class L20_skeleton : public Mob {
private:
	string nazwa = "Skeleton ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L20_skeleton();
};

class L20_grizzly : public Mob {
private:
	string nazwa = "Grizzly ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L20_grizzly();
};

class L20_lizard : public Mob {
private:
	string nazwa = "Lizard ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L20_lizard();
};

class L20_cockroach : public Mob {
private:
	string nazwa = "Cockroach ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L20_cockroach();
};

class L20_ape : public Mob {
private:
	string nazwa = "Ape a.k.a Anon ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L20_ape();
};

class L30_baby_dragon : public Mob {
private:
	string nazwa = "Baby Dragon ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L30_baby_dragon();
};

class L30_shade : public Mob {
private:
	string nazwa = "Shade ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L30_shade();
};

class L30_cyclop : public Mob {
private:
	string nazwa = "Cyclop ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L30_cyclop();
};

class L30_bloodworm : public Mob {
private:
	string nazwa = "Bloodworm ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L30_bloodworm();
};

class L30_slime : public Mob {
private:
	string nazwa = "Slime ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L30_slime();
};

class L40_troll : public Mob {
private:
	string nazwa = "Troll ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L40_troll();
};

class L40_ogre : public Mob {
private:
	string nazwa = "Ogre ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L40_ogre();
};

class L40_ghul : public Mob {
private:
	string nazwa = "Ghul ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L40_ghul();
};

class L40_wasp_queen : public Mob {
private:
	string nazwa = "Wasp Queen ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L40_wasp_queen();
};

class L40_gigant_jellyfish : public Mob {
private:
	string nazwa = "Gigant Jellyfish ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L40_gigant_jellyfish();
};

class L50_dragon : public Mob {
private:
	string nazwa = "Dragon ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L50_dragon();
};

class L50_ice_troll : public Mob {
private:
	string nazwa = "Ice Troll ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L50_ice_troll();
};

class L50_basilisk : public Mob {
private:
	string nazwa = "Basilisk ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L50_basilisk();
};

class L50_demon : public Mob {
private:
	string nazwa = "Demon ";

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L50_demon();
};

class L50_gargoyle : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L50_gargoyle();
};

class L75_troll_general : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L75_troll_general();
};

class L75_brute_dragon : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L75_brute_dragon();
};

class L75_vampire : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L75_vampire();
};

class L75_warewolf : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L75_warewolf();
};

class L75_unicorn : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L75_unicorn();
};

class L9000_bauer : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L9000_bauer();
};

class L9000_aleksy : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L9000_aleksy();
};

class L9000_konstantin : public Mob {
private:
	string nazwa;

	int dmg;
	int hp;

	int exp_per_kill;

public:
	int get_dmg();
	int get_hp();
	int get_exp();

	string get_nazwa();

	L9000_konstantin();
};