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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<ii, int> mii;

#define INF 2000000000 // 2 billion
#define PRIME_BRANCH_DEPTH 3
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvvi(c, it) \
	for (vector<vi>::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)

void generateCoprimePairs(ii pair, int depth, vii& pairs) {
	if(depth > PRIME_BRANCH_DEPTH) { return;}
	
	pairs.push_back(pair);
	int m = pair.first;
	int n = pair.second;

	generateCoprimePairs(make_pair(2*m - n, m), depth + 1, pairs);
	generateCoprimePairs(make_pair(2*m + n, m), depth + 1, pairs);
	generateCoprimePairs(make_pair(m + 2*n, n), depth + 1, pairs);
}

void generatePytagoreanTriples(vii& coprimePairs, vector<vi>& pytagoreanTriples) {
	int counter = 0;
	TRvii (coprimePairs, i) {
		int m = i->first;
		int n = i->second;
		int a = pow(m, 2) - pow(n,2);
		int b = 2*m*n;
		int c = pow(m, 2) + pow(n,2);
		vi tri;
		tri.push_back(a);
		tri.push_back(b);
		tri.push_back(c);
		//cout << m << "," << n << " : " << a << " " << b << " " << c << endl;
		pytagoreanTriples.push_back(tri);
		counter++;
	}
}

int memo[300][300][40];
int rMinCoins(vii& coins, int a, int b, int m) {
	if(a < 0 || b < 0 || m < 0)  {
		return INF;
	}
	if(memo[a][b][m] > -1) {
		return memo[a][b][m];
	}
	int r = min(rMinCoins(coins, a, b, m - 1), rMinCoins(coins, a - coins[m].first, b - coins[m].second, m) + 1);
	memo[a][b][m] = r;
	//cout << "[" << a << "][" << b << "][" << m << "] = " << r << endl; 
	return r;
}

vvi findPytagorianTriplesDivisibleOf(int s, vvi& pytagoreanTriples) {
	vvi triplesForC;
	TRvvi (pytagoreanTriples, triple) {
		vi tripleP = *triple;
		int c = tripleP[2];
		if(s % c == 0) {
			//cout << "Found a triangle! " << s << " is divisable of c " << c << ". " << s/c << ", " << endl;
			triplesForC.push_back(tripleP);
			vi inverseTriple;
			inverseTriple.push_back(tripleP[1]);
			inverseTriple.push_back(tripleP[0]);
			inverseTriple.push_back(tripleP[2]);
			triplesForC.push_back(inverseTriple);
		}
	}
	return triplesForC;
}

void addZeroSolutionsIfNeeded(vii& coins, vvi& solutions, int s) {
	bool hasZeroA = false;
	bool hasZeroB = false;
	TRvii (coins, c) {
		if(c->first == 0) {
			hasZeroA = true;
		}
		if(c->second == 0) {
			hasZeroB = true;
		}
	}
	if(hasZeroA == 0) {
		vi zeroSolution;
		zeroSolution.push_back(s);
		zeroSolution.push_back(0);
		zeroSolution.push_back(s);
		solutions.push_back(zeroSolution);
	}
	if(hasZeroB == 0) {
		vi zeroSolution;
		zeroSolution.push_back(0);
		zeroSolution.push_back(s);
		zeroSolution.push_back(s);
		solutions.push_back(zeroSolution);
	}
}

int main(void) {
	int n, m, s;
	cin >> n;
	vii coprimePairs;
	generateCoprimePairs(make_pair(2,1), 0, coprimePairs);
	sort(coprimePairs.begin(), coprimePairs.end());
	vvi pytagoreanTriples;
	generatePytagoreanTriples(coprimePairs, pytagoreanTriples);
	while(n--) {
		cin >> m >> s;
		vii coins;
		while(m--) {
			int convVal, infoVal;
			cin >> convVal >> infoVal;
			coins.push_back(make_pair(convVal, infoVal));
		}
		sort(coins.begin(), coins.end(),  std::greater<ii>());
		vvi matchingSolutions = findPytagorianTriplesDivisibleOf(s, pytagoreanTriples);
		addZeroSolutionsIfNeeded(coins, matchingSolutions, s);
		if(matchingSolutions.size() == 0) {
			cout << "not possible" << endl;
			continue;
		}
		int minMatchingLength = INF;

		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < 40; ++i) {
			memo[0][0][i] = 0;
		}

		TRvvi (matchingSolutions, sol) {
			int c = (*sol)[2];
			int multiplyByFactor = s/c;
	 		int a = (*sol)[0];
			int b = (*sol)[1];
			int startFactor;
			int nrCoins = rMinCoins(coins, a*multiplyByFactor, b*multiplyByFactor, coins.size() - 1);
			minMatchingLength = min(minMatchingLength, nrCoins);
		}
		if(minMatchingLength == INF) {
			cout << "not possible" << endl;
		}
		else {
			cout << minMatchingLength << endl;
		}
	}
	return 0;
}
