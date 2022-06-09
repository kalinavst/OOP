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
#include "Card.hpp"
enum Type {
	trap=0, buff=1, spell=2
};

class MagicCard : virtual public Card 
{public:
	MagicCard();
	MagicCard(const string& name, const string& effect, const unsigned& rarity, const Type& type);
	void Print()const;

	//Type getType()const;

	//void setType(const Type& type);

	Card* clone() const override;
	string getCardType() const override;

	friend std::istream& operator>>(std::istream&, MagicCard&);
	friend std::ostream& operator<<(std::ostream&, const MagicCard&);

protected:
	Type type;
	MagicCard(const Type&);


};