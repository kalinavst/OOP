#pragma once
#include <iostream>
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
    int votes[3];


public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;
    void SetVotesForParty(Party p1,int voteNuber);

    SectionVotes& operator=(const SectionVotes& to);

   friend std::istream&operator>>(std::istream&, SectionVotes&);
   friend std::ostream& operator<<(std::ostream& , const SectionVotes& );
};
