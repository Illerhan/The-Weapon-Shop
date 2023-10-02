#pragma once

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
		Weapon(std::string name,
			std::string descrition,
			WeaponType type, 
			float weight, 
			int damages, 
			int price, 
			float durability);
		~Weapon();
		std::string GetName();
		std::string GetDescription();
		WeaponType GetType();
		float GetWeight();
		int GetDamage();
		int GetPrice();
		float GetDurability();

		void setDurability();
		void setPrice();
};


