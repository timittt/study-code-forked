#include "greenhouse.hpp"

Sensor::Sensor(const std::string& name, double initvalue, double min, double max)
{
	if (name == "")
	{
		throw std::invalid_argument("Not a valid name");
	}
	if (initvalue < min || initvalue > max)
	{
		throw std::invalid_argument("Impossible initialization value");
	}
	if (max < min)
	{
		throw std::invalid_argument("Minimum is greater than maximum");
	}
	this->name = name;
	this->value = initvalue;
	this->MIN_VALUE = min;
	this->MAX_VALUE = max;
}

void Sensor::update_value(const double new_value)
{
	if (new_value < MIN_VALUE || new_value > MAX_VALUE)
	{
		throw std::out_of_range("Impossible Value");
	}
	this->value = new_value;
}

void Sensor::print_info() const
{
	std::cout << "Sensor: " << name << " | Current value: " << value << std::endl;
}

int main()
{
	Sensor thermo("Thermometer", 25.0, -273.15, 1000.0);
	try
	{
		thermo.update_value(-300.0);
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "Catch-Block 1: " << exception.what() << std::endl;
	}
	try
	{
		Sensor hygro("Luftfeuchtigkeit", 0.0, 111.1, 100.0);
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "Catch-Block 2: " << exception.what() << std::endl;
	}
	try
	{
		Sensor baro("Luftdruck", 450.0, 500.0, 400.0);
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "Catch-Block 3: " << exception.what() << std::endl;
	}
	try
	{
		Sensor noname("", 450.0, 500.0, 4000.0);
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "Catch-Block 4: " << exception.what() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << "Catch all: " << exception.what() << std::endl;
	}

	// good path
	thermo.print_info();
	Sensor hygro("Luftfeuchtigkeit", 0.0, 0.0, 100.0);
	hygro.print_info();
	Sensor baro("Luftdruck", 1013.0, 0.0, 2000.0);
	baro.print_info();
}