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
#include"Card.hpp"

class MonsterCard : virtual public Card {
public:
	MonsterCard();
	MonsterCard(const string& name, const string& effect, const unsigned& rarity, const unsigned& atk, const unsigned& def);

	//unsigned getATK()const;
	//unsigned getDEF()const;

	//void setATK(const unsigned& atk);
	//void setDEF(const unsigned& def);
	void Print()const;
	Card* clone() const override;
	friend std::istream& operator>>(std::istream&, MonsterCard&);
	friend std::ostream& operator<<(std::ostream&, const MonsterCard&);
	string getCardType() const override;
protected:
	unsigned int attack;
	unsigned int deffence;
	MonsterCard(const unsigned, const unsigned);



};