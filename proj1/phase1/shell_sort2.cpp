#include "project1.h"
#include <iostream>
#include <math.h>

void shell_sort2(std::vector<int>& nums) 
{
	std::vector<double> gaps;
	for (int i = log2(nums.size()); i > 0; --i)
	{
		gaps.push_back(pow(2, i) + 1);
	}
	gaps.push_back(1);
	//for (auto gap : gaps)
	//{
	//	std::cout << gap << " ";
	//}
	//std::cout << std::endl;
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
					while(k > -1)
					{
						if (temp < nums[k])
						{
							nums.at(k + gap) = nums.at(k);
							nums.at(k) = temp;
							k -= gap;
						}
						else
						{
							break; //spagettiiiii
						}
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
