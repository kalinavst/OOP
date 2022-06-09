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
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Card {
public:
	Card();
	Card(const string& name, const string& effect, const unsigned& rarity);
	void copy_card(const Card& from);
	Card& operator=(const Card& to);

	/*string getName()const;
	string getEffect()const;
	unsigned getRarity() const;

	void setName(const string&);
	void setEffect(const string&);
	void setRarity(const unsigned&);*/
	int getID()const;
	bool operator>( Card* to) const;
	bool operator< (Card* to) const;

	virtual Card* clone() const = 0;
	virtual ~Card() = default;
	virtual string getCardType() const = 0;


	friend std::ostream& operator<<(std::ostream&, const Card&);
	friend std::istream& operator>>(std::istream&, Card&);
protected:
	string name;
	string effect;
	unsigned int rarity;

private:
	static int count;
	const int ID;

};