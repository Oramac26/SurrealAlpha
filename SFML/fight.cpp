#include "fight.h"
#include "hero.h"
#include "RNG.h"

#define MEELE_RANGE 3
#define STAMINA 10

void fight::LevelCheck()
{
}

void fight::HeroAttack(int damage, int stamina_drop, int speed)
{
	enemy->ChangeHealth(-damage);
	hero->ChangeStamina(-stamina_drop);
	if (speed > 2 * enemy->WeaponParameters()->speed)
		HeroAttack(damage, stamina_drop, speed - 1);
}


void fight::EnemyAttack(int damage, int stamina_drop, int speed)
{
	hero->ChangeHealth(-damage);
	enemy->ChangeStamina(-stamina_drop);
	if (speed > 2 * hero->WeaponParameters()->speed)
		EnemyAttack(-damage, -stamina_drop, speed - 1);
}

void fight::DistantFight(std::vector<std::string> *comunicates)
{
	//RNG number;
	std::string comunicate(" ");
	int damage = 0;
	if ((hero->WeaponParameters()->range) && (hero->ViewStamina() > 0))
	{
		if (hero->FindSkill("agility"))
		{
			if (number.FortuneLoop(hero->FindSkill("agility")->ViewSkillLevel()))
			{
				damage = number.SmallRange(hero->WeaponParameters()->damage);
				comunicate += "You hit enemy for " + std::to_string(damage) + " He has " + std::to_string(enemy->ViewHealth()-damage) + " HP left";
				hero->FindSkill("agility")->SkillExpInc(damage);
				comunicates->push_back(comunicate);
			}
		}
		HeroAttack(damage, hero->WeaponParameters()->mass, hero->WeaponParameters()->speed);
	}
	if ((enemy->WeaponParameters()->range) && (enemy->ViewStamina() > 0))
	{
		damage = number.SmallRange(enemy->WeaponParameters()->damage);
		EnemyAttack(damage, enemy->WeaponParameters()->mass, enemy->WeaponParameters()->speed);
	}
	distance--;
}

void fight::MeleeFight(std::vector<std::string> *comunicates)
{
	//RNG number;
	std::string comunicate(" ");
	int damage = number.SmallRange(hero->CarriedMeleeWeapon()->damage);
	comunicate += "You hit enemy for " + std::to_string(damage) + " He has " + std::to_string(enemy->ViewHealth() - damage) + " HP left";
	comunicates->push_back(comunicate);
	HeroAttack(damage, hero->CarriedMeleeWeapon()->mass, hero->CarriedMeleeWeapon()->speed);
	damage = number.SmallRange(enemy->WeaponParameters()->damage);
	EnemyAttack(damage, enemy->WeaponParameters()->mass, enemy->WeaponParameters()->speed);
}

void fight::Main_Fight(std::vector<std::string> *comunicates)
{
	//RNG number;
	std::string comunicate(" ");
	while (!fight_end)
	{
		if (distance > MEELE_RANGE)
			DistantFight(comunicates);
		else
		{
			comunicate = "Enemy get too close";
			comunicates->push_back(comunicate);
			MeleeFight(comunicates);
		}
		hero->ChangeStamina(STAMINA);
		enemy->ChangeStamina(STAMINA);
		if (hero->ViewHealth() == 0)
		{
			fight_end = true;
		}
		if (enemy->ViewHealth() == 0)
		{
			fight_end = true;
			hero->HeroExpInc(number.SmallRange(enemy->ViewLevel()*10));
			comunicate = "You won";
			comunicates->push_back(comunicate);
		}
	}
}
void fight::SetFighters(Hero* one, Enemy* two)
{
	hero = one;
	enemy = two;
}