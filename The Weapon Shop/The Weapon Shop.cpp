// The Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Attack.h"
#include "Weapon.h"
#include "Character.h"
#include "Merchant.h"
#include "selection.h"
#include "Creature.h"


#define MAX_CATCHPHRASE_LENGTH 60

using namespace std;

int main()
{

	Weapon weapons[6];
	weapons[0] = Weapon("Hands",
		"Did you sell your weapons, or just lost it ? ",
		1,
		0,
		1,
		0,
		0);

	weapons[1] = Weapon("Sky's Staff",
		"Fallen from the sky, near thunder impact, imbued with elements power",
		64,
		125.68,
		12,
		364,
		0.95);

	weapons[2] = Weapon("Wood Club",
		"A piece a wood used by ogre when they're mad",
		2,
		362.25,
		5,
		15,
		0.8);
	weapons[3] = Weapon("Thief Dagger",
		"Perfect for peoples who wanna stab without being caught",
		32,
		60.25,
		15,
		245,
		1.00
		);
	weapons[4] = Weapon("Eagle's bow",
		"Better than a Oak, but without the arrows",
		8,
		110,
		26,
		548,
		0.4
	);
	weapons[5] = Weapon("Frostmourne",
		"As cold as the lich King's heart, it will froze all your ennemy",
		4,
		496,
		60,
		1200,
		1.0);

	Attack Smash("Smash", 15 ,AttackType::Bludgeoning, 4);
	Attack FireBlade("Fire blade",  24, AttackType::Burning, 2);
	Attack BackStabe("Backstabe",  12, AttackType::Piercing, 8);
	Attack FireBolt("FireBolt",  34, AttackType::Burning, 8);
	Attack TrueShot("PoisonShot", 16, AttackType::Poisoning, 4);
	Attack Punch("FireBolt",  8, AttackType::Bludgeoning, 7);
	Attack Pierce("Pierce", 20, AttackType::Piercing, 9);
	vector<Attack*> Attacks;
	Attacks.push_back(&Smash);
	Attacks.push_back(&FireBlade);
	Attacks.push_back(&BackStabe);
	Attacks.push_back(&FireBolt);
	Attacks.push_back(&TrueShot);
	Attacks.push_back(&Punch);
	Attacks.push_back(&Pierce);
	vector<Weapon> inventory;

	string firstName;
	string lastName;
	char catchphrase[MAX_CATCHPHRASE_LENGTH];
	cout << "Enter your character first name" << endl;
	cin >> firstName;
	cout << "Enter your character last name" << endl;
	cin >> lastName;
	cout << "Enter your character catchphrase (max 60 char)" << endl;
	cin.ignore();
	cin.getline(catchphrase,MAX_CATCHPHRASE_LENGTH);


	Character Player(firstName,
		"Powerfull mage",
		lastName,
		catchphrase,
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

	selectWeapon(weapons, Player);
	
	cout << Player.GetFirstName() << " : " << endl;
	Player.introduce();
	cout << Shrek.GetFirstName() << " : " << endl;
	Shrek.introduce();
	Player.useWeapon(Shrek);
	Player.loot(Shrek);
	cout << Player.GetWeapon().GetName() << endl;
	Player.defineAttacks(Shrek);
	
	if(Player.getInventory().size()>0){
		cout << "you have " << Player.getInventory().at(0).GetName() << endl;
	}
	cout << Amazon.getName() << " : " << endl;
	Amazon.introduce();
	Player.buyingWeapon(weapons[1], Amazon);
	Player.sellingWeapon(Player.GetWeapon(), Amazon);

	
}
	
