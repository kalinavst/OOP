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


#include "Duelist.hpp"

Duelist::Duelist(const std::string& name) : name(name) {}

Deck& Duelist::getDeck(){
    return deck;
}

void Duelist::duel(Duelist& first, Duelist& second){
    if(first.getDeck().allCardsCount() == second.getDeck().allCardsCount()){

        srand (time(NULL));
        int shuffles = 1 + rand() % 10;
        for(int i = 0; i < shuffles; i++){
            first.getDeck().shuffleDeck();
        }

        int last_shuffles = shuffles;
        while(shuffles == last_shuffles)
            shuffles = 1 + rand() % 10;

        for(int i = 0; i < shuffles; i++){
            second.getDeck().shuffleDeck();
        }

        int score_first = 0;
        int score_second = 0;
        for(int i = 0; i < first.getDeck().allCardsCount(); i++){

            std::cout<<"\n||| ROUND " << i + 1 << " |||\n";
            first.getDeck().getCard(i)->print();
            std::cout<<"VS\n";
            second.getDeck().getCard(i)->print();

            if(first.getDeck().getCard(i)->operator>(second.getDeck().getCard(i)))
                score_first ++;
            else if(first.getDeck().getCard(i)->operator<(second.getDeck().getCard(i)))
                score_second ++;

            std::cout<<"SCORE: " << score_first << " - " << score_second <<std::endl;
        }

        if(score_first > score_second)
            std::cout<<"\nWinner Duelist 1!\n";
        else if(score_first < score_second)
            std::cout<<"\nWinner Duelist 2!\n";
        else
            std::cout<<"\nDraw!\n";

        first.getDeck().arrangeDeck();
        second.getDeck().arrangeDeck();
    }
    else{
        std::cout<<"Duel can't start, duelists have different amount of cards!\n";
    }
}

void Duelist::duel(Duelist& other){
    Duelist::duel(*this, other);
}

bool Duelist::saveDeck(const std::string& filename){
    getDeck().arrangeDeck();

    std::ofstream file;
    file.open (filename, std::ios::out | std::ios::trunc);
    if(file.is_open()){
        file << *this;
        file.close();
        return 1;
    }
    return 0;
}

bool Duelist::loadDeck(const std::string& filename){
    std::ifstream file;
    file.open(filename, std::ios::in);
    if(file.is_open()){
        file >> *this;
        file.close();
        return 1;
    }
    return 0;
}

std::istream& operator>>(std::istream& in, Duelist& D){
    in >> D.getDeck();

    return in;
}

std::ostream& operator<<(std::ostream& out, const Duelist& D){
    out<<D.deck;

    return out;
}
