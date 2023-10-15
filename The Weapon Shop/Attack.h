#pragma once
#include "AttackType.h"
#include "Weapon.h"
#include "Creature.h"

class Attack
{
public:
	Attack(const std::string& m_name, int m_dmg, const AttackType& m_type, int m_bonus);

	int getDmg();
	int  bonusCalculation(int mDmg);
	void doesHit(int dmg, Creature &enemy);
	std::string getName();

private:
	std::string mName;
	int mDmg;
	AttackType mType;
	int mBonus;

};

