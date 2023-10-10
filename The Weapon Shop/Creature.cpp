#include "Creature.h"

#include "Attack.h"

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

int Creature::getDefense()
{
	return mDefense;
}

int Creature::getHealthPoint()
{
	return mHealthPoint;
}

void Creature::takeDmg(int dmg)
{
	mHealthPoint -= dmg;
}

void Creature::attack(Creature enemy, Attack attack)
{
	attack.doesHit(attack.getDmg(), enemy);
}
