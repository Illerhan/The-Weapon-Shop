
#include <iostream>
#include "Weapon.h"
#include "WeaponTypes.h"

using namespace std;

Weapon::Weapon(std::string name,
	std::string descrition,
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
string Weapon::GetName() { return mName; }
string Weapon::GetDescription() { return mDescripton; }
WeaponType Weapon::GetType() { return mType; }
float Weapon::GetWeight() { return mWeight; }
int Weapon::GetDamage() { return mDamages; }
int Weapon::GetPrice() { return mPrice; }
float Weapon::GetDurability() { return mDurability; }

void Weapon::setDurability() {

}

