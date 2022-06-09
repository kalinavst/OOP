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

#include <cstring>
#include <vector>
# include < utility >
#include <iostream>
#include"Weapon.hpp"



Weapon::Weapon()
{
    Name = "";
    type = one_handed;
    KindOfWeapon = "";
    hitDamage[0] = 0;
    hitDamage[1] = 0;
    std::vector<std::pair <std::string, double >> effects;
}

Weapon::Weapon(std:: string name,WeaponType type1, std::string kind, double minDamage, double MaxDamage, std::vector<std::pair <std::string, double >> effect)
{
    Name = name;
    type = type1;
    KindOfWeapon = kind;
    hitDamage[0] = minDamage;
    hitDamage[1] = MaxDamage;
    effects = effect;


}

std::string Weapon::GetName() const
{
    return Name;
}

WeaponType Weapon::Gettype() const
{
    return type;
}

std::string Weapon::GetKindOfWeapon() const
{
    return KindOfWeapon;
}

double* Weapon::GethitDamage()
{
    double* help=new double[2];
    help[0] = hitDamage[0];
    help[1] = hitDamage[1];
    return help;
}

std::vector<std::pair<std::string, double>> Weapon::Geteffects()
{
    return effects;
}

int Weapon::SlotsTaken() const
{
    if (type == one_handed)return 1;
    else return 2;
}

double Weapon::WeaponScore()
{
    double sum = 0.0;
    for (int i = 0; i < effects.size(); i++)
    {
        sum += effects[i].second;

    }
    if (type == one_handed)sum *= 0.75;
    else sum *= 1.5;
    return sum;

}

void Weapon::ChangeKind(std::string newKind)
{
    if (newKind == "saff" && type == one_handed)std::cout << "A saff can't be a one handed weapon.";
    else
        if (newKind == "dagger" && type == two_handed)std::cout << "A dagger is a one handed weapon.";
        else KindOfWeapon = newKind;
  



}

void Weapon::ChangeType(WeaponType typ)
{
    if (typ == one_handed && KindOfWeapon == "saff")std::cout << "A saff can't be a one handed weapon.";
    else if (typ == two_handed && KindOfWeapon == "dagger")std::cout << "A dagger can't be a two handed weapon.";
    else type = typ;
}

void Weapon::ChangePower(std::pair<std::string, double> Effect, double newpower)
{
    for (int i = 0; i < effects.size(); i++) {
        if (effects[i] == Effect)effects[i].second = newpower;
    }
}

bool Weapon::operator==(const Weapon& to) const
{
    return this->Name==to.Name;
}

    void Weapon::RemoveWeaponEffect(std::pair<std::string, double> Effect)
    {
        for (int i = 0; i < effects.size(); i++) {
            if (effects[i] == Effect)effects.erase(effects.begin() + i);
        }
    }
    void Weapon::AddWeaponEffect(std::pair<std::string, double> newEffect)
    {
        for (int i = 0; i < effects.size(); i++)
        {
            if (effects[i].first == newEffect.first)
            {
                effects[i].second = newEffect.second; return;
            }
            effects.push_back(newEffect);

        }
    }