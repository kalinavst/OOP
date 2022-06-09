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

#include"Money.hpp"
#include <iostream>
#include <cstring>
#include <vector>


Money::Money() {
	name = "";
	Gold = 0;
	Silver = 0;
}

Money::Money(unsigned int g, unsigned int s, std::string Name) {
	name = Name;
		
		if (s < 100) {
			Silver = s;
			Gold = g;
	}
		else {
			Silver = s % 100;
			Gold = g + s / 100;
		}
	

}

unsigned int Money::GetSilver() const
{
	return Silver;
}

unsigned int Money::GetGold() const
{
	return Gold
		;
}

void Money::SetSilver(const unsigned int& s)
{
	Silver = s;
}

void Money::SetGold(const unsigned int& g)
{
	Gold = g;
}
