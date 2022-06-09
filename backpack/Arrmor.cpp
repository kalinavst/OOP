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

#include "Arrmor.hpp"
#include <cstring>
#include <vector>
# include < utility >
#include <iostream>


Arrmor::Arrmor()
{
    Type = cloth;
    deffence = 0;
    std::vector<std::pair <std::string, int >> effects;
}

Arrmor::Arrmor(std::string Name, type type1, double deff, std::vector<std::pair<std::string, double>> effect)
{
    name = Name;
    Type = type1;
    deffence = deff;
    effects = effect;
}

void Arrmor::ChangeType(type newType)
{
    Type = newType;
}



double Arrmor::GearScore() const
{
    double score = 0;
    for (int i = 0; i < effects.size(); i++) 
    {
        score += effects[i].second;
    }
    return score;
}

void Arrmor::addEffect(std::pair<std::string, double>neweffect)
{
    for (int i = 0; i < effects.size(); i++) {
        if (neweffect.first == effects[i].first)
        {
            effects[i].second = neweffect.second;
            return;
        }
        effects.push_back(neweffect);
    }
}



void Arrmor::RemoveEffect(std::pair<std::string, double> Effect)
{
    for (int i = 0; i < effects.size(); i++) {
        if (effects[i] == Effect)effects.erase(effects.begin() + i);
    }
}

Arrmor& Arrmor::operator=(const Arrmor& from)
{
    this->Type = from.Type;
    this->deffence = from.deffence;
    this->name = from.name;
    this->effects = from.effects;
    return *this;
}

bool Arrmor::operator==(const Arrmor& to) const
{
    return (this->name == to.name);
}

int Arrmor::GetDeffence() const
{
    return deffence;
}

std::vector<std::pair<std::string, double>> Arrmor::GetEffects() const
{
    return effects;
}

std::string Arrmor::GetName() const
{
    return name;
}

type Arrmor::GetType() const
{
    return Type;
}

void Arrmor::SetDeffence(const int& def)
{
    deffence = def;
}

void Arrmor::SetName(const std::string& N)
{
    name = N;
}

void Arrmor::SetType(const type& typ)
{
    Type = typ;
}

void Arrmor::SetEffects(const std::vector<std::pair<std::string, double>>& eff)
{
    effects = eff;
}
