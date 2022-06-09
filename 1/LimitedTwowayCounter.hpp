#pragma once
# include "LimitedCounter.hpp"
#include"TwowayCounter.hpp"


class LimitedTwowayCounter: public LimitedCounter{
public:
	LimitedTwowayCounter();
	LimitedTwowayCounter(const int min, const int max);
	LimitedTwowayCounter(const int min, const int max, const int initial);
	LimitedTwowayCounter(const int min, const int max, const int initial, const unsigned step);

	void decrement();
	int getMin() const;

private:
	int min;


};