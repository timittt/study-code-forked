#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

template<typename T, typename U>

class Pair // pair of two values a and b
{
private:
	T a;
	U b;
public:
	Pair(T value1, U value2)
		: a(value1), b(value2) {};
	T getA() const
	{
		return a;
	}
	U getB() const
	{
		return b;
	}
	void setA(T value1)
	{
		this->a = value1;
	}
	void setB(U value2)
	{
		this->b = value2;
	}
};

#endif // 
