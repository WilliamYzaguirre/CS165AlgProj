#include <iostream>
#include "project1.h"
#include <vector>
#include <random>
#include <functional>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{	
	std::vector<int> nums;
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
	shell_sort3(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	nums.clear();
	for (int i = 123; i > 0; --i)
	{
		nums.push_back(i);
	}
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	shell_sort3(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	nums.clear();
	srand(time(NULL));
	for (int i = 101; i > 0; --i)
	{
		nums.push_back(rand() % 300 + 1);
	}
	std::cout << "Before:" << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	shell_sort3(nums);
	std::cout << "After: " << std::endl;
	for (auto item : nums)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	return 0;
}
