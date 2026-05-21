#include <iostream>
#include <vector>
#include <string>

template<typename T>

void swapValues(T &valA, T &valB)
{
	std::cout << "Before: Value A = " << valA << ", Value B = " << valB << std::endl;
	T temp = valB;
	valB = valA;
	valA = temp;
	std::cout << "After: Value A = " << valA << ", Value B = " << valB << std::endl;
}

template <typename T>

void printArray(const T array, const int size)
{
	std::cout << "[";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i];
		std::cout << ((i < size-1) ? ", " : "]");
	}
	std::cout << std::endl;
}

template <typename T>

T getMinimum(const T* array, const int size)
{
	T minVal = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] < minVal)
		{
			minVal = array[i];
		}
	}
	return minVal;
}

template <typename T, typename U>

void printPair(T labelA, T labelB)
{

}