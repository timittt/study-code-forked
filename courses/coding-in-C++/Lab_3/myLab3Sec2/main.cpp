#include <iostream>
#include <string>

class User
{
public:
	User(std::string name, int id);
	void printInfo();

protected:
	std::string name;
	int id;
};

User::User(std::string name, int id) // Constructor
	: name{name}, id{id} { }

void User::printInfo()
{
	std::cout << "Username: " << name << std::endl;
	std::cout << "User ID: " << id << std::endl;
}

class Student : public User
{
public:
	Student(std::string name, int id) : Base(name, id)
};

int main()
{
    std::cout << "Hello World!\n";
}
