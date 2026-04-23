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

#endif // !DRINK_UTILS_HPP