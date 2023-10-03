// The Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Weapon.h"
#include "WeaponTypes.h"
#include "Character.h"

using namespace std;

int main()
{
	Weapon SkyStaff("Sky's Staff",
		"falen from the sky, near thunder impact, imbu with elements power",
		WeaponType::Staff,
		125.68,
		12,
		364,
		0.95);

	cout << SkyStaff.GetDamage() << endl;

	/*Character Merlin("Merlin",
		"Hugebeard",
		"Hi sire, time for some practice",
		125,
		150,
		SkyStaff,
		"Humain",
		"Mage");*/
}
