/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalina Stoimenova
* @idnumber 62636
* @task 1
* @compiler VC
*/

#pragma once
#include <cstring>
#include <vector>
# include < utility >
#include <iostream>


enum WeaponType {
	one_handed, two_handed
};


class Weapon {
	std::string Name;
	WeaponType type;
	std::string KindOfWeapon;
	double hitDamage[2];
	std::vector<std::pair <std::string, double >> effects;
public:
	Weapon();
	Weapon(std::string name,WeaponType type1, std::string kind, double minDamage, double MaxDamage, std::vector<std::pair <std::string, double >> effect);
	std::string GetName()const;
	WeaponType Gettype()const;
	std::string GetKindOfWeapon()const;
	double* GethitDamage();
	std::vector<std::pair <std::string, double >> Geteffects();
	int SlotsTaken()const;
	double WeaponScore();
	void ChangeKind(std::string newKind);
	void ChangeType(WeaponType typ);
	void AddWeaponEffect(std::pair<std::string, double>newEffect);
	void RemoveWeaponEffect(std::pair<std::string, double>Effect);
	void ChangePower(std::pair<std::string, double>Effect, double newpower);
	bool operator==(const Weapon& to) const;

};

