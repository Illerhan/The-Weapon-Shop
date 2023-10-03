#pragma once
#include "WeaponTypes.h"
class Weapon
{
	private:
		std::string mName;
		std::string mDescripton;
		WeaponType mType;
		float mWeight;
		int mDamages;
		int mPrice;
		float mDurability;


	public:
		Weapon(const std::string& name,
			const std::string& descrition,
			WeaponType type, 
			float weight, 
			int damages, 
			int price, 
			float durability);
		~Weapon();
		const std::string& GetName();
		const std::string& GetDescription();
		WeaponType GetType();
		float GetWeight();
		int GetDamage();
		int GetPrice();
		float GetDurability();

		void use();
		void setPrice();
};


