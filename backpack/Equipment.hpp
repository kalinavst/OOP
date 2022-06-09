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
#include "Weapon.hpp"
#include "Arrmor.hpp"

template<class T>


class Equipment {
	std::vector<T>equipments;
	int slots ;
	int takenSlots;
public:
	Equipment();
	Equipment(std::vector<T>nnew);
	bool IsEmpty();
	bool IsFull();
	void ClearEquipment();
	void Add(const T& newEquipment);
	void Remove(const T& equipment);
	T Best();
	int TakenSlots()const;
};

template<class T>
inline Equipment<T>::Equipment()
{
	std::vector<T>equipments;
	int slots = 24;
	int takenSlots = 0;
}

template<class T>
inline Equipment<T>::Equipment(std::vector<T> nnew)
{
	takenSlots = 0;
	if (typeid(T) == typeid(Weapon)) {
		for (int i = 0; i < nnew.size(); i++) {
			takenSlots += nnew[i].SlotsTaken();
		}
	else takenSlots = nnew.size();

	equipments = nnew;

}
}

template<class T>
inline bool Equipment<T>::IsEmpty()
{
	if (equipments.size() == 0)return 1;
	return false;
}

template<class T>
inline bool Equipment<T>::IsFull()
{
	if (equipments.size() == slots)return 1;
	return false;
}

template<class T>
inline void Equipment<T>::ClearEquipment()
{
	if (!IsEmpty())equipments.clear();
	takenSlots = 0;

}

template<class T>
inline void Equipment<T>::Add(const T& newEquipment)
{
	equipments.push_back(newEquipment);
	takenSlots++;
}

template<class T>
inline void Equipment<T>::Remove(const T& equipment)
{
	for (int i = 0; i < equipments.size(); i++) {
		if (equipments[i] == equipment) { equipments.erase(equipments.begin() + i); 
		if (typeid(T) == typeid(Weapon))takenSlots -= equipment.SlotsTaken();
		else takenSlots--;
		}
}
}

template<>
inline Weapon Equipment<Weapon>::Best()
{
	double maxScore = 0;
	int Maxindex = 0;
	for (int i = 0; i < equipments.size(); i++) {
		if (equipments[i].WeaponScore() >= maxScore) {
			maxScore = equipments[i].WeaponScore();
			Maxindex = i;
		}
	} return equipments[Maxindex];
}
template<class T>
inline int Equipment<T>::TakenSlots() const
{
	return takenSlots;
}
template<>
inline Arrmor Equipment<Arrmor>::Best()
{
	double maxScore = 0;
	int Maxindex = 0;
	for (int i = 0; i < equipments.size(); i++) {
		if (equipments[i].GearScore() >= maxScore) {
			maxScore = equipments[i].GearScore();
			Maxindex = i;
		}
	} return equipments[Maxindex];
}

template<>
inline void Equipment<Weapon>::Add(const Weapon& newEquipment)
{
	if (!IsFull()) {
		equipments.push_back(newEquipment);
		takenSlots += newEquipment.SlotsTaken();
	}
	else std::cout << "Full.";
}
