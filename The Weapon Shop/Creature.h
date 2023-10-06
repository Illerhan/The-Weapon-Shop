#pragma once
#include <string>
#include <vector>

class Attack;


class Creature
{
public:
	Creature(const std::string& m_name, const std::string& m_description, int m_health_point, const std::vector<Attack>& m_attack,
		int m_defense);
	void attack(Creature enemy, Attack attack);
	int getDefense();
	int getHealthPoint();
	void takeDmg(int dmg);

private:
	std::string mName;
	std::string mDescription;
	int mHealthPoint;
	std::vector<Attack> mAttack;
	int mDefense;

};

