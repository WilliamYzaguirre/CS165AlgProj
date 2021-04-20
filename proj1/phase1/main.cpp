#include <iostream>
#include "project1.h"
#include <vector>
#include <random>
#include <functional>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <map>

std::vector<int> getUniform(std::mt19937 engine, int size)
{
	std::vector<int> v;
	for (int i = 0; i < size; ++i)
	{
		v.push_back(i);
	}
	std::shuffle(std::begin(v), std::end(v), engine);
	return v;
}

std::vector<int> getAlmost(std::mt19937 engine, int size)
{
	std::uniform_int_distribution<int> dis(0, size);
	std::vector<int> v;
	for (int i = 0; i < size; ++i)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 2*log2(size); ++i)
	{
		int first = dis(engine);
		int second = dis(engine);
		std::iter_swap(v.begin() + first, v.begin() + second);
	}
	return v;
}

std::vector<int> getReverse(int size)
{
	std::vector<int> v;
	for (int i = size; i > -1; --i)
	{
		v.push_back(i);
	}
	return v;
}

int main(int argc, char** argv)
{	
	typedef void (*sort_fn)(std::vector<int>& nums);
	sort_fn insertion_sort_fn = insertion_sort;
	sort_fn merge_sort_fn = merge_sort;
	sort_fn shell_sort1_fn = shell_sort1;
	sort_fn shell_sort2_fn = shell_sort2;
	sort_fn shell_sort3_fn = shell_sort3;
	sort_fn shell_sort4_fn = shell_sort4;
	sort_fn hybrid_sort1_fn = hybrid_sort1;
	sort_fn hybrid_sort2_fn = hybrid_sort2;
	sort_fn hybrid_sort3_fn = hybrid_sort3;
	std::map<std::string, sort_fn> name_to_fn;
	name_to_fn["insertion"] = insertion_sort;
	name_to_fn["merge"] = merge_sort;
	name_to_fn["shell1"] = shell_sort1;
	name_to_fn["shell2"] = shell_sort2;
	name_to_fn["shell3"] = shell_sort3;
	name_to_fn["shell4"] = shell_sort4;
	name_to_fn["hybrid1"] = hybrid_sort1;
	name_to_fn["hybrid2"] = hybrid_sort2;
	name_to_fn["hybrid3"] = hybrid_sort3;
	std::random_device rd;
	std::mt19937 engine{rd()};

	std::string sorting_type = argv[1];
	int size = atoi(argv[2]);
	
	std::vector<int> v = getReverse(size);
	name_to_fn[sorting_type](v);
	//name_to_fn["shell1"](v);

	//for (int i = v.size() - 10; i < v.size(); ++i)
	//{
	//	std::cout << v[i] << std::endl;
	//}


	//std::vector<int> sizes{100, 500, 1000, 2500, 5000, 7500, 10000};

	/**
	for (int i = 0; i < sizes.size(); ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			insertion_sort(getUniform(engine, sizes[i]));
			insertion_sort(getAlmost(engine, sizes[i]));
			insertion_sort(getReverse(sizes[i]));
			merge_sort(getUniform(engine, sizes[i]));
			merge_sort(getAlmost(engine, sizes[i]));
			merge_sort(getReverse(sizes[i]));
			shell_sort1(getUniform(engine, sizes[i]));
			shell_sort1(getAlmost(engine, sizes[i]));
			shell_sort1(getReverse(sizes[i]));
			shell_sort2(getUniform(engine, sizes[i]));
			shell_sort2(getAlmost(engine, sizes[i]));
			shell_sort2(getReverse(sizes[i]));
			shell_sort3(getUniform(engine, sizes[i]));
			shell_sort3(getAlmost(engine, sizes[i]));
			shell_sort3(getReverse(sizes[i]));
			shell_sort4(getUniform(engine, sizes[i]));
			shell_sort4(getAlmost(engine, sizes[i]));
			shell_sort4(getReverse(sizes[i]));
			hybrid_sort1(getUniform(engine, sizes[i]));
			hybrid_sort1(getAlmost(engine, sizes[i]));
			hybrid_sort1(getReverse(sizes[i]));
			hybrid_sort2(getUniform(engine, sizes[i]));
			hybrid_sort2(getAlmost(engine, sizes[i]));
			hybrid_sort2(getReverse(sizes[i]));
			hybrid_sort3(getUniform(engine, sizes[i]));
			hybrid_sort3(getAlmost(engine, sizes[i]));
			hybrid_sort3(getReverse(sizes[i]));
			
		}
	}
	**/
	return 0;
}
