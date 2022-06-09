/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Presiyan Todorov
* @idnumber 62626
* @task 1
* @compiler GCC
*/


#include "MagicCard.hpp"

MagicCard::MagicCard() :
    Card(),
    type(MagicCardType::none) {}

MagicCard::MagicCard(const MagicCardType& type) :
    type(type) {}

MagicCard::MagicCard(const std::string& name, const std::string& effect, const unsigned int& rarity, const MagicCardType& type) :
    Card(name, effect, rarity),
    type(type) {}

void MagicCard::setMagicCardType(const std::string& str){
    if (str == "NONE")
        type = MagicCardType::none;
    else if(str == "BUFF")
        type = MagicCardType::buff;
    else if(str == "SPELL")
        type = MagicCardType::spell;
    else if(str == "TRAP")
        type = MagicCardType::trap;
}

std::string MagicCard::getMagicCardType() const {
    if (type == MagicCardType::none)
        return "NONE";
    else if(type == MagicCardType::buff)
        return "BUFF";
    else if(type == MagicCardType::spell)
        return "SPELL";
    else
        return "TRAP";
}

BaseCardType MagicCard::getCardType() const{
    return MagicCard::CARD_TYPE;
}

void MagicCard::print() const{
    std::cout<<*this<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const MagicCard& MA){
    const Card* ptr = &MA;
    out << *ptr;
    out << "|" << MA.getMagicCardType();

    return out;
}

std::istream& operator>>(std::istream& in, MagicCard& MA){
    Card* ptr = &MA;
    in >> *ptr;

    std::string str;
    std::getline(in, str, '\n');


    MA.setMagicCardType(str);

    return in;
}
