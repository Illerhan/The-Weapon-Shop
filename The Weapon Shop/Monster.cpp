#include "Monster.h"


Monster::Monster(const string& m_name, const string& m_description, int m_health_point, const Weapon& m_equipped_weapon,
	const std::vector<Attack*>& m_attack, const int m_defense, vector<Weapon> m_loot): Creature(m_name,
	m_description,
	m_health_point,
	m_equipped_weapon,
	m_attack,
	m_defense)
{
	mLoot = m_loot;
}

Monster::~Monster() = default;

string Monster::getName()
{
	return mName;
}


Weapon Monster::lootWeapon()
{
	{
		Weapon randWeapon;
		srand(std::time(nullptr));
		int randValue = rand()%5;
		cout << "rand value " << randValue << endl;
		if (randValue == 0)
		{
			cout << "Nothing to loot here" << endl;
			randWeapon = Weapon("Hands",
				"Did you sell your weapons, or just lost it ? ",
				1,
				0,
				1,
				0,
				0);
		}
		else
		{
			randWeapon = mLoot[randValue];
			cout << "You can get " << randWeapon.GetName() << endl;
			cout << randWeapon.GetName();
		}
		return randWeapon;
	}

}
