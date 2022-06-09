#include "SectionVotes.hpp"

SectionVotes::SectionVotes()
{
	
	votes[0] = 0, votes[1] = 0, votes[2] = 0;
}

SectionVotes::SectionVotes(int party1Votes=0, int party2Votes=0, int party3Votes=0)
{
	votes[0] = party1Votes;
	votes[PARTY2] = party2Votes;
	votes[PARTY3] = party3Votes;
}

int SectionVotes::votesForParty(Party x) const
{
	return votes[x];
}

void SectionVotes::SetVotesForParty(Party p1, int voteNuber)
{
	votes[p1] = voteNuber;
}

SectionVotes& SectionVotes::operator=(const SectionVotes& to)
{
	for (int i = 0; i < 3; i++) {
		this->votes[i] = to.votes[i];
}
	return *this;
}



std::istream& operator>>(std::istream&input, SectionVotes& location)
{
	int v1=0, v2=0, v3=0;
	input >> v1 >> v2 >> v3;
	location = SectionVotes(v1, v2, v3);
	return input;
}

std::ostream& operator<<(std::ostream& output, const SectionVotes& from)
{
	return output << from.votes[0] << " " << from.votes[1] << " " << from.votes[2]<<std::endl;
}
