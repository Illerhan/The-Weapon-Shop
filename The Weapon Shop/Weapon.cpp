
#include <iostream>
#include "Weapon.h"
#include "WeaponTypes.h"


using namespace std;

Weapon::Weapon(const string& name,
	const string& description,
	WeaponType type,
	double weight,
	int damages,
	int price,
	double durability)
{
	mName = name;
	mDescription = description;
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mPrice = price;
	mDurability = durability;
}
Weapon::Weapon()
{
	mName = "Hands";
	mDescription = "You don't wear weapon";
	mType = WeaponType::Empty;
	mWeight = 0;
	mDamages = 0;
	mPrice = 0;
	mDurability = 0;
}
Weapon::~Weapon() {}
const string& Weapon::GetName() { return mName; }
const string& Weapon::GetDescription() { return mDescription; }
WeaponType Weapon::GetType() { return mType; }
double Weapon::GetWeight() { return mWeight; }
int Weapon::GetDamage() { return mDamages; }
int Weapon::GetPrice() { return mPrice; }
double Weapon::GetDurability() { return mDurability; }

void Weapon::use() {
	if (mDurability > 0.0) {
		mDurability -= 0.1;
	}
}

