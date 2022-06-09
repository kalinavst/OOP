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


#include "PendulumCard.hpp"

PendulumCard::PendulumCard() :
    Card(),
    MagicCard(MagicCardType::none),
    MonsterCard(0, 0),
    pendulum_scale(1) {}

PendulumCard::PendulumCard(const std::string& name, const std::string& effect, const unsigned int& rarity, const unsigned int& att,
                            const unsigned int& def, const MagicCardType& type,const unsigned int& scale) :
    Card(name, effect, rarity),
    MagicCard(type),
    MonsterCard(att, def)
    {
        if(scale > 13)
            pendulum_scale = 13;
        else if (scale < 1)
            pendulum_scale = 1;
        else
            pendulum_scale = scale;
    }


BaseCardType PendulumCard::getCardType() const{
    return PendulumCard::CARD_TYPE;
}

void PendulumCard::print() const{
    std::cout<<*this<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const PendulumCard& PC){
    const MonsterCard* ptr = &PC;
    out << *ptr;
    out << "|" << PC.pendulum_scale << "|" << PC.getMagicCardType();

    return out;
}

std::istream& operator>>(std::istream& in, PendulumCard& PC){
    std::string str;

    MonsterCard* ptr = &PC;
    in >> *ptr;

    //std::getline(in, str, '|');

    std::getline(in, str, '|');
    PC.pendulum_scale = PC.convertStrToInt(str);

    std::getline(in, str, '\n');

    PC.setMagicCardType(str);

    return in;
}

