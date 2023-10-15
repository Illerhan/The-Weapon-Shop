
#include "Character.h"

#include <iostream>

#include "Merchant.h"
#include "Weapon.h"

using namespace std;

Character::Character(const string& firstName,
	const string& m_description,
	const string& lastName,
	const string& catchphrase,
	double money,
	int healthPoint,
	vector<Attack*> m_attack,
	const int m_defense,
	const Weapon& m_equipped_weapon,
	const string& race,
	const string& classe,
	vector<Weapon> m_inventory): Creature(firstName,
		m_description,
		healthPoint,
		m_equipped_weapon,
		m_attack,
		m_defense)
{
	mFirstName = firstName;
	mLastName = lastName;
	mDescription = m_description;
	mCathchprase = catchphrase;
	mMoney = money;
	mHealthPoint = healthPoint;
	mEquippedWeapon = m_equipped_weapon;
	mInventory = m_inventory;
	mAttack = m_attack;
	mDefense = m_defense;
	mRace = race;
	mClasse = classe;
	
}

Character::~Character() = default;


	string Character::GetFirstName() { return mFirstName; }
	string Character::GetLastName() { return mLastName; }
	string Character::GetCathcphrase() { return mCathchprase; }
	vector<Weapon> Character::getInventory()
	{
		return mInventory;
	}
 
	double Character::GetMoney() { return mMoney; }
	int Character::GetHealthPoint() { return mHealthPoint; }
	Weapon Character::GetWeapon() { return mEquippedWeapon; }
	string Character::GetRace() { return mRace; }
	string Character::Getclass() { return mClasse; }

	void Character::SetMoney(double money) { mMoney = money; }
	void Character::SetWeapon(Weapon weapon) { mEquippedWeapon = weapon; }

	void Character::introduce() { cout << mCathchprase << endl; }
	void Character::sellingWeapon(Weapon weapon, Merchant merchant) {
		merchant.buyWeapon(weapon, *this);
	}

	void Character::buyingWeapon(Weapon weapon, Merchant merchant) {
		merchant.sellWeapon(weapon, *this);
	}

	void Character::addInventory(Weapon weapon)
	{
		mInventory.push_back(weapon);
	}

	/*void Character::takeDmg(int damageTaken) {
			mHealthPoint -= damageTaken;
			if (mHealthPoint <= 0) {
				mHealthPoint = 0;
				cout << mFirstName << " Was slain" << endl;
			}
		}*/
	void Character::useWeapon(Monster& enemy)
	{
	}
	void Character::loot(Monster &enemy) {
		Weapon getWeapon = enemy.lootWeapon();
		
		string answer;
		
		bool answered = false;
		if (getWeapon.GetType() & WeaponTypes::Empty)
		{
			return;
		}
		cout << "Would you like to take the " << getWeapon.GetName() << " ? (yes/no)" << endl;
			while (!answered) {
				cin >> answer;
				if (answer == "yes" || answer == "Yes") {
					addInventory(getWeapon);
					cout << "You have now " << getWeapon.GetName() << "in your inventory" << endl;
					answered = true;

				}
				else if (answer == "no" || answer == "No") {
					answered = true;
				}
				else {
					cout << "Please answer with yes or no" << endl;
				}
		}
	}
	/*void Character::useWeapon(Character& enemy) 
	{
		if (mHealthPoint > 0) {
			mWeapon.use();
			int damage = mWeapon.GetDamage();
			enemy.takeDmg(damage);
			cout <<mFirstName << " attacks " << enemy.GetFirstName() << " with " << mWeapon.GetName() << " for " << damage << " damage!" << endl;
		}
		else {
			cout << mFirstName << " is defeated and cannot attack." << endl;
		}

	};*/

