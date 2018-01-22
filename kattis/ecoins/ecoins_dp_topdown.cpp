#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define INF 2000000000 // 2 billion

int memo[301][40];
int s, sPow;

int change(vii& coins, int a, int b, int sLeft, int m) {
	if(a < 0 || b < 0 || sLeft < 0 || m < 0)  {
		return INF;
	}
	int sLeftSqrt = sqrt(sLeft);
	if(memo[sLeftSqrt][m] > -1) {
		return memo[sLeftSqrt][m];
	}
	int nA = a + coins[m].first;
	int nB = b + coins[m].second;
	int r = min(change(coins, a, b, sLeft, m - 1), change(coins, nA, nB, sPow - (pow(nA,2) + pow(nB,2)), m) + 1);
	memo[sLeftSqrt][m] = r;
	cout << nA << "," << nB << " : " << "[" << sLeftSqrt << "][" << m << "] = " << r << endl; 
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
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < 40; ++i) {
			memo[0][i] = 0;
		}
		change(coins, 0, 0, sPow, coins.size() - 1);
		int minChanges = memo[s][coins.size() - 1];
		if(minChanges == INF) {
			cout << "not possible" << endl;
		}
		else {
			cout << minChanges << endl;
		}
	}
	return 0;
}
/* 

1
3 20
0 2
2 0
2 1

*/
