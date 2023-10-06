#pragma once
#include "WeaponTypes.h"
#include "Weapon.h"

class Merchant;

class Character
{
	private:
		string mFirstName;
		string mLastName;
		string mCathchprase;
		double mMoney;
		int mHealthPoint;
		Weapon mWeapon;
		string mRace;
		string mClasse;
	public:
		Character(const string& firstName,
			const string& lastName,
			const string& catchphrase,
			double money,
			int healthPoint,
			const Weapon& weapon,
			const string& race,
			const string& classe);
		~Character();
		string GetFirstName();
		string GetLastName();
		string GetCathcphrase();
		double GetMoney();
		int GetHealthPoint();
		Weapon GetWeapon();
		string GetRace();
		string Getclass();
		void SetMoney(double money);
		void SetWeapon(Weapon weapon);

		void sellingWeapon(Weapon weapon, Merchant merchant);
		void buyingWeapon(Weapon mWeapon, Merchant merchant);

		void introduce();
		void takeDmg(int damageTaken);
		void useWeapon(Character& enemy);
		void loot(Character& enemy);

};

