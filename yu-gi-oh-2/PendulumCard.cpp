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


#include "PendulumCard.hpp"

PendulumCard::PendulumCard() :
	Card::Card(),
	MagicCard(Type::buff), 
	MonsterCard(0,0), pendulum_scale(1)
{
}

PendulumCard::PendulumCard(const string& name, const string& effect, const unsigned& rarity, const unsigned& atk, const unsigned& def, const Type& type, const unsigned& scale):
	Card::Card(name,effect,rarity),
	MonsterCard(atk,def),
	MagicCard(type),
	pendulum_scale(scale)
{
	
	
}

//unsigned PendulumCard::getScale() const
//{
//	return pendulum_scale;
//}
//
//void PendulumCard::setScale(const unsigned& scale)
//{
//	if (scale >= 1 && scale <= 13)this->pendulum_scale = scale;
//
//}



Card* PendulumCard::clone() const
{
	return new PendulumCard(*this);
}

string PendulumCard::getCardType() const
{
	return "pendulum";
}

std::istream& operator>>(std::istream&in, PendulumCard&card)
{
	std::string types[3] = { "TRAP", "BUFF", "SPELL" };
	
	std::string myString;

	Card* ptr = &card;
	in >> *ptr;

	//std::getline(in, str, '|');
	
	std::getline(in, myString, '|');
	card.attack = stoi(myString);

	std::getline(in, myString, '|');
	card.deffence = stoi(myString);
	

	std::getline(in, myString, '|');
	card.pendulum_scale = stoi(myString);

	std::getline(in, myString, '\n');

	if (myString == types[0])card.type = Type::trap;
	else if (myString == types[1])card.type = Type::buff;
	else if (myString == types[2])card.type = Type::spell;

	return in;
}

std::ostream& operator<<(std::ostream&out, const PendulumCard&card)
{
	std::string types[3] = { "TRAP", "BUFF", "SPELL" };
	
	const MonsterCard* ptr = &card;
	out << *ptr;
	out << "|" << card.pendulum_scale << "|" << types[card.type];
	return out;
}
