#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>

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
	for (const auto& value : v)
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

template <typename T>
void analyzeVector(const std::vector<T>& v)
{
	std::cout << "Analyzing Data Set:\n";
	printVector(v);
	// determine Sum
	T sum = std::accumulate(v.begin(), v.end(), T());
	T largest = *std::max_element(v.begin(), v.end());
	double average = static_cast<double>(sum) / static_cast<double>(v.size());
	std::cout << "Sum: " << sum << ", Max. Value: " << largest << ", Average: " << average << std::endl;
}
template <>
void analyzeVector<bool>(const std::vector<bool>& boolean_v)
{
	//for (bool datapoint : boolean_v)
	int sum = std::accumulate(boolean_v.begin(), boolean_v.end(), 0);
	double avg = static_cast<double>(sum) / static_cast<double>(boolean_v.size());
	std::cout << "Parameter was true " << sum << " of " << boolean_v.size() << " times\n";
	std::cout << "-> Parameter was " << ((avg < 0.5) ? "inactive" : "active") << " most of the time" << std::endl;
}

template <typename T, std::size_t size>
std::vector<T> frameToVector(const T (&frame)[size])
{
	std::vector<T> v;
	for (int i = 0; i < size; i++)
	{
		v.push_back(frame[i]);
	}
	std::cout << "Transformed frame of size " << size << " into a vector data set." << std::endl;
	return v;
}