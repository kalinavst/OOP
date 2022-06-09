#include "ElectionResultsDatabase.hpp"

ElectionResultsDatabase::ElectionResultsDatabase()
{
	std::vector<SectionVotes> sections;
}

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::ifstream filefrom;
	filefrom.open(filename);
	if (filefrom) {
		while (!filefrom.eof()) {
			SectionVotes s;
			filefrom >> s;
			sections.push_back(s);


		}filefrom.close();
	}
	else return;
	
}

void ElectionResultsDatabase::addResultsToFile(const char* filename)
{
	std::ofstream file;
	file.open(filename, std::ios::app);
	for (int i = 0; i < sections.size(); i++) {
		file << sections[i];
	}
	file.close();
	
}

int ElectionResultsDatabase::numberOfSections() const
{
	int number = 0;
	Party p1 (PARTY1),p2(PARTY2),p3(PARTY3);

	for (int i = 0; i < sections.size(); i++) {
		if (sections[i].votesForParty(p1) == 0 &&sections[i].votesForParty(p2) == 0&& sections[i].votesForParty(p3) == 0) number++;
	}
	return sections.size()-number;
}

void ElectionResultsDatabase::AddSection(const SectionVotes& ns)
{
	sections.push_back(ns);
}

int ElectionResultsDatabase::votesForParty(Party p1) const
{
	int allVotes = 0;
	for (int i = 0; i < sections.size(); i++)
	{
		allVotes += sections[i].votesForParty(p1);
	}return allVotes;
}

Party ElectionResultsDatabase::winningParty() const
{
	Party p1(PARTY1), p2(PARTY2), p3(PARTY3);
	
	int votes1 = votesForParty(p1), votes2 =votesForParty(p2), votes3 =votesForParty(p3);
	
	if (votes1 >=votes2 && votes1 >=votes3)return p1;
	if (votes2 >= votes3 && votes2 >= votes1)return p2;
	if (votes3 >= votes2 && votes3 >= votes1)return p3;
	
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& from)
{
	for (int i = 0; i < from.sections.size(); i++) {
		out << from.sections[i];
	}
	return out;
}

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& database)
{
	SectionVotes location;
	while (input >> location) {
		database.sections.push_back(location);
	}
	return input;
}
