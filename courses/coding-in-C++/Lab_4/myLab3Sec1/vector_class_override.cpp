#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdint>
#include <cmath>

class Vector2D
{
public:
	Vector2D()
		: x(0), y(0) {}

	Vector2D(double x, double y)
		: x(x), y(y) {
	}
	double getX() const{
		return x;
	}
	double getY() const{
		return y;
	}
	void print() const{
		std::cout << "X: " << x << "Y: " << y << std::endl;
	}
	double getLength() const{
		return sqrt((x * x) + (y * y));
	}
	double getLength(int precision) const{
		double factor = std::pow(10.0, precision);
		return std::round(getLength() * factor) / factor;
	}
	// Add another vector to current object
	Vector2D operator+=(const Vector2D &v) {
		this->x += v.getX();
		this->y += v.getY();
	}
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);

private:
	double x;
	double y;
};

// Add two vectors
Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D(v1.getX() + v2.getX(), v1.getY() + v2.getY());
}

// Scalar multiplication vector * scalar
Vector2D operator*(const Vector2D& v1, const double scalar)
{
	return Vector2D(v1.getX() * scalar, v1.getY() * scalar);
}

// Scalar multiplication scalar * vector
Vector2D operator*(const double scalar, const Vector2D& v1)
{
	return Vector2D(v1.getX() * scalar, v1.getY() * scalar);
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
	os << "Vector(" << v.x << "|" << v.y << ")";
	return os;
}

int main()
{
	Vector2D PunktA(2.11, 6.7);
	PunktA.print();
	std::cout << 3 * PunktA << PunktA * 5 << PunktA.getLength() << " Rounded (precision = 3): " << PunktA.getLength(3) << std::endl;

	Vector2D PunktB(6.893, 2.34241);
	PunktB.print();
	std::cout << PunktB.getLength() << " Rounded (precision = 1): " << PunktB.getLength(1) << std::endl;
}