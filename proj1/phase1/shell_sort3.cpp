#include "project1.h"
#include <iostream>
#include <math.h>
#include <algorithm>

void shell_sort3(std::vector<int>& nums) 
{
	std::vector<double> gaps;
	unsigned int p = 0;
	unsigned int q = 0;
	unsigned int in = 1;
	while (in)
	{
		int counter = 0;
		while (pow(2, p) * pow(3, q) < nums.size())
		{
			int temp = pow(2,p) * pow(3,q);
			//std::cout << "temp: " << temp << std::endl;
			//if (!std::count(gaps.begin(), gaps.end(),temp))
			//{
			gaps.push_back(temp);
			//}	
			p++;
			counter++;
		}
		if (counter == 0)
		{
			in = 0;
		}
		p = 0;
		q++;
	}
	
	std::sort(gaps.begin(), gaps.end(), std::greater<int>());
	

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
							break; //spagettiiiiii
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
