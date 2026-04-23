#include <iostream>
#include "drink_utils.hpp"

int main()
{
	DrinkBuilder myDrink;
	myDrink.setName("Cocoa");
	myDrink.setSugar(100);
	myDrink.setTemperature(67);
	myDrink.setMilk(true);
		
	if (myDrink.isValid())
	{
		myDrink.print();
	}
	else
	{
		std::cout << "Invalid Drink Configuration." << std::endl;
	}
}