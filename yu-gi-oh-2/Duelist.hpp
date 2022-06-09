/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author <Kalina Stoimenova>
* @idnumber <62636>
* @task <1>
* @compiler < VC>
*/

#pragma once
#include"Deck.hpp"
#include<fstream>

class Duelist {
public:
	Duelist(const std::string&);
	Deck& GetDeck();
	bool saveDeck(const std::string&);
	bool loadDeck(const std::string&);
	void duel(Duelist&);

	friend std::ostream& operator<<(std::ostream& out, const Duelist& duelist);
	friend std::istream& operator>>(std::istream& in, Duelist& duelist);

private:
	std::string Name;
	Deck deck;


};