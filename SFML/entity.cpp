#include "entity.h"


void Entity::ChangeHealth(int value) 
{ 
	health = health + value;
	if (health < 0)
		health = 0;
	if (health > health_max)
		health = health_max;
};
void Entity::MaxHealthInc()
{
	health_max = health_max + 20;
}

void Entity::MaxStaminaInc()
{
	stamina_max = stamina_max + 20;
}

void Entity::GainLevel()
{
	level++;
	MaxHealthInc();
	MaxStaminaInc();
}

void Entity::ChangeStamina(int value) 
{ 
	stamina = stamina + value; 
	if (stamina < 0)
		stamina = 0;
	if (stamina > stamina_max)
		stamina = stamina_max;
};
