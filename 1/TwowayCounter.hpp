#pragma once
#include "Counter.hpp"

class TwowayCounter :public Counter {
public:
	TwowayCounter();
	TwowayCounter( const int initial);
	TwowayCounter(const int initial, const  unsigned step);
	void decrement();
	

};