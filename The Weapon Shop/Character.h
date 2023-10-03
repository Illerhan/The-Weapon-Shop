#pragma once
#include "WeaponTypes.h"
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

		void introduce();
		void takeDmg(float damageTaken);
		void buyWeapon(Weapon type, int price);
		void sellWeapon(Weapon type, int price);
		void useWeapon();
		void lootMoney();
		void lootWeapon();

};

