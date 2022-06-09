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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include"Card.hpp"
class PendulumCard :  public  MagicCard ,public MonsterCard {
public:
	PendulumCard();
	PendulumCard(const string& name, const string& effect, const unsigned& rarity, const unsigned& atk, const unsigned& def, const Type& type, const unsigned& scale);

	//unsigned getScale()const;

	//void setScale(const unsigned& scale);
	

	Card* clone() const override;

	string getCardType() const override;

	friend std::istream& operator>>(std::istream&, PendulumCard&);
	friend std::ostream& operator<<(std::ostream&, const PendulumCard&);



protected:
	unsigned int pendulum_scale;
};