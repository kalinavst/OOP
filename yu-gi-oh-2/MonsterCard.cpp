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


#include "MonsterCard.hpp"

MonsterCard::MonsterCard():Card(),attack(0),deffence(0)
{
}

MonsterCard::MonsterCard(const string& name, const string& effect, const unsigned& rarity, const unsigned& atk, const unsigned& def):Card(name,effect,rarity), attack(atk), deffence(def)
{
}

//unsigned MonsterCard::getATK() const
//{
//	return attack;
//}
//
//unsigned MonsterCard::getDEF() const
//{
//	return deffence;
//}

//void MonsterCard::setATK(const unsigned& atk)
//{
//	attack = atk;
//}
//
//void MonsterCard::setDEF(const unsigned& def)
//{
//	deffence = def;
//}

void MonsterCard::Print() const
{
	std::cout << *this;
}

Card* MonsterCard::clone() const 
{
	return new MonsterCard(*this);
}

string MonsterCard::getCardType() const
{
	return "monster";
}

MonsterCard::MonsterCard(const unsigned atk, const unsigned def):attack(atk),deffence(def)
{
}



std::istream& operator>>(std::istream& input, MonsterCard& card)
{
	Card* ptr = &card;
	input >> *ptr;

	std::string str;
	std::getline(input, str, '|');
	card.attack = stoi(str);

	std::getline(input, str, '\n');
	card.deffence = stoi(str);
	return input;
}

std::ostream& operator<<(std::ostream& output, const MonsterCard& from)
{
	const Card* ptr = &from;
	output << *ptr;
	output << "|" << from.attack<< "|" << from.deffence;

	return output;
	
}
