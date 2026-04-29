#include "drink_utils.hpp"

DrinkBuilder::DrinkBuilder()
	: name{ "PLACEHOLDER" }, sugar{ DEFAULT_SUGAR }, temperature{ DEFAULT_TEMPERATURE }, withMilk{ DEFAULT_MILK } {
}

DrinkBuilder& DrinkBuilder::setName(const std::string& name)
{
	this->name = name;
	return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(const int sugar)
{
	this->sugar = sugar;
	return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature(const int temperature)
{
	this->temperature = temperature;
	return *this;
}

DrinkBuilder& DrinkBuilder::setMilk(const bool withMilk)
{
	this->withMilk = withMilk;
	return *this;
}

void DrinkBuilder::print() const
{
	const int CELL_WIDTH = 12;
	std::cout << "+++DRINK  INFORMATION+++\n\n";
	std::cout << std::left << std::setw(CELL_WIDTH) << "Drink:" << std::right << std::setw(CELL_WIDTH) << name << std::endl;
	std::cout << std::left << std::setw(CELL_WIDTH) << "Sugar:" << std::right << std::setw(CELL_WIDTH) << static_cast<int>(sugar) << std::endl;
	std::cout << std::left << std::setw(CELL_WIDTH) << "Temperature:" << std::right << std::setw(CELL_WIDTH) << static_cast<int>(temperature) << std::endl;
	std::cout << std::left << std::setw(CELL_WIDTH) << "Milk:" << std::right << std::setw(CELL_WIDTH) << (withMilk ? "Yes" : "No") << std::endl;
}

bool DrinkBuilder::isValid() const
{
	if (name == "PLACEHOLDER")
	{
		return false;
	}
	if (sugar < 0 || sugar > MAX_SUGAR_AMOUNT)
	{
		return false;
	}
	if (temperature < 0 || temperature > MAX_TEMPERATURE)
	{
		return false;
	}
	return true;
}