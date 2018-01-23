#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define INF 2000000000 // 2 billion

int s, sPow;

int change(vii& coins, int a, int b, int sLeft, int m) {
	if(a < 0 || b < 0 || sLeft < 0 || m < 0)  {
		return INF;
	}
	if(sLeft == 0) {
		return 0;
	}
	int aN = a + coins[m].first;
	int bN = b + coins[m].second;
	int r = min(
		change(coins, a, b, sLeft, m - 1), 
		change(coins, aN, bN, sPow - (pow(aN,2) + pow(bN,2)), m) + 1);
	return r;
}

int main(void) {
	int n, m;
	cin >> n;
	while(n--) {
		cin >> m >> s;
		sPow = s * s;
		vii coins;
		while(m--) {
			int convVal, infoVal;
			cin >> convVal >> infoVal;
			coins.push_back(make_pair(convVal, infoVal));
		}
		int minChanges = change(coins, 0, 0, sPow, coins.size() - 1);
		if(minChanges == INF) {
			cout << "not possible" << endl;
		}
		else {
			cout << minChanges << endl;
		}
	}
	return 0;
}