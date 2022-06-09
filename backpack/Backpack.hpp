/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalina Stoimenova
* @idnumber 62636
* @task 1
* @compiler VC
*/

#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include"Materials.hpp"
#include"Money.hpp"
const int SLOTS= 16,SPACES=21;
void print(char k[SLOTS][SPACES]) {
	for (int i = 0; i < SLOTS; i++) {
		for (int j = 0; j < SPACES; j++) {
			std::cout << k[i][j] << ",";
		}
		std::cout << std::endl;
	}

}



template<class T>



class Backpack {
private:
	
	unsigned int gold = 0,silver=0;
	char slots[SLOTS][SPACES];
	std::vector<T>things;

public:
	Backpack();
	Backpack(std::vector<T>start);
	bool IsEmpty() const;
	bool IsFull() const;
	void Erase();
	void Add(T m);
	unsigned int GetSilver();
	unsigned int GetGold();
	bool Remove( T& M);
	int TakenSlots() const;
	void printSlots() ;

};

template<class T>
inline Backpack<T>::Backpack()
{
	if (typeid(T) == typeid(Money)) {
		gold = 0;
		silver = 0;
	}
	else {
		for (int i = 0; i < 16; i++) 
		{
			for (int j = 0; j < 20; j++)
			{
				slots[i][j] = ' ';
			}
			slots[i][20] = '\0';
		}
	}

	std::vector<T>things;
}

template<>
inline Backpack<Money>::Backpack(std::vector<Money> start)
{
	
		things = start;
		for (int i = 0; i < things.size(); i++) {
			gold += things[i].GetGold();
			if (silver + things[i].GetSilver() >= 100) {
				silver = (silver + things[i].GetSilver()) % 100;
				gold++;
			}
			else silver += things[i].GetSilver();
		}

}
template<>
inline Backpack<Materials>::Backpack(std::vector<Materials>start) {
	things = start;
	for (int k = 0; k < start.size(); k++)
	{
		while (start[k].GetHerbs() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'h'||slots[i][0]==' ') {
					for (int j = 0; j < 20; j++) {
						if (slots[i][j] == ' ') 
						{
							slots[i][j] = 'h';
							start[k].SetHerbs(start[k].GetHerbs() - 1);

						}
					}
				}
			}
		}

		while (start[k].GetCloth() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'c' || slots[i][0] == ' ') {
					for (int j = 0; j < 20; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'c';
							start[k].SetCloth(start[k].GetCloth() - 1);

						}
					}
				}
			}
		}

		while (start[k].GetOres() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'o' || slots[i][0] == ' ') {
					for (int j = 0; j < 20; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'o';
							start[k].SetOres(start[k].GetOres() - 1);

						}
					}
				}
			}
		}
		while (start[k].GetEssence() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'e' || slots[i][0] == ' ') {
					for (int j = 0; j < 10; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'e';
							start[k].SetHerbs(start[k].GetHerbs() - 1);

						}
					}
				}
			}
		}


	}
}

template<class T>
inline bool Backpack<T>::IsEmpty() const
{
	if (things.size() == 0)return 1;
	for (int i = 0; i < 16; i++) {
		if (slots[i][0] != ' ')return 0;
}
}

template<class T>
inline bool Backpack<T>::IsFull() const
{
	if (things.size() == 0)return 0;
	for (int i = 0; i < 16; i++) {
		if (slots[i][0] == ' ')return 0;
		return false;
	}
	return 1;
}

template<class T>
inline void Backpack<T>::Erase()
{
	things.clear();
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			slots[i][j] = ' ';
		}
		slots[i][20] = '\0';
	}

}

template<class T>
inline void Backpack<T>::Add(T m)
{
	things.push_back(m);
}

template<class T>
inline unsigned int Backpack<T>::GetSilver()
{
	return silver;
}

template<class T>
inline unsigned int Backpack<T>::GetGold()
{
	return gold;
}

template<class T>
inline int Backpack<T>::TakenSlots() const
{
	int br = 0;
	if (typeid(T) == typeid(Money))return 0;
	else {
		for (int i = 0; i < 16; i++) {
			if (slots[i][0] != ' ')br++;
		}
		return br;
	}
}

template<class T>
inline void Backpack<T>::printSlots() 
{
	print(slots);
}

template<>
inline bool Backpack<Materials>::Remove( Materials& m)
{if(IsEmpty())
	return false;
else {
	while (m.GetHerbs() != 0) {
		for (int i = 0; i < 16; i++) {
			if (slots[i][0] == 'h' ) {
				for (int j = 19; j > 0; j--) {
					if (slots[i][j] != ' ')
					{
						slots[i][j] = ' ';
						m.SetHerbs(m.GetHerbs() - 1);

					}
				}
			}
			if (i == 15 && m.GetHerbs() != 0)return 0;
		}
	}

	while (m.GetCloth() != 0) {
		for (int i = 0; i < 16; i++) {
			if (slots[i][0] == 'c' ) {
				for (int j = 19; j > 0; j--) {
					if (slots[i][j] != ' ')
					{
						slots[i][j] = ' ';
						m.SetCloth(m.GetCloth() - 1);

					}
				}
			}
			if (i == 15 && m.GetCloth() != 0)return 0;
		}
	}
	while (m.GetOres() != 0) {
		for (int i = 0; i < 16; i++) {
			if (slots[i][0] == 'o' ) {
				for (int j = 19; j > 0; j--) {
					if (slots[i][j] != ' ')
					{
						slots[i][j] = ' ';
						m.SetOres(m.GetOres() - 1);

					}
				}
			}if (i == 15 && m.GetOres() != 0)return 0;
		}
	}


	while (m.GetEssence() != 0) {
		for (int i = 0; i < 16; i++) {
			if (slots[i][0] == 'e' ) {
				for (int j = 10; j > 0; j--) {
					if (slots[i][j] != ' ')
					{
						slots[i][j] = ' ';
						m.SetEssence(m.GetEssence() - 1);

					}
				}
			}
			if (i == 15 && m.GetEssence() != 0)return 0;
		}
	}





}
}

template<>
inline bool Backpack<Money>::Remove( Money& M)
{
	if (gold < M.GetGold())return 0;
	if (M.GetSilver() > silver) {
		if (gold > 0) {
			gold--;
			silver += 100;
			silver -= M.GetSilver();
		}
		else return 0;
	}
	else {
		gold -= M.GetGold();
		silver -= M.GetSilver();
	}


	
}


template<>
inline void Backpack<Money>::Add(Money m)
{
	gold += m.GetGold();
	if (silver + m.GetSilver() >= 100) {
		silver = (silver + m.GetSilver()) % 100;
		gold++;
	}
	else silver +=m.GetSilver();
	things.push_back(m);


}

template<>
inline void Backpack<Materials>::Add(Materials m) {
	if (!IsFull()) {
		things.push_back(m);
		while (m.GetHerbs() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'h' || slots[i][0] == ' ') {
					for (int j = 0; j < 20; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'h';
							m.SetHerbs(m.GetHerbs() - 1);

						}
					}
				}
			}
		}

		while (m.GetCloth() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'c' || slots[i][0] == ' ') {
					for (int j = 0; j < 20; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'c';
							m.SetCloth(m.GetCloth() - 1);

						}
					}
				}
			}
		}
		while (m.GetOres() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'o' || slots[i][0] == ' ') {
					for (int j = 0; j < 20; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'o';
							m.SetOres(m.GetOres() - 1);

						}
					}
				}
			}
		}


		while (m.GetEssence() != 0) {
			for (int i = 0; i < 16; i++) {
				if (slots[i][0] == 'e' || slots[i][0] == ' ') {
					for (int j = 0; j < 10; j++) {
						if (slots[i][j] == ' ')
						{
							slots[i][j] = 'e';
							m.SetEssence(m.GetEssence() - 1);

						}
					}
				}
			}
		}

	}
	else std::cout << "The backpack is full";
}
