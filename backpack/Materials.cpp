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

#include "Materials.hpp"

Materials::Materials()
{
	herbs = 0;
	ores = 0;
	cloth = 0;
	essence = 0;
	type = "";
}
//type,herbs,ores,cloth,essence
Materials::Materials(std::string Type, int Herbs, int Ores, int Cloth, int Essence)
{
	type = Type;
	herbs = Herbs;
	ores = Ores;
	cloth = Cloth;
	essence = Essence;
}

int Materials::GetHerbs() const
{
	return herbs;
}

int Materials::GetOres() const
{
	return ores;
}

int Materials::GetCloth() const
{
	return cloth;
}

int Materials::GetEssence() const
{
	return essence;
}

std::string Materials::GetType() const
{
	return type;
}

void Materials::SetHerbs(const int& h)
{
	herbs = h;
}

void Materials::SetOres(const int& o)
{
	ores = o;
}

void Materials::SetCloth(const int& c)
{
	cloth = c;
}

void Materials::SetEssence(const int& e)
{
	essence = e;
}

void Materials::SetType(const std::string& typ)
{
	type = typ;
}


