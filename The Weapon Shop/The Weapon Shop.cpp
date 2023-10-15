// The Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Attack.h"
#include "Weapon.h"
#include "Character.h"
#include "Merchant.h"
#include "selection.h"
#include "Creature.h"
#include "Monster.h"


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
	Attack Punch("Punch",  8, AttackType::Bludgeoning, 7);
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
	vector<Weapon> loot{weapons[1],weapons[2] ,weapons[3] ,weapons[4] ,weapons[5] };

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
	
	
	Monster Shrek("Shrek",
		"A really bad guy",		
		300,		
		weapons[2],		
		Attacks,		
		15,
		loot);

	Merchant Amazon("Jeff",
		"Amazon", 
		"The blacksmith where you can find anything you want",
		"How can i help you non-online visitor ?",
		1000);

	selectWeapon(weapons, Player);
	
	cout << Player.GetFirstName() << " : " << endl;
	Player.introduce();
	cout <<  Shrek.getName() << " wanna fight. " << endl;
	while (Player.GetHealthPoint() > 0 || Shrek.getHealthPoint() > 0)
	{
		Player.defineAttacks(Shrek);
		Shrek.defineAttacks(Player);
	};

	Player.loot(Shrek);

	if (!Player.getInventory().empty()) {
		cout << "You have :" << endl;
		for (int i = 0; i < Player.getInventory().size(); ++i)
		{
			cout << Player.getInventory().at(i).GetName() << endl;
		}

	};

	cout << Amazon.getName() << " : " << endl;
	Amazon.introduce();
	Player.buyingWeapon(weapons[1], Amazon);
	Player.sellingWeapon(Player.GetWeapon(), Amazon);

	
}
	
