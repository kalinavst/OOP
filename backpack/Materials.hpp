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
#include <iostream>
#include <cstring>
#include <vector>
class Materials {

	int herbs = 0;
	int ores = 0;
	int cloth = 0;
	int essence = 0;
	std::string type;
public:
	Materials();

	Materials(std::string type, int Herbs=0, int Ores=0, int Cloth=0, int Essence=0);
	int GetHerbs()const;
	int GetOres()const;
	int GetCloth()const;
	int GetEssence() const;
	std::string GetType()const;
	void SetHerbs( const int& h);
	void SetOres( const int& o);
	void SetCloth(const int& c);
	void SetEssence(const int& e);
	void SetType(const std::string& typ);
};