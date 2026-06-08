#include <iostream>
#include <stdexcept>
#include <string>

class Sensor
{
public:
	Sensor(const std::string& name, double initvalue, double min, double max);
	~Sensor() = default;
	void update_value(const double new_value);
	double get_value() const { return this->value; };
	void print_info() const;
	void simulate_failure() const;
private:
	std::string name;
	double value;
	double MIN_VALUE;
	double MAX_VALUE;
};