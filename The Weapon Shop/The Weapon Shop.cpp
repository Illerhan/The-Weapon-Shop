// The Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Weapon.h"
#include "WeaponTypes.h"
#include "Character.h"
#include "Merchant.h"
#include "selection.h"
#include "Creature.h"

using namespace std;

int main()
{
	Weapon weapons[6];
	weapons[0] = Weapon("Hands",
		"Did you sell your weapons, or just lost it ? ",
		WeaponType::Empty,
		0,
		1,
		0,
		0);

	weapons[1] = Weapon("Sky's Staff",
		"Fallen from the sky, near thunder impact, imbued with elements power",
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
		"Perfect for peoples who wanna stab without being cought",
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
		"As cold as the liche King's heart, it will froze all your ennemy",
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

	selectWeapon(weapons, Merlin);
	
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
	
