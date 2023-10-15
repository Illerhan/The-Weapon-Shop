#include "Creature.h"

#include <codecvt>
#include <iostream>

#include "Attack.h"
#include "selectAttacks.h"

using namespace std;

Creature::Creature(const string& m_name, const string& m_description, int m_health_point, Weapon m_equipped_weapon ,const std::vector<Attack*>& m_attack,
	int m_defense) :
	mName(m_name),
	mDescription(m_description),
	mHealthPoint(m_health_point),
	mEquippedWeapon(m_equipped_weapon),
	mAttack(m_attack),
	mDefense(m_defense)
{

}


void Creature::defineAttacks(Creature& enemy)
{
	uint8_t type = mEquippedWeapon.GetType();

	vector<Attack*> availableAttacks = selectAttacks(type,getAttack());
	int count = availableAttacks.size();
	int selectedAttack;

	bool selected = false;
	
	while (!selected) {
		cin >> selectedAttack;
		switch (selectedAttack)
		{
		case 1:
			availableAttacks.at(0)->doesHit(availableAttacks.at(0)->getDmg(), enemy);
			selected = true;
			break;
		case 2:
			availableAttacks.at(1)->doesHit(availableAttacks.at(1)->getDmg(), enemy);
			selected = true;
			break;
		case 3:
			availableAttacks.at(2)->doesHit(availableAttacks.at(2)->getDmg(), enemy);
			selected = true;
			break;
		default:
			cout << "Please only use numbers betwean 1 and " << count << endl;
			cin.clear();
			cin.ignore(256, '\n');
			break;
		}
	}
}


int Creature::getDefense()
{
	return mDefense;
}

int Creature::getHealthPoint()
{
	return mHealthPoint;
}

void Creature::setHealthPoint(int value){
	mHealthPoint -= value;
}


void Creature::takeDmg(int dmg)
{
	mHealthPoint -= dmg;
	if (mHealthPoint <= 0) {
		mHealthPoint = 0;
		cout << mName << " Was slain" << endl;
	};
}

vector<Attack*> Creature::getAttack()
{
	return mAttack;
}

void Creature::attack(Creature &enemy, Attack attack)
{
	attack.doesHit(attack.getDmg(), enemy);
}
