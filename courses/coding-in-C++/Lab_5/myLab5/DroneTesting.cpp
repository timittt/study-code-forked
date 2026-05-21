#include "DroneTesting.hpp"

int main()
{
	std::string name = "Tim";
	std::string name2 = "Thomas";
	swapValues(name, name2);

	char array[5] = { 'T', 'H', 'g', 'Y', 'z' };
	double array2[3] = { 1.2, 3.33333, 4.6 };
	printArray(array, 5);
	printArray(array2, 3);
	std::cout << getMinimum(array2, 3) << std::endl;
}