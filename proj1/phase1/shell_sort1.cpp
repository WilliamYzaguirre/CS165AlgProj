#include "shell_sort1.hpp"

void ShellSort1::shell_sort1(std::vector<int>& nums) noexcept
{
	std::vector<double> gaps;
	for (double i = 1; i < log2(nums.size()); ++i)
	{
		gaps.push_back(floor(nums.size()/pow(2.0, i)));
	}
	for (auto gap : gaps)
	{
		//std::cout << "GAP: " << gap << std::endl;
		for (int i = 0; i < gap; ++i)
		{
			int count = ceil( (nums.size() - i + 0.0) / (gap * 1.0));
			for (int j = i + gap; j < nums.size(); j += gap)
			{
				//std::cout << "j + j-gap: " << nums.at(j) << " " << nums.at(j-gap) << std::endl;
				if (nums[j] < nums[j-gap])
				{
					int k = j - gap;
					int temp = nums[j];
					while(temp < nums[k] && k > -1)
					{
						nums.at(k + gap) = nums.at(k);
						nums.at(k) = temp;
						k -= gap;

					}
				}
			}
			
			//for (auto num : nums)
			//{
			//	std::cout << num << ", ";
			//}
			//std::cout << std::endl;
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
