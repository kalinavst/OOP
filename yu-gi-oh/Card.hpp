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
#include <cmath>
#include <string>

enum class BaseCardType{
    MonsterCard,
    MagicCard,
    PendulumCard
};

class Card{
private:
    bool is_used = 0;
    static int _count;
    const int ID;
protected:
    std::string name;
    std::string effect;
    unsigned int rarity;
public:
    Card();
    Card(const std::string&, const std::string& = "None", const unsigned int = 0);

    int convertStrToInt(const std::string&) const;

    virtual BaseCardType getCardType() const = 0;
    int getID() const;
    bool isUsed() const;
    void setUsed(const bool);

    int getRarity() const;
    bool operator<(Card*) const;
    bool operator>(Card*) const;

    virtual void print() const = 0;

    friend std::ostream& operator<<(std::ostream&, const Card&);
    friend std::istream& operator>>(std::istream&, Card&);

};
