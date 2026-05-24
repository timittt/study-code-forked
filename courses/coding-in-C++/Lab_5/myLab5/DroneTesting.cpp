#include "DroneTesting.hpp"

int main()
{
	std::string name = "Tim";
	std::string name2 = "Thomas";
	swapValues(name, name2);

	char array[] = { 'T', 'H', 'g', 'Y', 'z' , 'P'};
	double array2[] = { 1.2, 3.33333, 0.6 , 0.3, 2.2};
	printArray(array);
	printArray(array2);
	std::cout << getMinimum(array2) << std::endl;
	printPair("X", "Retard", "Y", 22.2);

	std::vector<int> flight_recorder = { 42, 17, 42, 5, 99, 17, 63, 12 };
	std::cout << "Recorded Data: ";
	printVector(flight_recorder);
	std::sort(flight_recorder.begin(), flight_recorder.end());
	std::cout << "Sorted   Data: ";
	printVector(flight_recorder);
	searchVector(flight_recorder, 62);
	searchVector(flight_recorder, 63);

	std::vector<int> test_container = { 7, -1, 13, -1, 21, 21, 8, -1, 8 };
	printVector(test_container);
	cleanupVector(test_container);
	printVector(test_container);
}