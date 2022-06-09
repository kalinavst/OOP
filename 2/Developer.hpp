#pragma once
#include <cstring>
#include<iostream>
//#include"TeamLead.hpp"
#include"PromotionRequest.hpp"
#include"LeavingRequest.hpp"
class TeamLead;
class Developer {
public:
	Developer(const std::string& name);
	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void increaseSalary(double amount);
	void decreaseSalary(double amount);
	void setTeamLead( TeamLead* boss);
protected:
	std::string name;
	double salary;
	TeamLead* teamlead;
};