#include <iostream>
#include "Character.h"
#include "Weapon.h"

using namespace std;

Character::Character(const std::string& firstName,
	const std::string& lastName,
	const std::string& catchphrase,
	float money,
	int healthPoint,
	const Weapon& weapon,
	const std::string& race,
	const std::string& classe)
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
	float Character::GetMoney() { return mMoney; }
	int Character::GetHealthPoint() { return mHealthPoint; }
	Weapon Character::GetWeapon() { return mWeapon; }
	string Character::GetRace() { return mRace; }
	string Character::Getclass() { return mClasse; }

	void Character::SetMoney(int money) { mMoney = money; }
	void Character::SetWeapon(Weapon weapon) { mWeapon = weapon; }

	void Character::introduce() { cout << mCathchprase << endl; }
	void  Character::buyWeaponFromMerchant(Merchant& merchant, Weapon& weaponToBuy)
	{ 
		int cost = merchant.calculBuyingCost(weaponToBuy);
		if (mMoney >= cost) {
			mMoney -= cost;
			merchant.sellWeapon(weaponToBuy, *this);
			mWeapon = weaponToBuy;
			cout << "Bought " << weaponToBuy.GetName() << " from " << merchant.getName() << " for " << cost << " gold coins." << endl;
		}
		else {
			cout << "Not enough money to buy " << weaponToBuy.GetName() << " from " << merchant.getName() << "." << endl;
		}
	};
	void  Character::sellWeaponToMerchant(Merchant& merchant)
	{
		int cost = merchant.calculSellPrice(mWeapon);
		mMoney += cost;
		cout << "Sold " << mWeapon.GetName() << " to " << merchant.getName() << " for " << cost << " gold coins." << endl;
		merchant.buyWeapon(mWeapon, *this);
		
		
	};
	void Character::takeDmg(float damageTaken) {
		mHealthPoint -= damageTaken;
		if (mHealthPoint <= 0) {
			mHealthPoint = 0;
			cout << mFirstName << " Was slain" << endl;
		}
	}
	void Character::loot(Character& enemy) {
		mMoney += enemy.GetMoney();
		enemy.SetMoney(0);
		enemy.SetWeapon(Weapon("Hands", "No weapon equiped", WeaponType::Empty, 0.0, 0, 0, 0.0));
	}
	void Character::useWeapon(Character& enemy) 
	{
		if (mHealthPoint > 0) {
			mWeapon.use();
			int damage = mWeapon.GetDamage();
			enemy.takeDmg(damage);
			std::cout <<mFirstName << " attacks " << enemy.GetFirstName() << " with " << mWeapon.GetName() << " for " << damage << " damage!" << std::endl;
		}
		else {
			std::cout << mFirstName << " is defeated and cannot attack." << std::endl;
		}

	};

