#include "project1.h"
#include <iostream>

void insertion_sort(std::vector<int>& nums) 
{
	for(int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] < nums[i - 1])
		{
			int j = i - 1;
			while (nums[i] < nums[j] && j > -1)
			{
				--j;
			}
			int temp = nums[i];
			nums.erase(nums.begin() + i);
			nums.insert(nums.begin() + j + 1, temp);
		}
	}
}
