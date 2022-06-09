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

#include "Duelist.hpp"

Duelist::Duelist(const std::string&name):Name(name)
{
	Deck deck;
}

Deck& Duelist::GetDeck()
{
	return deck;
}

bool Duelist::saveDeck(const std::string&filename)
{
	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::trunc);
	if (file.is_open()) {
		file <<this-> GetDeck();
		file.close();
		return 1;

	}


	return false;
}

bool Duelist::loadDeck(const std::string& filename)
{
	std::ifstream file;
	file.open(filename, std::ios::in );
	if (file.is_open()) {
		file >> *this;
		file.close();
		return 1;

	}


	return false;
}

void Duelist::duel(Duelist& enemy)
{
	if (this->GetDeck().CardsCount() != enemy.GetDeck().CardsCount()) {
		std::cout << "The players have different number of cards!";
		return ;

}
	this->deck.Shuffle();
	enemy.deck.Shuffle();

	int myPoints = 0;
	int enemyPoints = 0;
	const int size = this->deck.CardsCount();
	for (int i = 0; i < size; i++) {
		/*std::cout << "My card is:  "  << std::endl;
		this->deck.getCards()[i].Print();
		std::cout<<enemy.Name << "`s card is:  " << enemy.deck.getCards()[i] << std::endl;*/
		if (this->deck.getCards()[i] ->operator>( enemy.deck.getCards()[i])) { myPoints++; }
		else if (this->deck.getCards()[i]->operator< ( enemy.deck.getCards()[i]))enemyPoints++;
		//std::cout << " The result after this round is: \n" << this->Name << "  " << myPoints << " points " << enemy.Name << "  " << enemyPoints << " points ";

	}
	std::cout << "My deck: " << this->deck;
	std::cout << std::endl<<enemy.Name<<"`s deck: "<<std::endl<<enemy.deck;
	
	if (myPoints > enemyPoints)std::cout << "The winner is " << this->Name;
	else if (myPoints < enemyPoints)std::cout << "The winner is " << enemy.Name;
	else std::cout << "The result is equal! ";
}

std::ostream& operator<<(std::ostream& out, const Duelist& duelist)
{
	out << duelist.deck;
	return out;
}

std::istream& operator>>(std::istream& in, Duelist& duelist)
{
	in >> duelist.GetDeck();
	return in;
	
}
