#pragma once
#include "WeaponTypes.h"
#include <string>

using namespace std;

class Weapon
{
	private:
		string mName;
		string mDescription;
		WeaponType mType;
		double mWeight;
		int mDamages;
		int mPrice;
		double mDurability;

	public:
		Weapon(const string& name,
			const string& description,
			WeaponType type, 
			double weight, 
			int damages, 
			int price, 
			double durability);
		Weapon();
		~Weapon();
		const string& GetName();
		const string& GetDescription();
		WeaponType GetType();
		double GetWeight();
		int GetDamage();
		int GetPrice();
		double GetDurability();

		void use();

};


