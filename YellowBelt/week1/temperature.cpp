#include <iostream>
#include <vector>
#include <inttypes.h>
using namespace std;

int main() {
	uint32_t N;
	cin >> N;
	vector<int64_t> numbers(N);

	int64_t avg = 0;
	for(uint32_t i = 0; i < N; i++)
	{
		cin >> numbers[i];
		avg += numbers[i];
	}
	avg /= static_cast<int64_t>(N);

	uint32_t amount = 0;
	for(auto n : numbers)
	{
		if(n > avg)
		{
			amount++;
		}
	}
	cout << amount << endl;

	for(uint32_t i = 0; i < N; i++)
	{
		if(numbers[i] > avg)
		{
			cout << i << " ";
		}
	}

	return 0;
}
