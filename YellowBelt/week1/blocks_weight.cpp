#include <iostream>
#include <inttypes.h>
using namespace std;

int main() {
	uint64_t n, r;
	cin >> n >> r;

	uint64_t w, h, d;
	uint64_t sum = 0;
	for(uint32_t i = 0; i < n; i++)
	{
		cin >> w >> h >> d;
		sum += w * h * d;
	}
	sum *= r;
	cout << sum;
	return 0;
}
