#pragma once
#include "WeaponTypes.h"
#include "Weapon.h"
#include "Creature.h"
 
class Merchant;

class Character :
	public Creature
{
	private:
		string mFirstName;
		string mLastName;
		string mCathchprase;
		double mMoney;
		string mRace;
		string mClasse;
		vector<Weapon*> mInventory;

	public:
		Character(const string& firstName,
			const string& m_description,
			const string& lastName,
			const string& catchphrase,
			double money, int healthPoint,
			vector<Attack*> m_attack, 
			const int m_defense,
			const Weapon& m_equipped_weapon,
			const string& race,
			const string& classe,
			vector<Weapon*> m_inventory) ;

		Character();


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

