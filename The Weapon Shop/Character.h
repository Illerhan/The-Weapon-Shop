#pragma once
#include "WeaponTypes.h"
#include "Merchant.h"
class Character
{
	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mCathchprase;
		float mMoney;
		int mHealthPoint;
		Weapon mWeapon;
		std::string mRace;
		std::string mClasse;
	public:
		Character(const std::string& firstName,
			const std::string& lastName,
			const std::string& catchphrase,
			float money,
			int healthPoint,
			const Weapon& weapon,
			const std::string& race,
			const std::string& classe);
		~Character();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetCathcphrase();
		float GetMoney();
		int GetHealthPoint();
		Weapon GetWeapon();
		std::string GetRace();
		std ::string Getclass();
		void SetMoney(int money);
		void SetWeapon(Weapon weapon);

		void introduce();
		void buyWeaponFromMerchant(Merchant& merchant, Weapon& weaponToBuy);
		void sellWeaponToMerchant(Merchant& merchant);
		void takeDmg(float damageTaken);
		void useWeapon(Character& enemy);
		void loot(Character& enemy);

};

