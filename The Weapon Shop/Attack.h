#pragma once
#include "AttackType.h"
#include "Weapon.h"
#include "Creature.h"

class Attack
{
public:
	Attack(const std::string& m_name, const Weapon& m_weapon, int m_dmg, const AttackType& m_type, int m_bonus);

	int getDmg();
	int  bonusCalculation(int mDmg);
	void doesHit(int dmg, Creature enemy);

private:
	std::string mName;
	Weapon mWeapon;
	int mDmg;
	AttackType mType;
	int mBonus;

};

