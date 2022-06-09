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
enum type {
	cloth, leather, mail
};

class Arrmor {
	type Type;
	int deffence = 0;
	std::string name;
	std::vector<std::pair <std::string, double >> effects;

public:
	Arrmor();
	Arrmor(std::string Name, type type1, double deff, std::vector<std::pair <std::string, double >> effect);
	void ChangeType(type newType);
	double GearScore() const;
	void addEffect(std::pair<std::string, double>newEffect);
	void RemoveEffect(std::pair<std::string, double>Effect);
	Arrmor& operator=(const Arrmor&);
	bool operator==(const Arrmor& to) const;
	int GetDeffence() const;
	std::vector<std::pair <std::string, double >> GetEffects()const;
	std::string GetName() const;
	type GetType() const;
	void SetDeffence(const int& def);
	void SetName( const std::string& N);
	void SetType( const type& typ);
	void SetEffects(const std::vector<std::pair <std::string, double >>&eff);
};