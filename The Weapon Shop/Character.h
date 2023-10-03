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
		class Weapon mWeapon;
		std::string mRace;
		std::string mClasse;
	public:
		Character(std::string firstName,
			std::string lastName,
			std::string catchphrase,
			float money,
			int healthPoint,
			class Weapon weapon,
			std::string race,
			std::string classe);
		~Character();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetCathcphrase();
		float GetMoney();
		int GetHealthPoint();
		Weapon GetWeapon();
		std::string GetRace();
		std ::string Getclass();

		void introduce();
		void takeDmg(float damageTaken);
		void buyWeapon(Weapon type, int price);
		void sellWeapon(Weapon type, int price);
		void useWeapon();
		void lootMoney();
		void lootWeapon();

};

