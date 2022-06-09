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

#include "Card.hpp"

int Card::_count = 0;

Card::Card() :
    ID(_count),
    name("None"),
    effect("None"),
    rarity(0)
    {_count++;}

Card::Card(const std::string& name, const std::string& effect, const unsigned int rarity) :
    ID(_count),
    name(name),
    effect(effect),
    rarity(rarity)
    {_count++;}

int Card::convertStrToInt(const std::string& str) const{
    size_t i = 0;
    if(str[i] == '-')
        i = 1;
    int num = 0;
    while(i < str.size()){
        if(int(str[i]) < int('0') || int(str[i]) > int('9')){
            std::cout<<"String contains other characters! Failed to convert ot int.\n";
            return -1;
    }
        num += ((int(str[i]) - int('0')) * pow(10, str.size() - 1 - i));
        i++;
    }
    if(str[i] == '-')
        return -1*num;
    return num;
}

bool Card::isUsed() const {
    return is_used;
}

void Card::setUsed(const bool used){
    is_used = used;
}

int Card::getID() const{
    return ID;
}

int Card::getRarity() const{
    return rarity;
}

bool Card::operator<(Card* other) const{
    return (rarity < other->rarity);
}

bool Card::operator>(Card* other) const{
    return (rarity > other->rarity);
}

std::ostream& operator<<(std::ostream& out, const Card& C) {
    out << C.name << "|" << C.effect << "|" << C.rarity;

    return out;
}

std::istream& operator>>(std::istream& in, Card& C){
    std::string str;
    std::getline(in, C.name, '|');

    std::getline(in, C.effect, '|');

    std::getline(in, str, '|');

    C.rarity = C.convertStrToInt(str);

    return in;
}
