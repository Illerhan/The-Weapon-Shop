#pragma once
#include <string>
#include <vector>

#include "Weapon.h"

class Attack;


class Creature
{
public:
	Creature(const std::string& m_name,
		const std::string& m_description,
		int m_health_point,
		Weapon m_equipped_weapon,
		const std::vector<Attack*>& m_attack,
		int m_defense);
	Creature();

	void defineAttacks(Creature enemy);
	void attack(Creature enemy, Attack attack);
	int getDefense();
	int getHealthPoint();
	void takeDmg(int dmg);
	vector<Attack*> getAttack();

protected:
	std::string mName;
	std::string mDescription;
	int mHealthPoint;
	Weapon mEquippedWeapon;
	std::vector<Attack*> mAttack;
	int mDefense;

};

