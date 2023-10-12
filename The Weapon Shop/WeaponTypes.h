#pragma once
namespace WeaponTypes{
	enum WeaponType {
    Empty = 1<<0,
    OneHSword = 1<<1,
    TwoHSword = 1<<2,
    Bow = 1<<3,
    Lance = 1<<4,
    Dagger = 1<<5,
    Staff = 1<<6,
    Gun = 1<< 7,
	};
}