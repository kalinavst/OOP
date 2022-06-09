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


#include "MonsterCard.hpp"

MonsterCard::MonsterCard() :
    Card(),
    attack_points(0),
    defense_points(0) {}

MonsterCard::MonsterCard(const unsigned int& att, const unsigned int& def) :
    attack_points(att),
    defense_points(def) {}

MonsterCard::MonsterCard(const std::string& name, const std::string& effect, const unsigned int& rarity, const unsigned int& att,
                          const unsigned int& def) :
    Card(name, effect, rarity),
    attack_points(att),
    defense_points(def) {}

BaseCardType MonsterCard::getCardType() const{
    return MonsterCard::CARD_TYPE;
}

void MonsterCard::print() const{
    std::cout<<*this<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& MC){
    const Card* ptr = &MC;
    out << *ptr;
    out << "|" << MC.attack_points << "|" << MC.defense_points;

    return out;
}

bool MonsterCard::PendulumCardInput(const std::string& str) const{
    bool PC_input = 1;
    for(size_t i = 0; i < str.size(); i++){
        if (int(str[i]) == int('\n')){
            PC_input = 0;
        }
    }

    return PC_input;
}

std::istream& operator>>(std::istream& in, MonsterCard& MC){
    Card* ptr = &MC;
    in >> *ptr;

    std::string str;
    std::getline(in, str, '|');
    MC.attack_points = MC.convertStrToInt(str);

    std::getline(in, str, '|');

    if(MC.PendulumCardInput(str) == 0){
        in.seekg((-1)*str.size() - 1, std::ios_base::cur);
        std::getline(in, str, '\n');
    }

    MC.defense_points = MC.convertStrToInt(str);

    return in;
}
