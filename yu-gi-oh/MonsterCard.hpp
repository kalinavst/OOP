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


#pragma once

#include <iostream>

#include "Card.hpp"

class MonsterCard : virtual public Card{
private:
    const static BaseCardType CARD_TYPE = BaseCardType::MonsterCard;
    bool PendulumCardInput(const std::string&) const;
protected:
    unsigned int attack_points;
    unsigned int defense_points;
    MonsterCard(const unsigned int&, const unsigned int&);
public:
    MonsterCard();
    MonsterCard(const std::string&, const std::string& = "None", const unsigned int& = 0, const unsigned int& = 0, const unsigned int& = 0);
    //MonsterCard(const MonsterCard&);

    BaseCardType getCardType() const;

    void print() const;

    friend std::ostream& operator<<(std::ostream& out, const MonsterCard& MC);
    friend std::istream& operator>>(std::istream& in, MonsterCard& MC);
};
