#include <iostream>
#include <stdexcept>
#include <string>

class ConfigLoader
{
public:
    ConfigLoader() {};
	bool load(std::string filename);
private:

};

class ConfigError : public std::logic_error
{
	public:
		ConfigError(std::string message) : std::logic_error(message) {};
};

bool ConfigLoader::load(std::string filename)
{
    if (filename.empty())
    {
        throw std::invalid_argument("Filename is empty.");
    }
	if (filename.find(".cfg") == std::string::npos || filename.length() < 4) // not a .cfg file
	{
		throw std::invalid_argument("File is not a .cfg file");
	}
	if (filename == "missing.cfg")		// can't be opened
	{
		throw std::runtime_error("File cannot be opened");
	}
	if (filename == "invalid.cfg")		// invalid configuration
	{
		throw ConfigError("File has invalid configuration");
	}
    return true;
}

int main()
{
    ConfigLoader loader;

    // good path
    if (loader.load("test.cfg"))
    {
        std::cout << "Good path is working" << std::endl;
    }

    try
    {
        loader.load("");
    }
    catch (const std::invalid_argument& exception)
    {
        std::cout << "Catch-Block 1: " << exception.what() << std::endl;
    }

    try
    {
        loader.load("test.txt");
    }
    catch (const std::invalid_argument& exception)
    {
        std::cout << "Catch-Block 2: " << exception.what() << std::endl;
    }

    try
    {
        loader.load("missing.cfg");
    }
    catch (const std::runtime_error& exception)
    {
        std::cout << "Catch-Block 3: " << exception.what() << std::endl;
    }

    try
    {
        loader.load("invalid.cfg");
    }
    catch (const std::logic_error& exception)
    {
        std::cout << "Catch-Block 4: " << exception.what() << std::endl;
    }
    // catches all remaining exceptions
    catch (const std::exception& exception)
    {
        std::cout << "Gonna catch em all: " << exception.what() << std::endl;
    }
}