#include "Attack.h"

#include <iostream>

#include "Creature.h"

using namespace std;

Attack::Attack(const std::string& m_name,  int m_dmg, const AttackType& m_type, int m_bonus)
	: mName(m_name),

	mDmg(m_dmg),
	mType(m_type),
	mBonus(m_bonus){}

	std::string Attack::getName()
	{
		return mName;
	}


	int Attack::getDmg()
	{
		return mDmg;
	};

	int Attack::bonusCalculation(int diceSize = 20){
		int dice;
		srand(std::time(nullptr));
		dice = (rand() % diceSize) + 1;
		cout << "You rolled dice and get " << dice << endl;
		return dice;
	};

	void Attack::doesHit(int dmg, Creature &enemy)
	{
		int attack = dmg + bonusCalculation();
		if (attack >= enemy.getDefense())
		{
			enemy.takeDmg(attack);
			cout << "Enemy took " << attack << " and now have " << enemy.getHealthPoint() << ".\n";
		} else
		{
			cout << "You missed the enemy.\n";
		}
	}