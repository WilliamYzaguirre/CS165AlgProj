#include <iostream>
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "shell_sort1.hpp"
#include "shell_sort2.hpp"
#include "shell_sort3.hpp"
#include "shell_sort4.hpp"
#include <vector>
#include <random>
#include <functional>

int main(int argc, char** argv)
{	std::vector<int> nums;
	for (int i = 100; i > 0; --i)
	{
		nums.push_back(i);
	}
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	ShellSort1 sort1;
	sort1.shell_sort1(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	
	nums.clear();
	for (int i = 100; i > 0; --i)
	{
		nums.push_back(i);
	}
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	ShellSort2 sort2;
	sort2.shell_sort2(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	
	nums.clear();
	for (int i = 100; i > 0; --i)
	{
		nums.push_back(i);
	}
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	ShellSort3 sort3;
	sort3.shell_sort3(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	nums.clear();
	for (int i = 100; i > 0; --i)
	{
		nums.push_back(i);
	}
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	ShellSort4 sort4;
	sort4.shell_sort4(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	return 0;
}
