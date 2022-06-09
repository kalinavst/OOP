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

#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"

class Deck{
private:
    MonsterCard* monster_cards_database = nullptr;
    MagicCard* magic_cards_database = nullptr;
    PendulumCard* pendulum_cards_database = nullptr;

    std::vector<Card*> card_deck;
    std::string name;

    int findCardByID(const int) const;
    bool isAlreadyInDeck(const Card&) const;
    void readFirstLine(std::string&, int&, int&, int&);
    int convertStrToInt(const std::string) const;

    int MagicCardsCount() const;
    int MonsterCardsCount() const;
    int PendulumCardsCount() const;
public:
    Deck();
    void setDeckname(const std::string&);

    int allCardsCount() const;
    void shuffleDeck();
    void arrangeDeck();
    Card* getCard(const int&);

    bool addCard(const Card&);
    bool changeCard(const int&, const Card&);


    friend std::ostream& operator<<(std::ostream& out, const Deck& D);
    friend std::istream& operator>>(std::istream& in, Deck& D);

    void clearDeck();
    ~Deck();
};
