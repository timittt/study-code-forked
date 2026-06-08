#include "greenhouse.hpp"

class init_fail : public std::invalid_argument
{
public:
	explicit init_fail(const std::string& message) : std::invalid_argument(message)
	{
	};
	~init_fail() = default;
};

class min_max_error : public std::invalid_argument
{
public:
	explicit min_max_error(const std::string& message) : std::invalid_argument(message)
	{
	};
	~min_max_error() = default;
};

class SensorFailureError : public std::exception
{
public:
	const char* what() const override
	{
		return "Sensor is unreachable";
	}
	~SensorFailureError() = default;
};


Sensor::Sensor(const std::string& name, double initvalue, double min, double max)
{
	if (name == "")
	{
		throw std::invalid_argument("Not a valid name");
	}
	if (max < min)
	{
		throw min_max_error(name);
	}
	if (initvalue < min || initvalue > max)
	{
		throw init_fail(name);
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
		throw std::out_of_range(this->name);
	}
	this->value = new_value;
}

void Sensor::print_info() const
{
	std::cout << "Sensor: " << name << " | Current value: " << value << std::endl;
}

void Sensor::simulate_failure() const
{
	throw SensorFailureError();
}

int main()
{
	/* Old version
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
	*/
	Sensor thermo("Thermometer", 25.0, -273.15, 1000.0);
	try 
	{
		thermo.simulate_failure();
		thermo.update_value(-300.0);
		Sensor hygro("Luftfeuchtigkeit", 0.0, 111.1, 100.0);
		Sensor baro("Luftdruck", 450.0, 500.0, 400.0);
		Sensor noname("", 450.0, 500.0, 4000.0);
	}
	catch(const SensorFailureError& e)
	{
		std::cout << "Sensor Failure Error: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Error out of range: " << e.what() << std::endl;
	}
	catch (const min_max_error& e)
	{
		std::cout << "MinMaxError creating a sensor: " << e.what() << std::endl;
	}
	catch (const init_fail& e)
	{
		std::cout << "Error with initializing value at a sensor: " << e.what() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Naming error creating a sensor: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Some error occured: " << e.what() << std::endl;
	}
	// good path
	thermo.print_info();
	Sensor hygro("Luftfeuchtigkeit", 0.0, 0.0, 100.0);
	hygro.print_info();
	Sensor baro("Luftdruck", 1013.0, 0.0, 2000.0);
	baro.print_info();
}