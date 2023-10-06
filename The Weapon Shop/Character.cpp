
#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Merchant.h"
#include "Selection.cpp"

using namespace std;

Character::Character(const string& firstName,
	const string& lastName,
	const string& catchphrase,
	double money,
	int healthPoint,
	const Weapon& weapon,
	const string& race,
	const string& classe)
	{
		mFirstName = firstName;
		mLastName = lastName;
		mCathchprase = catchphrase;
		mMoney = money;
		mHealthPoint = healthPoint;
		mWeapon = weapon;
		mRace = race;
		mClasse = classe;

	}
	Character::~Character() {}

	string Character::GetFirstName() { return mFirstName; }
	string Character::GetLastName() { return mLastName; }
	string Character::GetCathcphrase() { return mCathchprase; }
	double Character::GetMoney() { return mMoney; }
	int Character::GetHealthPoint() { return mHealthPoint; }
	Weapon Character::GetWeapon() { return mWeapon; }
	string Character::GetRace() { return mRace; }
	string Character::Getclass() { return mClasse; }

	void Character::SetMoney(double money) { mMoney = money; }
	void Character::SetWeapon(Weapon weapon) { mWeapon = weapon; }

	void Character::introduce() { cout << mCathchprase << endl; }
	void Character::sellingWeapon(Weapon weapon, Merchant merchant) {
		merchant.buyWeapon(weapon, *this);
	}

	void Character::buyingWeapon(Weapon weapon, Merchant merchant) {
		merchant.sellWeapon(weapon, *this);
	}
	
	void Character::takeDmg(int damageTaken) {
		mHealthPoint -= damageTaken;
		if (mHealthPoint <= 0) {
			mHealthPoint = 0;
			cout << mFirstName << " Was slain" << endl;
		}
	}
	void Character::loot(Character& enemy) {
		mMoney += enemy.GetMoney();
		cout << "You earned " << enemy.GetMoney() << " golds." << endl;
		enemy.SetMoney(0);
		cout << "Would you like to take the " << enemy.GetWeapon().GetName() << " ? (yes/no)" << endl;
		string answer;
		
		bool answered = false;
		while(!answered){

			cin >> answer;
			if (answer == "yes" || answer == "Yes") {
				mWeapon = enemy.GetWeapon();
				enemy.SetWeapon(Weapon("Hands", "No weapon equiped", WeaponType::Empty, 0.0, 0, 0, 0.0));
				answered = true;
				cout << "You have now " << mWeapon.GetName() << endl;
			}
			else if (answer == "no" || answer == "No") {
				answered = true;
			}
			else {
				cout << "Please answer with yes or no" << endl;
			}
		} 
	}
	void Character::useWeapon(Character& enemy) 
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

	};

