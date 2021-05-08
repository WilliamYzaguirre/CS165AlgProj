#include "project2.h"
#include "ZipTree.h"
#include <vector>
#include <algorithm>
#include <cmath>

void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	ZipTree<int, std::pair<double, double>> bins;
	int binCount = 0;
	int bestFit;
	int found;
	double bestRemain;
	bins.insert(++binCount, std::make_pair(1.0-items[0], 1.0));
	assignment[0] = 1;
	for (int i = 1; i < items.size(); ++i)
	{
		found = 0;
		bestFit = -1;
		bestRemain = 2.0;
		//std::cout << "item: " << items[i] << std::endl;
		for (int j = 1; j < binCount + 1; ++j)
		{
			std::pair<double, double> binInfo = bins.find(j);
			double temp = binInfo.first - items[i];
			//std::cout << "bin: " << j << " remain: " << binInfo.first << std::endl;
			//std::cout << "temp: " << std::abs(temp) << std::endl;
			//std::cout << binInfo.first - items[i] << std::endl;
			if (std::abs(temp) <= 0.00000001)
			{
				bins.updateValue(j, std::make_pair(0.0, 1));
				assignment[i] = j;
				found = 2;
				break;
			}
			else if (temp >= 0.0 && temp < bestRemain)
			{
				bestFit = j;
				bestRemain = temp;
				found = 1;
			}
		}
		if (found == 0)
		{
			bins.insert(++binCount, std::make_pair(1.0-items[i], 1));
			assignment[i] = binCount;
		}
		else if (found == 1)
		{
			bins.updateValue(bestFit, std::make_pair(bestRemain, 1));
			assignment[i] = bestFit;

		}
	}
	for (int i = 1; i < binCount + 1; ++i)
	{
		double temp = bins.find(i).first;
		if (std::abs(temp) < 0.00001)
		{
			free_space.push_back(0.0);
		}
		else
		{
			free_space.push_back(temp);
		}
		//std::cout << temp << ", ";
	}
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double>* temp = (std::vector<double>*)&items;
	std::sort(temp->begin(), temp->end(), std::greater<double>());
	ZipTree<int, std::pair<double, double>> bins;
	int binCount = 0;
	int bestFit;
	int found;
	double bestRemain;
	bins.insert(++binCount, std::make_pair(1.0-items[0], 1.0));
	assignment[0] = 1;
	for (int i = 1; i < items.size(); ++i)
	{
		found = 0;
		bestFit = -1;
		bestRemain = 2.0;
		//std::cout << "item: " << items[i] << std::endl;
		for (int j = 1; j < binCount + 1; ++j)
		{
			std::pair<double, double> binInfo = bins.find(j);
			double temp = binInfo.first - items[i];
			//std::cout << "bin: " << j << " remain: " << binInfo.first << std::endl;
			//std::cout << "temp: " << std::abs(temp) << std::endl;
			//std::cout << binInfo.first - items[i] << std::endl;
			if (std::abs(temp) <= 0.00000001)
			{
				bins.updateValue(j, std::make_pair(0.0, 1));
				assignment[i] = j;
				found = 2;
				break;
			}
			else if (temp >= 0.0 && temp < bestRemain)
			{
				bestFit = j;
				bestRemain = temp;
				found = 1;
			}
		}
		if (found == 0)
		{
			bins.insert(++binCount, std::make_pair(1.0-items[i], 1));
			assignment[i] = binCount;
		}
		else if (found == 1)
		{
			bins.updateValue(bestFit, std::make_pair(bestRemain, 1));
			assignment[i] = bestFit;

		}
	}
	for (int i = 1; i < binCount + 1; ++i)
	{
		double temp = bins.find(i).first;
		if (std::abs(temp) < 0.00001)
		{
			free_space.push_back(0.0);
		}
		else
		{
			free_space.push_back(temp);
		}
		//std::cout << temp << ", ";
	}
}
