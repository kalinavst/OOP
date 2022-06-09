#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, const double salary):Developer(name){
	
	this->salary = salary;
	teamlead = this;
}

std::vector<Developer*> TeamLead::getTeam()
{
	return this->developers;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr) {
		developer->setInitialSalary(salary);
		developer->setTeamLead(this);
		developers.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	int position = 0;
	for (int i = 0; i < developers.size(); i++) {
		if (developers[i]->getName() == name)position = i;

}
	TeamLead* d1 = nullptr;
	developers[position]->setTeamLead(d1);
	developers.erase(developers.begin() + position);
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < developers.size(); i++) {
		developers[i]->increaseSalary(amount);
}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < developers.size(); i++) {
		developers[i]->decreaseSalary(amount);
}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	WantsToLeave.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	WantsMoreMoney.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < WantsToLeave.size(); i++) {
		this->removeDeveloperFromTeam(WantsToLeave[i].getSender());


	}
	WantsToLeave.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < WantsMoreMoney.size(); i++) {
		for (int j = 0; j < developers.size(); j++) {
			if (WantsMoreMoney[i].getSender() == developers[i]->getName()) {
				developers[j]->increaseSalary(WantsMoreMoney[i].getAmount());
			}
		}
}
	WantsMoreMoney.clear();
}
