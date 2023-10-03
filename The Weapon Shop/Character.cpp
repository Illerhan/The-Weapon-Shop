#include <iostream>
#include "Character.h"
#include "Weapon.h"

using namespace std;

Character::Character(std::string firstName,
	std::string lastName,
	std::string catchphrase,
	float money,
	int healthPoint,
	class Weapon weapon,
	std::string race,
	std::string classe)
	{
		mFirstName = firstName;
		mLastName = lastName;
		mCathchprase = catchphrase;
		mMoney = money;
		mHealthPoint = healthPoint;
		Weapon mWeapon = weapon;
		mRace = race;
		mClasse = classe;

	}
Character::~Character() {}
string Character::GetFirstName() { return mFirstName; }
string Character::GetLastName() { return mLastName; }
string Character::GetCathcphrase() { return mCathchprase; }
float Character::GetMoney() { return mMoney; }
int Character::GetHealthPoint() { return mHealthPoint; }
class Weapon Character::GetWeapon() { return mWeapon; }
string Character::GetRace() { return mRace; }
string Character::Getclass() { return mClasse; }

void Character::introduce() { cout << mCathchprase << endl; }
void Character::takeDmg(float damageTaken) {
	mHealthPoint -= damageTaken;
}
void Character::buyWeapon(class Weapon mWeapon, int mPrice) {
}
void Character::sellWeapon(class Weapon mWeapon, int mPrice) {}
void Character::useWeapon() {}
void Character::lootMoney() {}
void Character::lootWeapon() {}

