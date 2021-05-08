#include "project2.h"
#include "ZipTree.h"
#include <vector>
#include <algorithm>
#include <cmath>


void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	ZipTree<int, std::pair<double, double>> bins;
	int binCount = 0;
	int found;
	bins.insert(++binCount, std::make_pair(1.0-items[0], 1.0));
	assignment[0] = 1;
	for (int i = 1; i < items.size(); ++i)
	{
		//std::cout << "item: " << items[i] << std::endl;
		found = 0;
		for (int j = 1; j < binCount + 1; ++j)
		{
			std::pair<double, double> binInfo = bins.find(j);
			//std::cout << "bin: " << j << " remain: " << binInfo.first << std::endl;
			//std::cout << binInfo.first - items[i] << std::endl;
			if (binInfo.first - items[i] >= -0.00001)
			{
				bins.updateValue(j, std::make_pair(binInfo.first - items[i], 1));
				assignment[i] = j;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			bins.insert(++binCount, std::make_pair(1.0-items[i], 1));
			assignment[i] = binCount;
		}
	}
	for (int i = 1; i < binCount + 1; ++i)
	{
		double temp = bins.find(i).first;
		if (std::abs(temp) <= 0.000001)
		{
			free_space.push_back(0.0);
		}
		else
		{
			free_space.push_back(temp);
		}
	}
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double>* temp = (std::vector<double>*)&items;
	std::sort(temp->begin(), temp->end(), std::greater<double>());
	ZipTree<int, std::pair<double, double>> bins;
	int binCount = 0;
	int found;
	bins.insert(++binCount, std::make_pair(1.0-items[0], 1.0));
	assignment[0] = 1;
	for (int i = 1; i < items.size(); ++i)
	{
		//std::cout << "item: " << items[i] << std::endl;
		found = 0;
		for (int j = 1; j < binCount + 1; ++j)
		{
			std::pair<double, double> binInfo = bins.find(j);
			//std::cout << "bin: " << j << " remain: " << binInfo.first << std::endl;
			//std::cout << binInfo.first - items[i] << std::endl;
			if (binInfo.first - items[i] >= -0.00001)
			{
				bins.updateValue(j, std::make_pair(binInfo.first - items[i], 1));
				assignment[i] = j;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			bins.insert(++binCount, std::make_pair(1.0-items[i], 1));
			assignment[i] = binCount;
		}
	}
	for (int i = 1; i < binCount + 1; ++i)
	{
		double temp = bins.find(i).first;
		if (std::abs(temp) <= 0.000001)
		{
			free_space.push_back(0.0);
		}
		else
		{
			free_space.push_back(temp);
		}
		//std::cout << bins.find(i).first << ", ";
		//free_space.push_back(bins.find(i).first);
	}
}
