#include "DroneTesting.hpp"

int main()
{
	/*
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
	analyzeVector(test_container);
	cleanupVector(test_container);
	analyzeVector(test_container);

	std::vector<double> test_containerd = { 7.33, -1.0, 13.5, -1.0, 21.22, 21.45, 8.8, -1.0, 8.67 };
	analyzeVector(test_containerd);
	cleanupVector(test_containerd);
	analyzeVector(test_containerd);
	*/

	double test_frame[] = { 1.2, 3.33333, -1.0 , 0.3, 2.2, -1.0 };
	std::vector test_vector = frameToVector(test_frame);
	analyzeVector(test_vector);
	cleanupVector(test_vector);
	analyzeVector(test_vector);

	bool bool_test_frame[] = { false, false, true, false, true, true, true, false, true, false, true, false, false };
	std::vector bool_test_vector = frameToVector(bool_test_frame);
	analyzeVector(bool_test_vector);
}