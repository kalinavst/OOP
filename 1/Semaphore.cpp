#include "Semaphore.hpp"

Semaphore::Semaphore():LimitedTwowayCounter(0,1,0,1)
{
}

Semaphore::Semaphore(bool k) 
{
	if (k == true)LimitedTwowayCounter(0, 1, 1, 1);
	else LimitedTwowayCounter(0, 1, 0, 1);
}

bool Semaphore::isAvailable() const
{
	if (this->getTotal() > 0)return 1;
	return false;
}

void Semaphore::wait()
{
	this->decrement();
}

void Semaphore::signal()
{
	this->increment();
}
