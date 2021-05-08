#include "project2.h"
#include <vector>
#include "ZipTree.h"
#include <iostream>
#include <cmath>

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	//int binCount = 0;
	int currentBin = 0;
	int found = 0;
	ZipTree<int, std::pair<double, double>> bins;
	bins.insert(++currentBin, std::make_pair(1.0-items[0], 1));
	assignment[0] = 1;
	for (int i = 1; i < items.size(); ++i)
	{
		//std::cout << "item: " << items[i] << std::endl;
		std::pair<double, double> binInfo = bins.find(currentBin);
		if (binInfo.first - items[i] >= 0)
		{
			bins.updateValue(currentBin, std::make_pair(binInfo.first - items[i], 1));
			assignment[i] = currentBin;
		}
		else
		{
			bins.insert(++currentBin, std::make_pair(1.0-items[i], 1));
			assignment[i] = currentBin;

		}
	}
	for (int i = 1; i < currentBin + 1; i++)
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
	//std::cout << std::endl;
}
