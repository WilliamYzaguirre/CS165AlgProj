#include "project1.h"
#include <iostream>
#include <math.h>

void recur(std::vector<int>& nums, unsigned int left, unsigned int right); 
void merge(std::vector<int>& nums, unsigned int left, unsigned int middle, unsigned int right);


void merge_sort(std::vector<int>& nums)
{
	recur(nums, 0, nums.size() - 1);
}

void recur(std::vector<int>& nums, unsigned int left, unsigned int right) 
{
	if (left < right)
	{
		unsigned int middle = left + (right - left) / 2;
		recur(nums, left, middle);
		recur(nums, middle + 1, right);
		merge(nums, left, middle, right);
	}
}

void merge(std::vector<int>& nums, unsigned int left, unsigned int middle, unsigned int right) 
{
	unsigned int cur_left = left;
	unsigned int cur_right = middle + 1;
	
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



	for (unsigned int i = left; i < right + 1; ++i)
	{
		nums[i] = temp[i - left];
	}

}
