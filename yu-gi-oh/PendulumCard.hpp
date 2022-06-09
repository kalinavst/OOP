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

#include "MagicCard.hpp"
#include "MonsterCard.hpp"

class PendulumCard : public MagicCard, public MonsterCard{
private:
    const static BaseCardType CARD_TYPE = BaseCardType::PendulumCard;
    unsigned int pendulum_scale;
public:
    PendulumCard();
    PendulumCard(const std::string&, const std::string& = "None", const unsigned int& = 0, const unsigned int& = 0, const unsigned int& = 0,
                  const MagicCardType& = MagicCardType::none, const unsigned int& = 1);


    BaseCardType getCardType() const;

    void print() const;


    friend std::ostream& operator<<(std::ostream& out, const PendulumCard& PC);
    friend std::istream& operator>>(std::istream& in, PendulumCard& PC);

};
