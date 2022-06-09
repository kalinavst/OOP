#pragma once
#include "LimitedTwowayCounter.hpp"
class Semaphore: public LimitedTwowayCounter {
public:
	Semaphore();
	Semaphore(bool);
	bool isAvailable() const;
	void wait();
	void signal();



};