#include <iostream>

class Display
{
public:
    void show_temperature(float value)
    {
        std::cout << "Display: " << value << " C\n";
    }
};

class Logger
{
public:
    void log_temperature(float value)
    {
        std::cout << "Logger: " << value << " C\n";
    }
};

class Alarm
{
public:
    void print_warning(float temperature) const;
};

void Alarm::print_warning(float temperature) const
{
    if (temperature > 30.0)
    {
        std::cout << "ALARM: Temperature " << temperature << " too high!\n";
    }
}

class TemperatureSensor
{
private:
    float temperature = 0.0f;

    Display display;
    Logger logger;
    Alarm temp_alarm;

public:
    void set_temperature(float value)
    {
        temperature = value;

        // directly coupled to other classes
        display.show_temperature(temperature);
        logger.log_temperature(temperature);
        temp_alarm.print_warning(temperature);
    }
};
/*
int main()
{
    TemperatureSensor sensor;

    sensor.set_temperature(23.5f);

    return 0;
}*/