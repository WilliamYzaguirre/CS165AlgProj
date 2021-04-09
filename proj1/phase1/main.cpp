#include <iostream>
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "shell_sort1.hpp"
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> nums = {15, 1, 6, 12, 10, 4, 8, 14, 9, 11, 2, 5, 7, 13, 3};
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	ShellSort1 sort;
	sort.shell_sort1(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	return 0;
}
