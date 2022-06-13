#pragma once
#include<string>
#include "Dice.h"

class MemeFighter
{

public:
	MemeFighter() = default;
	MemeFighter(const std::string& name, int hp, int power, int speed);
	std::string GetName() const;
	int GetInitiative(Dice& dice) const;
	bool IsAlive() const;
	void GetDamage(int damage);
	void Punch(MemeFighter& fighter, Dice& dice) const;
	void Tick(Dice& dice);
protected:
	std::string name;
	int hp;
	int power;
	int speed;
};

class MemeFrog : public MemeFighter
{
public:
	MemeFrog(const  std::string& name);
	void SpecialMove(MemeFighter& figther, Dice& dice);
private:
	
};

class MemeStoner : public MemeFighter
{
public:
	MemeStoner(const  std::string& name);
	void SpecialMove(Dice& dice);
private:

};