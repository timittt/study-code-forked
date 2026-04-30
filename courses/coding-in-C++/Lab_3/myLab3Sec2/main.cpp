#include <iostream>
#include <string>

class User
{
public:
	User(std::string name, int id)
		: name(name), id(id) 
	{};
	void printInfo();

protected:
	std::string name;
	int id;
};
	
void User::printInfo()
{
	std::cout << "Username: " << name << std::endl;
	std::cout << "User ID: " << id << std::endl << std::endl;
}

class Student : public User
{
private:
	int year;
public:
	Student(std::string name, int id, int year)
		: User(name, id), year(year) {}
	void printRole()
	{
		std::cout << "Role: Student" << std::endl;
		std::cout << "Year: " << year << std::endl;
	}
};

class Instructor : public User
{
private:
	std::string title;
public:
	Instructor(std::string name, int id, std::string title)
		: User(name, id), title(title) {
	}
	void printRole()
	{
		std::cout << "Role: Instructor" << std::endl;
		std::cout << "Title: " << title << std::endl;
	}
};

int main()
{
	User user1("Daniel Weimer", 44352);
	Student student1("Andrew Volle", 67420, 2025);
	Instructor teacher1("Philipp Hasselbach", 9962, "Prof. Dr.");
	user1.printInfo();
	student1.printRole(), student1.printInfo();
	teacher1.printRole(), teacher1.printInfo();
}