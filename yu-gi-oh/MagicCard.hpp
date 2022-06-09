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

#include "Card.hpp"

enum class MagicCardType{
    none,
    trap,
    buff,
    spell
};

class MagicCard : virtual public Card{
private:
    const static BaseCardType CARD_TYPE = BaseCardType::MagicCard;
protected:
    MagicCardType type;
    MagicCard(const MagicCardType&);
public:
    MagicCard();
    MagicCard(const std::string&, const std::string& = "None", const unsigned int& = 0, const MagicCardType& = MagicCardType::none);

    void setMagicCardType(const std::string&);
    std::string getMagicCardType() const;
    BaseCardType getCardType() const;

    void print() const;

    friend std::ostream& operator<<(std::ostream& out, const MagicCard& MC);
    friend std::istream& operator>>(std::istream& in, MagicCard& MC);
};
