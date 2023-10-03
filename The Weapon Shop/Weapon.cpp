
#include <iostream>
#include "Weapon.h"
#include "WeaponTypes.h"

using namespace std;

Weapon::Weapon(const std::string& name,
	const std::string& descrition,
	WeaponType type,
	float weight,
	int damages,
	int price,
	float durability) {
	mName = name;
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mPrice = price;
	mDurability = durability;
}
Weapon::~Weapon() {}
const string& Weapon::GetName() { return mName; }
const string& Weapon::GetDescription() { return mDescripton; }
WeaponType Weapon::GetType() { return mType; }
float Weapon::GetWeight() { return mWeight; }
int Weapon::GetDamage() { return mDamages; }
int Weapon::GetPrice() { return mPrice; }
float Weapon::GetDurability() { return mDurability; }

void Weapon::use() {
	if (mDurability > 0.0) {
		mDurability -= 0.1;
	}
}

