#pragma once
#include"SectionVotes.hpp"
#include <vector>
#include<cstring>
#include <fstream>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{
    std::vector<SectionVotes> sections;

public:
    ElectionResultsDatabase();

    void addResultsFromFile(const char* filename);
    void addResultsToFile(const char* filename);
    int numberOfSections() const;
    void AddSection(const SectionVotes&);

    int votesForParty(Party) const;

    Party winningParty() const;
    friend std::ostream& operator<<(std::ostream&, const ElectionResultsDatabase&);
    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
};