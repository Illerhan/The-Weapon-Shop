#pragma once
#include <string>

#include "Creature.h"
#include "Weapon.h"

class Monster :
    public Creature
{
private:
	Weapon mLoot;
public:
	Monster(const string& m_name,
		const string& m_description,
		int m_health_point,
		const Weapon& m_equipped_weapon,
		const std::vector<Attack*>& m_attack,
		const int m_defense,
		Weapon& m_loot)
		: Creature(m_name,
			m_description,
			m_health_point,
			m_equipped_weapon,
			m_attack,
			m_defense)

	{
	}
	
};

	

