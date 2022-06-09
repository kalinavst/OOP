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
#include"MagicCard.hpp"
#include"MonsterCard.hpp"
#include"PendulumCard.hpp"
#include<vector>
#include <random>
#include <time.h>

class Deck {
public:
	Deck();
	Deck(const std::string&);
	//Deck& operator=(const Deck& to);
	int CardsCount()const;
	int MagicCardCount() const;
	int MonsterCardCount() const;
	int PendulumCardCount() const;
	void AddCard(Card& newCard);
	void ChangeCard(int index, Card&);
	void Empty();
	void Shuffle();
	~Deck();
	vector<Card*>getCards()const;
	//const std::string get_name()const;
	//void set_name(const std::string name);
	friend std::ostream& operator<<(std::ostream& out, const Deck& D);
	friend std::istream& operator>>(std::istream& in, Deck& D);

private:
	string name;
	std::vector<Card*>cards;
	int findCardByID(const int) const;
	bool isAlreadyInDeck(const Card&) const;

};