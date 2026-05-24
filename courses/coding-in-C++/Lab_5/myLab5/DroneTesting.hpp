#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

template<typename T>

void swapValues(T &valA, T &valB)
{
	std::cout << "Before: Value A = " << valA << ", Value B = " << valB << std::endl;
	T temp = valB;
	valB = valA;
	valA = temp;
	std::cout << "After: Value A = " << valA << ", Value B = " << valB << std::endl;
}

template <typename T, std::size_t size>

void printArray(const T (&array)[size])
{
	std::cout << "[";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i];
		std::cout << ((i < size-1) ? ", " : "]");
	}
	std::cout << std::endl;
}

template <typename T, std::size_t N>

T getMinimum(const T (&array)[N])
{
	auto it_start = std::begin(array);
	auto it_end = std::end(array);

	T minVal = *it_start;
	for (auto it = ++it_start; it != it_end; ++it)
	{
		if (*it < minVal)
		{
			minVal = *it;
		}
	}
	return minVal;
}

template <typename T, typename U>

void printPair(std::string labA, T valA, std::string labB, U valB)
{
	std::cout << labA << ": " << valA << " | " << labB << ": " << valB << std::endl;
}

template <typename T>
void printVector(const std::vector<T>& v)
{
	std::cout << "[";
	for (T value : v)
	{
		std::cout << value << ", ";
	}
	std::cout << "end]" << std::endl;
}

template <typename T>
bool searchVector(const std::vector<T>& v, const T prompt)
{
	if (std::find(v.begin(), v.end(), prompt) != v.end())
	{
		std::cout << "Vector contains value " << prompt << std::endl;
		return true;
	}
	std::cout << "Vector does not contain value " << prompt << std::endl;
	return false;
}

template <typename T>
int cleanupVector(std::vector<T>& v)
{
	int error_count = 0;

	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it == -1)
		{
			*it = 0;
			error_count++;
		}
	}
	std::reverse(v.begin(), v.end());
	std::cout << "Corrected " << error_count << " false values and reversed data set.\n";
	return error_count;
}