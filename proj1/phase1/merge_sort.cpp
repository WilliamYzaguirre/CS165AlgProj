#include "merge_sort.hpp"

void MergeSort::merge_sort(std::vector<int>& nums) noexcept
{
	recur(nums, 0, nums.size() - 1);
}

void MergeSort::recur(std::vector<int>& nums, unsigned int left, unsigned int right) noexcept
{
	if (left < right)
	{
		unsigned int middle = left + (right - left) / 2;
		std::cout << "recur mid: " << middle << std::endl;
		recur(nums, left, middle);
		recur(nums, middle + 1, right);
		merge(nums, left, middle, right);
	}
}

void MergeSort::merge(std::vector<int>& nums, unsigned int left, unsigned int middle, unsigned int right) noexcept
{
	std::cout << "left: " << left << " middle: " << middle << " right: " << right << std::endl;
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

	std::cout << "temp: ";

	for (int i = 0; i < temp.size(); ++i)
	{
		std::cout << temp[i] << ", ";
	}

	std::cout << std::endl;

	for (unsigned int i = left; i < right + 1; ++i)
	{
		std::cout << "move: " << temp[i - left] << ", ";
		nums[i] = temp[i - left];
	}

	std::cout << std::endl;
}
