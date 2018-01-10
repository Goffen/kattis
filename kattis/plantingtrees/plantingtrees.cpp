#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int seedlings[n];
	for (int i = 0; i < n; ++i) {
		cin >> seedlings[i];
	}
	sort(seedlings, seedlings+n, greater<int>());
	int maxDays = -1;
	for (int i = 0; i < n; ++i) {
		if(seedlings[i] + i + 1 > maxDays) {
			maxDays = seedlings[i] + i + 1;
		}
	}
	cout << maxDays + 1;
}