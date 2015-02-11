#ifndef FIGHT_H_
#define FIGHT_H_

#include "hero.h"
#include "enemy.h"
#include "skills.h"
#include "RNG.h"


class fight 
{
protected:
	Hero* hero;
	Enemy* enemy;	
	int distance;
	bool fight_end;
	RNG number;
public:
	void SetFighters(Hero* one, Enemy* two);
	void HeroAttack(int damage, int stamina_drop, int speed);
	void EnemyAttack(int damage, int stamina_drop, int speed);
	void DistantFight(std::vector<std::string> *comunicates);
	void MeleeFight(std::vector<std::string> *comunicates);
	void Main_Fight(std::vector<std::string> *comunicates);
	void LevelCheck();
	fight() : distance(20), fight_end(false) {};
	fight(Hero* one, Enemy* two, int value) : hero(one), enemy(two), distance(value), fight_end(false) {};
};
#endif