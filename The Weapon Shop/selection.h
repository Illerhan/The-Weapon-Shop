#pragma once
#include "Weapon.h"
#include "Character.h"

inline void selectWeapon(Weapon weapons[], Character& character) {
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
			character.SetWeapon(weapons[0]);
			selected = true;
			break;
		case 2:
			character.SetWeapon(weapons[1]);

			selected = true;
			break;
		case 3:
			character.SetWeapon(weapons[2]);

			selected = true;
			break;
		case 4:
			character.SetWeapon(weapons[3]);

			selected = true;
			break;
		case 5:
			character.SetWeapon(weapons[4]);
			selected = true;
			break;
		case 6:
			character.SetWeapon(weapons[5]);
			selected = true;
			break;
		default:

			cout << "Please select a number between 1 and 6" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			break;
		}
		cout << "You earned " << character.GetWeapon().GetName() << endl;
	}
}
