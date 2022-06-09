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


#include <iostream>
#include"PendulumCard.hpp"
#include"Deck.hpp"
#include"Duelist.hpp"

int main() {
	PendulumCard k("kalina", "instant death", 1000, 1000000, 100000, spell, 13);
	PendulumCard j;
	//MagicCard k1;
	//MonsterCard j;
	//string a, b, c;
	/*std::cin >> j;
	std::cout << j;*/
	/*Deck Kalina_deck("Kalina`s monsters");
	std::cin >> Kalina_deck;*/
	Duelist krisi("Krisko327");
	Duelist kalina("Kalina");
	if (krisi.loadDeck("kalina.txt"))std::cout << "Brawooo!!";
	//if (krisi.saveDeck("blq.txt"))std::cout << "evala!!";

	if (kalina.loadDeck("deck.txt"))std::cout << "Brawooo!!";
	kalina.duel(krisi);

	//std::cout << Kalina_deck;



}