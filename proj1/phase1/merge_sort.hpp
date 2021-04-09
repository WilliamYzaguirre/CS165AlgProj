#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <iostream>

class MergeSort
{
public:		
	void merge_sort(std::vector<int>& nums) noexcept;

	void recur(std::vector<int>& nums, unsigned int left, unsigned int right) noexcept;


	void merge(std::vector<int>& nums, unsigned int left, unsigned int middle, unsigned int right) noexcept;
};

#endif
