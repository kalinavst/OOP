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


#include "Deck.hpp"

Deck::Deck() {
    name = "";
    clearDeck();
}

int Deck::MagicCardsCount() const {
    int _count = 0;
    for (size_t i = 0; i<card_deck.size(); i++){
        if(card_deck[i]->getCardType() == BaseCardType::MagicCard)
            _count++;
    }
    return _count;
}

int Deck::MonsterCardsCount() const {
    int _count = 0;
    for (size_t i = 0; i<card_deck.size(); i++){
        if(card_deck[i]->getCardType() == BaseCardType::MonsterCard)
            _count++;
    }
    return _count;
}

int Deck::PendulumCardsCount() const {
    int _count = 0;
    for (size_t i = 0; i<card_deck.size(); i++){
        if(card_deck[i]->getCardType() == BaseCardType::PendulumCard)
            _count++;
    }
    return _count;
}

 int Deck::allCardsCount() const{
    return card_deck.size();
 }

bool Deck::isAlreadyInDeck(const Card& card) const{
    for(size_t i =0; i < card_deck.size(); i++){
        if(card_deck[i]->getID() == card.getID())
            return 1;
    }
    return 0;
}

bool Deck::addCard(const Card& card){
    if(isAlreadyInDeck(card) == 1){
        std::cout<<"Failed to add card, card already is already in the deck!\n";
        return 0;
    }
    else if(card.isUsed() == 0){
        card_deck.push_back(const_cast<Card*>(&card));
        card_deck[card_deck.size() - 1];
        arrangeDeck();
        return 1;
    }
    std::cout<<"Failed to add card, card already used in a different deck!\n";
    return 0;
}

int Deck::findCardByID(const int ID) const{
    for(size_t i = 0; i < card_deck.size(); i++){
        if(card_deck[i]->getID() == ID)
            return i;
    }
    std::cout<<"Card with ID " << ID << " not found!\n";
    return -1;
}

bool Deck::changeCard(const int& index, const Card& card){
    if(size_t(index) >= card_deck.size() || index < 0){
        std::cout<<"Failed to change card, index out of range!\n";
        return 0;
    }
    else if(card.getCardType() != card_deck[index]->getCardType()){
        std::cout<<"Failed to change card, card types do not match!\n";
        return 0;
    }
    else if(isAlreadyInDeck(card) == 1){
        std::swap(card_deck[index], card_deck[findCardByID(card.getID())]);
        return 1;
    }
    else if(card.isUsed() == 0){
        card_deck[index]->setUsed(0);
        card_deck[index] = const_cast<Card*>(&card);
        card_deck[index]->setUsed(1);
        return 1;
    }
    std::cout<<"Failed to change card, card already used in a different deck!\n";
    return 0;
}

Card* Deck::getCard(const int& index){
    return card_deck[index];
}

void Deck::shuffleDeck(){
    const int DECK_SIZE = card_deck.size();
    srand (time(NULL));
    for(int i = 0; i < DECK_SIZE; i++){
        std::swap(card_deck[i], card_deck[rand() % DECK_SIZE]);
    }
    /*std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(card_deck), std::end(card_deck), g);*/
}

void Deck::arrangeDeck(){
    int monster_count = 0;
    int magic_count = 0;
    int pendulum_count = 0;
    for (size_t i = 0; i < card_deck.size(); i++){
        if(card_deck[i]->getCardType() == BaseCardType::MonsterCard){
            std::swap(card_deck[i], card_deck[monster_count]);
            monster_count++;
        }
    }
    if(monster_count != MonsterCardsCount())
            std::cout<<"Something went wrong when arranging!\n";

    for(size_t i = 0; i < card_deck.size(); i++){
        if(card_deck[i]->getCardType() == BaseCardType::MagicCard){
            std::swap(card_deck[i], card_deck[monster_count + magic_count]);
            magic_count++;
        }
    }
    if(magic_count != MagicCardsCount())
            std::cout<<"Something went wrong when arranging!\n";

    for(size_t i = 0; i < card_deck.size(); i++){
        if(card_deck[i]->getCardType() == BaseCardType::PendulumCard){
            std::swap(card_deck[i], card_deck[MonsterCardsCount() + MagicCardsCount() + pendulum_count]);
            pendulum_count++;
        }
    }
    if(pendulum_count != PendulumCardsCount())
            std::cout<<"Something went wrong when arranging!\n";
}

void Deck::setDeckname(const std::string& new_name){
    name = new_name;
}

int Deck::convertStrToInt(const std::string str) const{
    int num = 0;
    for(size_t i = 0; i < str.size(); i++){
        num += ((int(str[i]) - int('0')) * pow(10, str.size() - 1 - i));
    }
    return num;
}

std::ostream& operator<<(std::ostream& out, const Deck& D){
    out << D.name << "|" << D.allCardsCount() << "|" << D.MonsterCardsCount() << "|" << D.MagicCardsCount() << "|" << D.PendulumCardsCount() << "\n";

    for(size_t  i = 0; i < D.card_deck.size(); i++){
        if(D.card_deck[i] -> getCardType() == BaseCardType::MonsterCard){
            MonsterCard* ptr = dynamic_cast<MonsterCard*>(D.card_deck[i]);
            out << *ptr;
        }

        else if(D.card_deck[i] -> getCardType() == BaseCardType::MagicCard){
            MagicCard* ptr = dynamic_cast<MagicCard*>(D.card_deck[i]);
            out << *ptr;
        }

        else{
            MonsterCard* ptr1 = dynamic_cast<MonsterCard*>(D.card_deck[i]);
            PendulumCard* ptr2 = dynamic_cast<PendulumCard*>(ptr1);
            out << *ptr2;
        }
        out << "\n";
    }

    return out;
}

void Deck::readFirstLine(std::string& line, int& monster_card_count, int& magic_card_count, int& pendulum_card_count) {
    size_t index = 0;

    index = line.find("|");
    name = line.substr(0, index);
    line = line.substr(index + 1, line.size() - 1);

    index = line.find("|");
    line = line.substr(index + 1, line.size() - 1);

    index = line.find("|");
    monster_card_count = convertStrToInt(line.substr(0, index));
    line = line.substr(index + 1, line.size() - 1);

    index = line.find("|");
    magic_card_count = convertStrToInt(line.substr(0, index));
    line = line.substr(index + 1, line.size() - 1);

    pendulum_card_count = convertStrToInt(line.substr(0, index));
}

std::istream& operator>>(std::istream& in, Deck& D){
    D.clearDeck();

    int monster_card_count = 0;
    int magic_card_count = 0;
    int pendulum_card_count = 0;

    std::string line;
    std::getline (in, line, '\n');

    D.readFirstLine(line, monster_card_count, magic_card_count, pendulum_card_count);

    const int MCC = monster_card_count;
    const int MAC = magic_card_count;
    const int PCC = pendulum_card_count;

    D.clearDeck();

    D.monster_cards_database = new MonsterCard[MCC];
    D.magic_cards_database = new MagicCard[MAC];
    D.pendulum_cards_database = new PendulumCard[PCC];

    for(int i = 0; i < monster_card_count; i++){
        in >> D.monster_cards_database[i];
        Card* ptr = &D.monster_cards_database[i];
        D.card_deck.push_back(ptr);
    }

    for(int i = 0; i < magic_card_count; i++){
        in >> D.magic_cards_database[i];
        Card* ptr = &D.magic_cards_database[i];
        D.card_deck.push_back(ptr);
    }

    for(int i = 0; i < pendulum_card_count; i++){
        in >> D.pendulum_cards_database[i];
        Card* ptr = &D.pendulum_cards_database[i];
        D.card_deck.push_back(ptr);
    }

    return in;
}

void Deck::clearDeck(){
    card_deck.clear();
    if(monster_cards_database != nullptr){
        delete [] monster_cards_database;
        monster_cards_database = nullptr;
    }
    if(magic_cards_database != nullptr){
        delete [] magic_cards_database;
        magic_cards_database = nullptr;
    }

    if(pendulum_cards_database != nullptr){
        delete [] pendulum_cards_database;
        pendulum_cards_database = nullptr;
    }
}

Deck::~Deck(){
    clearDeck();
}
