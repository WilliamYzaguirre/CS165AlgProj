#include "shell_sort4.hpp"

void ShellSort4::shell_sort4(std::vector<int>& nums) noexcept
{
	std::vector<double> gaps;
	unsigned int counter = 0;
	while (true)
	{
		unsigned int temp = 0;
		if (counter % 2 == 0)
		{
			temp = 9 * (pow(2,counter) - pow(2,counter/2)) + 1;
		}
		else
		{
			temp = (8 * pow(2,counter)) - (6 * pow(2,(counter+1)/2)) + 1;
		}
		if (temp < nums.size())
		{
			gaps.insert(gaps.begin(), temp);
			counter++;
		}
		else
		{
			break;
		}
	}
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
