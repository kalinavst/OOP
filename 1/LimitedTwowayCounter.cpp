#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter():LimitedCounter(),min(0)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(const int min, const int max): LimitedCounter(max),min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(const int min, const int max, const int initial):LimitedCounter(max,initial),min(min){}

LimitedTwowayCounter::LimitedTwowayCounter(const int min, const int max, const int initial, const unsigned step):LimitedCounter(max,initial,step),min(min)
{
}

void LimitedTwowayCounter::decrement()
{
	if (this->getTotal() - (int)this->getStep() >= this->getMin())this->value-=step;
}

int LimitedTwowayCounter::getMin() const
{
	return this->min;
}
