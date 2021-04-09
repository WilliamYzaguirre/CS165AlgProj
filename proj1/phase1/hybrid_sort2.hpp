#ifndef HYBRID_SORT2_HPP
#define HYBRID_SORT2_HPP

#include <vector>
#include <iostream>
#include <math.h>

class HybridSort2
{
public:		
	void hybrid_sort2(std::vector<int>& nums) noexcept;

	void recur(std::vector<int>& nums, int left, int right, int H) noexcept;


	void merge(std::vector<int>& nums, int left, int middle, int right) noexcept;

	void insertion_sort(std::vector<int>& nums, int left, int right) noexcept;
};

#endif
