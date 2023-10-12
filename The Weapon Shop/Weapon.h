#pragma once
#include "WeaponTypes.h"
#include <string>



using namespace std;

class Weapon
{
	private:
		string mName;
		string mDescription;
		std::uint8_t mType;
		double mWeight;
		int mDamages;
		int mPrice;
		double mDurability;

	public:
		Weapon(const string& name,
			const string& description,
			std::uint8_t type = 0, 
			double weight =0, 
			int damages=1, 
			int price=0, 
			double durability=1);
		Weapon();
		~Weapon();
		const string& GetName();
		const string& GetDescription();
		uint8_t GetType();
		double GetWeight();
		int GetDamage();
		int GetPrice();
		double GetDurability();

		void use();

};


