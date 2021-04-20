#include "project1.h"
#include <iostream>
#include <math.h>

void insertion_sort3(std::vector<int>& nums, int left, int right); 
void merge3(std::vector<int>& nums, int left, int middle, int right); 
void recur3(std::vector<int>& nums, int left, int right, int H); 
	
void hybrid_sort3(std::vector<int>& nums) 
{
	int H = pow(nums.size(), 1.0/6.0);
	recur3(nums, 0, nums.size() - 1, H);
}

void recur3(std::vector<int>& nums, int left, int right, int H) 
{
	if (right - left > H)
	{
		if (left < right)
		{
			int middle = left + (right - left) / 2;
			recur3(nums, left, middle, H);
			recur3(nums, middle + 1, right, H);
			merge3(nums, left, middle, right);
		}
	}
	else
	{
		insertion_sort3(nums, left, right);
	}
}

void merge3(std::vector<int>& nums, int left, int middle, int right) 
{
	int cur_left = left;
	int cur_right = middle + 1;

	
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


	for (int i = left; i < right + 1; ++i)
	{
		nums[i] = temp[i - left];
	}

}


void insertion_sort3(std::vector<int>& nums, int left, int right) 
{
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
}
