#include "Developer.hpp"
#include"TeamLead.hpp"

Developer::Developer(const std::string& name)
{
	this->name = name;
	this->salary = 0.0;
	this->teamlead = nullptr;
}

std::string Developer::getName() const
{
	return name;
}

double Developer::getSalary() const
{
	return salary;
}

TeamLead* Developer::getTeamLead() const
{
	return teamlead;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0.0)salary = amount;
}

void Developer::sendLeavingRequest()
{
	if (teamlead != nullptr) {
		LeavingRequest leave(name);

		teamlead->addLeavingRequest(leave);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (teamlead != nullptr) {
		PromotionRequest promotionreq(name, amount);
		teamlead->addPromotionRequest(promotionreq);
	}
}

void Developer::increaseSalary(double amount)
{
	salary += amount;
}

void Developer::decreaseSalary(double amount)
{
	salary -= amount;
}

void Developer::setTeamLead( TeamLead* boss)
{
	teamlead = boss;
}
