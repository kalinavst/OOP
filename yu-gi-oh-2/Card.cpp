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

#include "Card.hpp"
int Card::count = 0;
Card::Card() :name(""), effect(""), rarity(0), ID(count) { count++; }

Card::Card(const string& name, const string& effect, const unsigned& rarity) : name(name), effect(effect), rarity(rarity), ID(count) { count++; }

void Card::copy_card(const Card& from)
{
	this->name = from.name;
	this->effect = from.effect;
	this->rarity = from.rarity;
}

Card& Card::operator=(const Card& to)
{
	this->copy_card(to);
	return *this;
}

//string Card::getName() const
//{
//	return name;
//}
//
//string Card::getEffect() const
//{
//	return effect;
//}
//
//unsigned Card::getRarity() const
//{
//	return rarity;
//}
//
//void Card::setName(const string& name)
//{
//	this->name = name;
//}
//
//void Card::setEffect(const string&effect)
//{
//	this->effect = effect;
//}
//
//void Card::setRarity(const unsigned& rarity)
//{
//	this->rarity = rarity;
//}

int Card::getID() const
{
	return ID;
}

bool Card::operator>( Card* to) const
{
	if (this->rarity > to->rarity)return 1;
	else
	return false;
}

bool Card::operator<( Card* to) const
{
	if (this->rarity < to->rarity)return 1;
	 else return false;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	out << card.name << "|" << card.effect << "|" << card.rarity;
	return out;
}

std::istream& operator>>(std::istream& in, Card& card)
{
string str;
	getline(in, card.name, '|');

	std::getline(in, card.effect, '|');

	std::getline(in, str, '|');

	card.rarity = stoi(str);

	return in;
}

