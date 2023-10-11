// The Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Attack.h"
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
		"A piece a wood used by ogre when they're mad",
		WeaponType::OneHSword,
		362.25,
		5,
		15,
		0.8);
	weapons[3] = Weapon("Thief Dagger",
		"Perfect for peoples who wanna stab without being caught",
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

	Attack Smash("Smash", weapons[2], 15 ,AttackType::Bludgeoning, 4);
	Attack FireBlade("Fire blade", weapons[5], 24, AttackType::Burning, 2);
	Attack BackStabe("Backstabe", weapons[3], 12, AttackType::Piercing, 8);
	Attack FireBolt("FireBolt", weapons[1], 34, AttackType::Burning, 8);
	vector<Attack*> Attacks;
	Attacks.push_back(&Smash);
	Attacks.push_back(&FireBlade);
	Attacks.push_back(&BackStabe);
	Attacks.push_back(&FireBolt);
	vector<Weapon> inventory;

	Character Merlin("Merlin",
		"Powerfull mage",
		"Hugebeard",
		"Hi sire, time for some practice",
		250,
		450,
		Attacks,
		12,
		weapons[1],
		"Human",
		"Mage",
		inventory
		);
	
	
	Character Shrek("Shrek",
		"A really bad guy",
		"",
		"ME, heating HUMAN",
		24,
		300,
		Attacks,
		15,
		weapons[2],
		"Ogre",
		"War",
		inventory);

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
	cout << "you have " << Merlin.getInventory().at(0).GetName() << endl;

	cout << Amazon.getName() << " : " << endl;
	Amazon.introduce();
	Merlin.buyingWeapon(weapons[1], Amazon);
	Merlin.sellingWeapon(Merlin.GetWeapon(), Amazon);

	
}
	
