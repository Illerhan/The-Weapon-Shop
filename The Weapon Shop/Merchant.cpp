#include <iostream>
#include "Merchant.h"


Merchant::Merchant(const string& name,
	const string& shopName,
	const string& description,
	const string& catchphrase,
	int money) 
	{
		mName = name;
		mShopName = shopName;
		mDescription = description;
		mCatchphrase = catchphrase;
		mMoney = money;
	}
		string Merchant::getName() { return mName; }
		string Merchant::getShopName() { return mShopName; }
		void Merchant::introduce() {
			cout << "Hi traveler i'm " << Merchant::getName() << " I hope tou will find everything you need in " << Merchant::getShopName() << endl;
		};

		int Merchant::calculBuyingCost(Weapon& weapon)
			{
				return (weapon.GetPrice() *  weapon.GetDurability());
			};
		int Merchant::calculSellPrice(Weapon& weapon)
			{
			return (weapon.GetPrice() * (0.20 + weapon.GetDurability()));
			};

		void Merchant::sellWeapon(Weapon& weapon, Character& character) {
			int cost = calculSellPrice(weapon);
			if (character.GetMoney() >= cost) {
				character.SetMoney((character.GetMoney() - cost));
				cout << "You bought " << weapon.GetName() << " for " << cost << endl;
			}
			else {
				cout << "You don't have enough money for this weapon" << endl;
			}
		}
		void Merchant::buyWeapon(Weapon& weapon, Character& character){
			int cost = calculBuyingCost(weapon);
			character.SetMoney((character.GetMoney() + cost));
			cout << "You sold " << weapon.GetName() << " for " << cost << " too " << Merchant::getName() << endl;
		
		}