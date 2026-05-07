#include <iostream>
#include <cmath>

class Shape
{
public:
	virtual ~Shape() {};			// Virtual as Shape is a polymorphic base class
	virtual double getArea() const = 0;	// Virtual as each shape uses different formulas for area calculation
};
/* Made getArea() pure virtual
double Shape::getArea() const
{
	return 0.0;
}
*/

class Circle : public Shape
{
private:
	double r;
public:
	Circle(double radius) : r(radius) {};
	~Circle() {};
	double getArea() const override;	// Circle::getArea() has a different behavior than Shape::getArea()
};

double Circle::getArea() const
{
	return 3.14 * r * r;
}

class Rectangle : public Shape
{
private:
	double a;
	double b;
public:
	Rectangle(double length, double width) : a(length) ,b(width) {};
	~Rectangle() {};
	double getArea() const override;	// Rectangle::getArea() has a different behavior than Shape::getArea()
};

double Rectangle::getArea() const
{
	return a * b;
}

int main()
{
	Circle c1(1.0);
	Circle c2(2.5);
	//std::cout << c1.getArea() << std::endl;
	Rectangle r1(2.5, 1.2);
	Rectangle r2(1.3, 6.7);
	//std::cout << r1.getArea() << std::endl;

	Shape* array[4] = { &c1, &c2, &r1, &r2 };

	for (int i = 0; i < 4; i++)
	{
		std::cout << array[i]->getArea() << std::endl;
	}
}