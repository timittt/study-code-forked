#include "pair.hpp"

int main()
{
	Pair p("Braun", 3.3);
	std::cout << p.getA() << p.getB() << std::endl;
	std::cout << "Ende" << std::endl;
}