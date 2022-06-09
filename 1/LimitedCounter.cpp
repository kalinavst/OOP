#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter():Counter(),max(1)
{
}

LimitedCounter::LimitedCounter(const int max) : Counter(), max(max)
{
}

LimitedCounter::LimitedCounter(const int max, const int initial):Counter(initial),max(max)
{
}

LimitedCounter::LimitedCounter(const int max, const int initial, const unsigned step) : Counter(initial, step), max(max)
{
}

void LimitedCounter::increment()
{
	if (this->value + (int)this->step <=this->max)
	{
		value+=step;
	}
	
}

int LimitedCounter::getMax() const
{
	return max;
}
