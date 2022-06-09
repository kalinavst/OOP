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

using namespace std;

int main()
{
    cout<<"||||| ADD/CHANGE CARD TEST |||||\n\n";

    MonsterCard MC1("MONSTER1", "EFFECT1", 5, 150, 100);
    MonsterCard MC2("MONSTER2", "EFFECT2", 3, 200, 155);
    MonsterCard MC3("MONSTER3", "EFFECT3", 2, 170, 125);
    MonsterCard MC4("MONSTER4", "EFFECT4", 6, 175, 120);
    MonsterCard MC5("MONSTER5", "EFFECT5", 4, 165, 150);
    MagicCard MA1("MAGIC1", "EFFECT1", 4, MagicCardType::buff);
    MagicCard MA2("MAGIC2", "EFFECT2", 8, MagicCardType::spell);
    MagicCard MA3("MAGIC3", "EFFECT3", 10, MagicCardType::trap);
    MagicCard MA4("MAGIC4", "EFFECT4", 3, MagicCardType::buff);
    MagicCard MA5("MAGIC5", "EFFECT5", 5, MagicCardType::trap);
    PendulumCard PC1("PENDULUM1", "EFFECT1", 5, 150, 200, MagicCardType::spell, 4);
    PendulumCard PC2("PENDULUM2", "EFFECT2", 6, 150, 250, MagicCardType::buff, 6);
    PendulumCard PC3("PENDULUM3", "EFFECT3", 7, 200, 300, MagicCardType::spell, 7);
    PendulumCard PC4("PENDULUM4", "EFFECT4", 3, 400, 200, MagicCardType::buff, 8);
    PendulumCard PC5("PENDULUM5", "EFFECT5", 1, 500, 400, MagicCardType::trap, 12);

    Duelist Preso("Preso");
    Preso.getDeck().setDeckname("Preso");

    Deck Preso_Deck;
    Preso_Deck.setDeckname("Preso");

    Preso.getDeck().addCard(MC1);
    Preso.getDeck().addCard(MC2);
    Preso.getDeck().addCard(MC3);
    Preso.getDeck().addCard(MC4);
    Preso.getDeck().addCard(MC5);
    Preso.getDeck().addCard(MA1);
    Preso.getDeck().addCard(MA2);
    Preso.getDeck().addCard(MA3);
    Preso.getDeck().addCard(MA4);
    Preso.getDeck().addCard(MA5);
    Preso.getDeck().addCard(PC1);
    Preso.getDeck().addCard(PC2);
    Preso.getDeck().addCard(PC3);
    Preso.getDeck().addCard(PC4);
    Preso.getDeck().addCard(PC5);

    cout<<Preso<<endl;


    MonsterCard MC20("MONSTER6", "EFFECT6", 20, 600, 800);
    cout<<Preso.getDeck().changeCard(1, MC20)<<endl;
    cout<<Preso.getDeck().changeCard(1, MC2)<<endl;
    cout<<Preso.getDeck().changeCard(5, MC2)<<endl;
    cout<<Preso.getDeck().changeCard(7, MA5)<<endl;

    Duelist Preso_copy("Preso copy");
    Preso_copy.getDeck().setDeckname("Preso copy deck");
    cout<<Preso_copy.getDeck().changeCard(1, MC20)<<endl;
    cout<<Preso_copy.getDeck().addCard(MC20)<<endl;
    cout<<Preso_copy.getDeck().changeCard(0, MC20)<<endl;
    cout<<Preso_copy.getDeck().changeCard(0, MC3)<<endl;

    cout<<"\n||||| SHUFFLE TEST |||||\n";
    Preso.getDeck().shuffleDeck();
    cout<<Preso<<endl;


    cout<<"\n||||| LOAD/SAVE TEST |||||\n";
    Preso.saveDeck("TXT_CARDS.txt");
    Preso_copy.loadDeck("TXT_CARDS.txt");

    cout<<Preso_copy<<endl;

    cout<<"||||| DUEL TEST |||||\n";

    Duelist::duel(Preso_copy, Preso);

    //Preso.duel(Preso_copy);


    return 0;



}
