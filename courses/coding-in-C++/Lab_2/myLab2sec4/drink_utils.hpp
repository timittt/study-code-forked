#ifndef DRINK_UTILS_HPP
#define DRINK_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdint>

std::string DEFAULT_NAME = "PLACEHOLDER";
constexpr int DEFAULT_SUGAR = 0;
constexpr int DEFAULT_TEMPERATURE = 25;
constexpr bool DEFAULT_MILK = false;

constexpr int MAX_SUGAR_AMOUNT = 100;
constexpr int MAX_TEMPERATURE = 100;

class DrinkBuilder
{
public:
	DrinkBuilder();
	~DrinkBuilder();
	DrinkBuilder& setName(const std::string& name);
	DrinkBuilder& setSugar(int sugar);
	DrinkBuilder& setTemperature(int temperature);
	DrinkBuilder& setMilk(bool withMilk);
	void print() const;
	bool isValid() const;

private:
	std::string name;
	int sugar;
	int temperature;
	bool withMilk;
};

DrinkBuilder::DrinkBuilder()
	: name{ DEFAULT_NAME }, sugar{ DEFAULT_SUGAR }, temperature{ DEFAULT_TEMPERATURE }, withMilk{ DEFAULT_MILK } {
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
	std::cout << std::left << std::setw(CELL_WIDTH) << "Sugar:" << std::right << std::setw(CELL_WIDTH) << sugar << std::endl;
	std::cout << std::left << std::setw(CELL_WIDTH) << "Temperature:" << std::right << std::setw(CELL_WIDTH) << temperature << std::endl;
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

#endif // !DRINK_UTILS_HPP