#include "project1.h"
#include <iostream>
#include <math.h>

void shell_sort1(std::vector<int>& nums) 
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
			
			for (int j = i + gap; j < nums.size(); j += gap)
			{
				//std::cout << "j + j-gap: " << nums.at(j) << " " << nums.at(j-gap) << std::endl;
				if (nums[j] < nums[j-gap])
				{
					int k = j - gap;
					//std::cout << "K: " << k << std::endl;
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
							break; //super spagetti code
						}
					}
				}
			}
		}
	}
}
