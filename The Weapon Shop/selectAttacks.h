#pragma once
#include <cstdint>
#include <iostream>

#include "Creature.h"
#include "WeaponTypes.h"
#include "Attack.h"

inline vector<Attack*> selectAttacks(uint8_t type, vector<Attack*> attacks)
{
	vector<Attack*> availableAttacks;
	cout << "Select an attack :" << endl;
	int count = 0;
	if ((type & (WeaponTypes::Dagger | WeaponTypes::TwoHSword | WeaponTypes::OneHSword |  WeaponTypes::Lance)))
	{
		
		count++;
		std::cout << count << " : " << attacks.at(1)->getName() << std::endl;
		availableAttacks.push_back(attacks.at(1));
	}
	if ((type & (WeaponTypes::TwoHSword | WeaponTypes::OneHSword | WeaponTypes::Staff)))
	{
		count++;
		std::cout << count << " : " << attacks.at(0)->getName() << std::endl;
		availableAttacks.push_back(attacks.at(0));
	}
	if ((type & (WeaponTypes::Bow |WeaponTypes::Gun)))
	{
		count++;
		std::cout << count << " : " << attacks.at(4)->getName() << std::endl;
		availableAttacks.push_back(attacks.at(4));

	}
	if (type & WeaponTypes::Dagger) {
		{
			count++;
			std::cout << count << " : " << attacks.at(2)->getName() << std::endl;
			availableAttacks.push_back(attacks.at(2));
		}
	}
	if (type & WeaponTypes::Staff) {
		{
			count++;
			std::cout << count << " : " << attacks.at(3)->getName() << std::endl;
			availableAttacks.push_back(attacks.at(3));
		}
	}
	if (type & WeaponTypes::Empty) {
		{
			count++;
			std::cout << count << " : " << attacks.at(5)->getName() << std::endl;
			availableAttacks.push_back(attacks.at(5));
		}
	}
	if (type & WeaponTypes::Lance) {
		{
			count++;
			std::cout << count << " : " << attacks.at(6)->getName() << std::endl;
			availableAttacks.push_back(attacks.at(6));
		}
	}

	return availableAttacks;
}
