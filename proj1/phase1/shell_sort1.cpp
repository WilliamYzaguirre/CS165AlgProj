#include "shell_sort1.hpp"

void ShellSort1::shell_sort1(std::vector<int>& nums) noexcept
{
	std::vector<double> gaps;
	for (double i = 1; i < log2(nums.size()); ++i)
	{
		std::cout << i << " " << floor(nums.size()/pow(2.0, i)) << std::endl;
		gaps.push_back(floor(nums.size()/pow(2.0, i)));
	}
	for (auto gap : gaps)
	{
		for (int i = 0; i < gap - 1; ++i)
		{
			int count = ceil( (nums.size() - i + 0.0) / (gap * 1.0));
			for (int j = i + gap; j < nums.size(); j += gap)
			{
				if (nums[j] < nums[j-gap])
				{
					int k = j - gap;
					while(nums[j] < nums[k] && k > -1)
					{
						std::cout << nums.at(j) << " " << nums.at(k) << std::endl;
						int temp = nums[j];
						nums.at(j) = nums.at(k);
						nums.at(k) = temp;
						k -= gap;

					}
				}
			}
			
			for (auto num : nums)
			{
				std::cout << num << ", ";
			}
			std::cout << std::endl;
		}
	}
	/**
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
	}**/
}
