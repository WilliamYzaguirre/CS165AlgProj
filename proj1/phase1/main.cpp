#include <iostream>
#include "insertion_sort.hpp"
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> nums = {6, 4, 8, 1, 2, 9, 3, 5, 7};
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	InsertionSort is;
	is.insertion_sort(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	return 0;
}
