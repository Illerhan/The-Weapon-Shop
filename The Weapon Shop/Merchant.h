#pragma once
#include "WeaponTypes.h"
#include "Weapon.h"
#include "Character.h"

class Merchant
{
	private:
		string mName;
		string mShopName;
		string mDescription;
		string mCatchphrase;
		int mMoney;
	public:
		Merchant(const std::string& name,
			const std::string& shopName,
			const std::string& description,
			const std::string& catchphrase,
			int money
			);

		int calculBuyingCost(Weapon& weapon);
		int calculSellPrice(Weapon& weapon);
		
		void sellWeapon(Weapon& weapon, Character& character);
		void buyWeapon(Weapon& weapon, Character& character);
		void getName();
		void getShopName();
};

