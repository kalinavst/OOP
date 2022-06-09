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


class Money {
	std::string name;
	unsigned int Gold;
	unsigned int Silver;
public:
	Money();
	Money(unsigned int g,unsigned int s,std::string Name);
	unsigned int GetSilver() const;
	unsigned int GetGold() const ;
	void SetSilver(const unsigned int& s);
	void SetGold(const unsigned int& g);
};