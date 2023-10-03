#include <iostream>
#include "Merchant.h"

using namespace std;

Merchant::Merchant(const std::string& name,
	const std::string& shopName,
	const std::string& description,
	const std::string& catchphrase,
	int money) 
	{
		mShopName = shopName;
		mDescription = description;
		mCatchphrase = catchphrase;
		mMoney = money;
	}


		int Merchant::calculBuyingCost(Weapon& weapon)
			{
				return (weapon.GetPrice() * (1 - weapon.GetDurability()));
			};
		int Merchant::calculSellPrice(Weapon& weapon)
			{
			return (weapon.GetPrice() * (1 + weapon.GetDurability()));
			};

		void Merchant::sellWeapon(Weapon& weapon, Character& character) {
			int cost = calculSellPrice(weapon);
			if (character.GetMoney() >= cost) {
				character.SetMoney((character.GetMoney() - cost));
			}
			else {
				cout << "You don't have enough money for this weapon" << endl;
			}
		}
		void Merchant::buyWeapon(Weapon& weapon, Character& character){
			int cost = calculBuyingCost(weapon);
			character.SetMoney((character.GetMoney() + cost));
			weapon = Weapon("Hands", "No weapon equiped", WeaponType::Empty, 0.0, 0, 0, 0.0);
			cout << "You brought " << weapon.GetName() << " for " << cost << " from " << character.GetFirstName() << endl;
		}