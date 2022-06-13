#include "MemeFighter.h"
#include <iostream>

MemeFighter::MemeFighter(const std::string& name, int hp, int power, int speed)
	:
	hp(hp),
	power(power),
	speed(speed)
{
	this->name = name;
}

std::string MemeFighter::GetName() const
{
	return name;
}

int MemeFighter::GetInitiative(Dice& dice) const
{
	return speed + dice.Roll(2);
}

bool MemeFighter::IsAlive() const
{
	return hp>0;
}

void MemeFighter::GetDamage(int damage)
{
	hp-=damage;
}

void MemeFighter::Punch(MemeFighter& fighter, Dice& dice) const
{
	int damage = power + dice.Roll(2);
	std::cout << name + " Punches " << fighter.GetName() << " and deals " << damage << " of damage" << std::endl;
	if (fighter.IsAlive())
	{
		fighter.GetDamage(damage);
	}
	else
	{
		std::cout << "But " << fighter.GetName() << " is already dead!!" << std::endl;
	}
	
}

void MemeFighter::Tick(Dice& dice)
{
	int recover = dice.Roll(1);
	std::cout << name + " heals " << recover << " hp" << std::endl;
	hp += recover;
}

MemeFrog::MemeFrog(const  std::string& name)
	:
	MemeFighter(name, 69, 14, 7)
{
	
}

MemeStoner::MemeStoner(const std::string& name)
	:
	MemeFighter(name, 80, 10, 4)
{
	
}

void MemeStoner::SpecialMove(Dice& dice)
{
	std::cout << name + " tries a special move " << std::endl;
	if (dice.Roll(1) <= 2)
	{
		speed += 2;
		power += 2;
		hp += 10;
		name = "Super " + name;
		std::cout << "and became " << name << std::endl;
	}
	else
	{
		std::cout <<"But had no luck " << std::endl;
	}
}

void MemeFrog::SpecialMove(MemeFighter& fighter, Dice& dice)
{
	std::cout << name + " tries a special move " << std::endl;
	if (dice.Roll(1) <= 3)
	{
		int damage = 20 + dice.Roll(3);
		std::cout << "and makes " << damage << " of damage" << std::endl;
		if (fighter.IsAlive())
		{
			fighter.GetDamage(damage);
		}
		else
		{
		std::cout << "But " << fighter.GetName() << " is already dead!!" << std::endl;
		}
	}
	else
	{
		std::cout << "But had no luck " << std::endl;
	}
}