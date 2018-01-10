#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int solved[100][100][10] = {};

int sum(int a) {
	return (a*(a+1)) / 2;
}

int minMatches(int from, int to, int k) {
	if(k == 1) { return sum(to) - sum(from);}
	if(from == to) { return 0;}
	int bestStrategy = 1000000;
	if(solved[from][to][k] == 0) {
		for (int i = from + 1; i <= to; ++i) {
			int left = minMatches(from, i - 1, k - 1);
			int right = minMatches(i, to, k);
			bestStrategy = min(bestStrategy, max(left, right) + i);
		}
		solved[from][to][k] = bestStrategy;
		//cout << from << "," << to << "," << k << " "  << bestStrategy << endl;
	}
	return solved[from][to][k];
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k,m;
		cin >> k >> m;
		cout << minMatches(0, m, k) << endl;
	}
	return 0;
}

/* 




*/