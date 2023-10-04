// The Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Weapon.h"
#include "WeaponTypes.h"
#include "Character.h"
#include "Merchant.h"

using namespace std;

int main()
{
	Weapon weapons[6];
	weapons[0] = Weapon("Hands",
		"Did you sell your weaons, or just lost it ? ",
		WeaponType::Empty,
		0,
		1,
		0,
		0);

	weapons[1] = Weapon("Sky's Staff",
		"falen from the sky, near thunder impact, imbu with elements power",
		WeaponType::Staff,
		125.68,
		12,
		364,
		0.95);

	weapons[2] = Weapon("Wood Club",
		"A piece a wood used by oger when they're mad",
		WeaponType::OneHSword,
		362.25,
		5,
		15,
		0.8);
	weapons[3] = Weapon("Thief Dagger",
		"Perfect for peaople who wanna stab withour being cought",
		WeaponType::Dagger,
		60.25,
		15,
		245,
		1.00
		);
	weapons[4] = Weapon("Eagle's bow",
		"Better than a Oak, but without the arrows",
		WeaponType::Bow,
		110,
		26,
		548,
		0.4
	);
	weapons[5] = Weapon("Frostmourne",
		"As cold as the lich King's heart, it will froze all your ennemy",
		WeaponType::TwoHSword,
		496,
		60,
		1200,
		1.0);

	Character Merlin("Merlin",
		"Hugebeard",
		"Hi sire, time for some practice",
		500,
		125,
		weapons[1],
		"Human",
		"Mage");
	
	Character Shrek("Shrek",
		"",
		"ME, heating HUMAN",
		250,
		10,
		weapons[2],
		"Ogre",
		"War");

	Merchant Amazon("Jeff",
		"Amazon", 
		"The blacksmith where you can find anything you want",
		"How can i help you non-online visitor ?",
		1000);

	cout << "Choose a weapon in this list between 1 and 6" << endl;

	for (int i = 0; i < 6; i++) {

		cout << weapons[i].GetName() << " - " << weapons[i].GetDescription() << " - Dmg -> " << weapons[i].GetDamage() << endl;
	};

	
	bool selected = false;
	
	while (!selected) {
		int choose;
		cin >> choose;
		switch (choose)
			{
			case 1:
				Merlin.SetWeapon(weapons[0]);
				selected = true;
				break;
			case 2:
				Merlin.SetWeapon(weapons[1]);
				selected = true;
				break;
			case 3:
				Merlin.SetWeapon(weapons[2]);
				selected = true;
				break;
			case 4:
				Merlin.SetWeapon(weapons[3]);
				selected = true;
				break;
			case 5:
				Merlin.SetWeapon(weapons[4]);
				selected = true;
				break;
			case 6:
				Merlin.SetWeapon(weapons[5]);
				selected = true;
				break;
			default:
				
				cout << "Please select a number between 1 and 6" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
	}
	
	cout << Merlin.GetFirstName() << " : " << endl;
	Merlin.introduce();
	cout << Shrek.GetFirstName() << " : " << endl;
	Shrek.introduce();
	Merlin.useWeapon(Shrek);
	Merlin.loot(Shrek);

	cout << Amazon.getName() << " : " << endl;
	Amazon.introduce();
	Merlin.buyingWeapon(weapons[1], Amazon);
	Merlin.sellingWeapon(Merlin.GetWeapon(), Amazon);

	
}
	
