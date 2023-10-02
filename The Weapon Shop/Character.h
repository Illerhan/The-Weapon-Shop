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
		Character(std::string firstName,
			std::string lastName,
			std::string catchphrase,
			float money,
			int healthPoint,
			WeaponType type,
			std::string race,
			std::string classe);
		~Character();
		string GetFirstName();
		string GetLastName();
		string GetCathcphrase();
		float GetMoney();
		int GetHealthPoint();
		Weapon GetWeapon();
		string GetRace();
		string Getclass();

		void introduce();
		void takeDmg(float damageTaken);
		void buyWeapon(Weapon type, int price);
		void sellWeapon(Weapon type, int price);
		void useWeapon();
		void lootMoney();
		void lootWeapon();

};

