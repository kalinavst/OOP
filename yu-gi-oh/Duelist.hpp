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

#include <fstream>

#include "Deck.hpp"

class Duelist{
private:
    std::string name;
    Deck deck;
public:
    Duelist(const std::string&);
    Deck& getDeck();
    bool saveDeck(const std::string&);
    bool loadDeck(const std::string&);

    void duel(Duelist&);
    static void duel(Duelist&, Duelist&);

    friend std::ostream& operator<<(std::ostream& out, const Duelist& D);
    friend std::istream& operator>>(std::istream& in, Duelist& D);
};
