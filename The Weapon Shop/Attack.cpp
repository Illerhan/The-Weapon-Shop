#include "Attack.h"

#include <iostream>

#include "Creature.h"

using namespace std;

Attack::Attack(const std::string& m_name, const Weapon& m_weapon, int m_dmg, const AttackType& m_type, int m_bonus)
	: mName(m_name),
	mWeapon(m_weapon),
	mDmg(m_dmg),
	mType(m_type),
	mBonus(m_bonus)
{
}
	int Attack::getDmg()
	{
		return mDmg;
	};

	int Attack::bonusCalculation(int diceSize = 20){
		int dice;
		dice = (rand() % diceSize) + 1;
		cout << "You rolled dice and get " << dice << endl;
		return dice;
	};

	void Attack::doesHit(int dmg, Creature enemy)
	{
		int attack = dmg + bonusCalculation();
		if (attack >= enemy.getDefense())
		{
			enemy.takeDmg(dmg);
			cout << "Enemy took " << dmg << " and now have " << enemy.getHealthPoint() << ".\n";
		} else
		{
			cout << "You missed the enemy";
		}
	}