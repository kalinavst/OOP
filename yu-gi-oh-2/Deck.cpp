/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author <Kalina Stoimenova>
* @idnumber <62636>
* @task <1>
* @compiler < VC>
*/

#include "Deck.hpp"

Deck::Deck()
{
	name = "";
}

Deck::Deck(const std::string&name):name(name)
{
}

int Deck::CardsCount() const
{
	return cards.size();
}

int Deck::MagicCardCount() const
{
	int magics = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getCardType() == "magic")magics++;
	}
	return magics;
}

int Deck::MonsterCardCount() const
{
	int br = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getCardType() == "monster")br++;
	}
	return br;
}

int Deck::PendulumCardCount() const
{
	int br = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getCardType() == "pendulum")br++;
	}
	return br;
}

void Deck::AddCard(Card& newCard)
{
	if (!isAlreadyInDeck(newCard))
		cards.push_back(newCard.clone());
	else std::cout << "Card  is already in the deck";
}


void Deck::ChangeCard(int index, Card& card)
{
	if (cards[index]->getCardType() != card.getCardType())
	{
		std::cout << "Different card type";
		return;
	}

	else if (index > cards.size() || index < 0) {
		std::cout << "Wrong index input!";
		return;
	}

	else {
		Card* newCard = card.clone();
		cards[index] = newCard;
	}
}

void Deck::Empty()
{
	cards.clear();
}

void Deck::Shuffle()
{
	const int SIZE = cards.size();
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		std::swap(cards[i], cards[rand() % SIZE]);
	}
}

Deck::~Deck()
{
	cards.clear();
}

vector<Card*> Deck::getCards() const
{
	return cards;
}

int Deck::findCardByID(const int id) const
{
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getID() == id)return i;
	}
	 return -1;
}

bool Deck::isAlreadyInDeck(const Card&card) const
{

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getID() == card.getID())return 1;
	}
	
	return false;
}

std::ostream& operator<<(std::ostream& out, const Deck& from)
{
	out << from.name << "|" << from.CardsCount() << "|" << from.MonsterCardCount() << "|" << from.MagicCardCount() << "|" << from.PendulumCardCount()<<std::endl;
	for (int i = 0; i < from.cards.size(); i++) {
		if (from.cards[i]->getCardType() == "monster") {
			MonsterCard* ptr = dynamic_cast<MonsterCard*>(from.cards[i]);
			out << *ptr << std::endl;


		}


	}

	for (int i = 0; i < from.cards.size(); i++) {
		if (from.cards[i]->getCardType() == "magic") {
			MagicCard* ptr = dynamic_cast<MagicCard*>(from.cards[i]);
			out << *ptr << std::endl;


		}
	}

	for (int i = 0; i < from.cards.size(); i++) {
		if (from.cards[i]->getCardType() == "pendulum") {
			PendulumCard* ptr = dynamic_cast<PendulumCard*>(from.cards[i]);
			out <<*ptr << std::endl;


		}
	}
	
	
	
	
	
	
	
	
	
	
	return out;
}

std::istream& operator>>(std::istream& in, Deck& to)
{
	
	std::string line;
	std::getline(in, line, '\n');
	int monster_card_count = 0;
	int magic_card_count = 0;
	int pendulum_card_count = 0;
	size_t index = 0;

	index = line.find("|");
	to.name = line.substr(0, index);
	line = line.substr(index + 1, line.size() - 1);

	index = line.find("|");
	line = line.substr(index + 1, line.size() - 1);

	index = line.find("|");
	monster_card_count = stoi(line.substr(0, index));
	line = line.substr(index + 1, line.size() - 1);

	index = line.find("|");
	magic_card_count = stoi(line.substr(0, index));
	line = line.substr(index + 1, line.size() - 1);

	pendulum_card_count = stoi(line.substr(0, index));


	

	

	const int MCC = monster_card_count;
	const int MAC = magic_card_count;
	const int PCC = pendulum_card_count;

	to.Empty();

	

	for (int i = 0; i < monster_card_count; i++) {
		MonsterCard newCard;
		in >> newCard;
		to.cards.push_back(newCard.clone());
	}

	for (int i = 0; i < magic_card_count; i++) {
		MagicCard newCard;
		in >> newCard;
		to.cards.push_back(newCard.clone());
	}

	for (int i = 0; i < pendulum_card_count; i++) {
		PendulumCard newCard;
		in >> newCard;
		to.cards.push_back(newCard.clone());
	}

	return in;
}
