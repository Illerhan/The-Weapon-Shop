#pragma once
#include <iostream>
#include <ostream>
#include <string>

#include "Creature.h"
#include "Weapon.h"

class Monster :
    public Creature
{
private:
	vector<Weapon> mLoot;
public:
	Monster(const string& m_name,
		const string& m_description,
		int m_health_point,
		const Weapon& m_equipped_weapon,
		const std::vector<Attack*>& m_attack,
		const int m_defense,
		vector<Weapon> m_loot);

	~Monster();
	Weapon lootWeapon();
	string getName();
};




	

