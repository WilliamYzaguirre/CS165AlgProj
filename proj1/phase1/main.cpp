#include <iostream>
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "shell_sort1.hpp"
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> nums = {6, 4, 8, 1, 2, 9, 3, 5, 7, 13, 14, 10, 11, 17, 16, 12, 15, 20, 19, 18};
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
