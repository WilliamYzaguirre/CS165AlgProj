#include "project1.h"
#include <iostream>
#include <math.h>

void insertion_sort2(std::vector<int>& nums, int left, int right);
void recur2(std::vector<int>& nums, int left, int right, int H);
void merge2(std::vector<int>& nums, int left, int middle, int right);

void hybrid_sort2(std::vector<int>& nums) 
{
	int H = pow(nums.size(), 1.0/4.0);
	std::cout << "H: " << H << std::endl;
	recur2(nums, 0, nums.size() - 1, H);
}

void recur2(std::vector<int>& nums, int left, int right, int H)
{
	std::cout << "recur left: " << left << " right: " << right << std::endl;
	if (right - left > H)
	{
		if (left < right)
		{
			int middle = left + (right - left) / 2;
			std::cout << "recur mid: " << middle << std::endl;
			recur2(nums, left, middle, H);
			recur2(nums, middle + 1, right, H);
			merge2(nums, left, middle, right);
		}
	}
	else
	{
		insertion_sort2(nums, left, right);
	}
}

void merge2(std::vector<int>& nums, int left, int middle, int right) 
{
	std::cout << "left: " << left << " middle: " << middle << " right: " << right << std::endl;
	int cur_left = left;
	int cur_right = middle + 1;

	std::cout << "MERGING: ";
	for (int i = left; i < right; ++i)
	{
		std::cout << nums[i] << ", ";
	}
	std::cout << std::endl;
	
	std::vector<int> temp;

	while (cur_left <= middle && cur_right <= right)
	{
		if (nums[cur_left] <= nums[cur_right])
		{
			temp.push_back(nums[cur_left]);
			cur_left++;
		}
		else
		{
			temp.push_back(nums[cur_right]);
			cur_right++;
		}
	}

	for (int i = cur_left; i < middle + 1; ++i)
	{
		temp.push_back(nums[i]);
	}

	for (int i = cur_right; i < right + 1; ++i)
	{
		temp.push_back(nums[i]);
	}

	std::cout << "temp: ";

	for (int i = 0; i < temp.size(); ++i)
	{
		std::cout << temp[i] << ", ";
	}

	std::cout << std::endl;

	for (int i = left; i < right + 1; ++i)
	{
		std::cout << "move: " << temp[i - left] << ", ";
		nums[i] = temp[i - left];
	}

	std::cout << std::endl;
}


void insertion_sort2(std::vector<int>& nums, int left, int right) 
{
	std::cout << "LEFT: " << left << " RIGHT: " << right << std::endl;
	std::cout << "Sorting: ";
	for (int i = left; i < right + 1; ++i)
	{
		std::cout << nums[i] << ", ";
	}
	std::cout << std::endl;
	for (int i = left + 1; i < right + 1; ++i)
	{
		if (nums[i] < nums[i - 1])
		{
			int j = i - 1;
			while (nums[i] < nums[j] && j > left - 1)
			{
				--j;
			}
			int temp = nums[i];
			nums.erase(nums.begin() + i);
			nums.insert(nums.begin() + j + 1, temp);
		}
	}
	std::cout << "Done Sorting: ";
	for (int i = left; i < right + 1; ++i)
	{
		std::cout << nums[i] << ", ";
	}
	std::cout << std::endl;
}
