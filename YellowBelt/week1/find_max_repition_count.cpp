#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool operator<(const Region& lhs, const Region& rhs)
{
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
	if(!regions.size())
	{
		return 0;
	}

	int max_count = 0;
	map<Region, int> counts;
	for(const auto& region : regions)
	{
		counts[region]++;

		if(max_count < counts[region])
		{
			max_count = counts[region];
		}
	}

	return max_count;
}