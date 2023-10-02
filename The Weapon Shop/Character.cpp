#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(std::string firstName,
	std::string lastName,
	std::string catchphrase,
	float money,
	int healthPoint,
	WeaponType type,
	std::string race,
	std::string classe)
	{
		mFirstName = firstName;
		mLastName = lastName;
		mCathchprase = catchphrase;
		mMoney = money;
		mHealthPoint = healthPoint;
		mType = type;
		mRace = race;
		mClasse = classe;

	}
Character::~Character() {}
string Character::GetFirstName() { return mFirstName; }
string Character::GetLastName() { return mLastName; }
string Character::GetCathcphrase() { return mCathchprase; }
float Character::GetMoney() { return mMoney; }
int Character::GetHealthPoint() { return mHealthPoint; }
WeaponType Character::GetWeapon() { return mType; }
string Character::GetRace() { return mRace; }
string Character::Getclass() { return mClasse; }

void Character::introduce() { cout << mCathchprase << endl; }
void Character::takeDmg(float damageTaken) {
	mHealthPoint -= damageTaken;
}
void Character::buyWeapon(WeaponType type, int price) {
}
void Character::sellWeapon(WeaponType type, int price) {}
void Character::useWeapon() {}
void Character::lootMoney() {}
void Character::lootWeapon() {}

