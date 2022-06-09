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


#include "MagicCard.hpp"

MagicCard::MagicCard():Card(),type(Type::buff)
{
}

MagicCard::MagicCard(const string& name, const string& effect, const unsigned& rarity, const Type& type):Card(name,effect,rarity),type(type)
{
}

void MagicCard::Print() const
{
	std::cout << *this;
}



//Type MagicCard::getType() const
//{
//	return type;
//}
//
//void MagicCard::setType(const Type& type)
//{
//	this->type=type;
//}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

string MagicCard::getCardType() const
{
	return "magic";
}

MagicCard::MagicCard(const Type&t)
{
	type = t;
}

std::ostream& operator<<(std::ostream&out, const MagicCard& card)
{
	string types[3] = { "TRAP", "BUFF", "SPELL" };
	const Card* ptr = &card;
	out << *ptr;
	out << "|" << types[card.type];
	return out;
}
std::istream& operator>>(std::istream& in, MagicCard& card) {
	string types[3] = { "TRAP", "BUFF", "SPELL" };
	Card* ptr = &card;
	in >> *ptr;

	std::string str;
	std::getline(in, str, '\n');
	if (str == types[0])card.type = Type::trap;
	else if (str == types[1])card.type = Type::buff;
	else if (str == types[2])card.type = Type::spell;

	

	return in;
}
