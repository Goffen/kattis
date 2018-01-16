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
typedef map<ii, int> mii;

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
		//cout << m << "," << n << " : " << a << " " << b << " " << c << endl;
		pytagoreanTriples.push_back({a,b,c});
		counter++;
	}
}

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main(void) {
	int n, m, s;
	cin >> n;

	vii coprimePairs;
	generateCoprimePairs(make_pair(2,1), 0, coprimePairs);
	sort(coprimePairs.begin(), coprimePairs.end());
	vector<vi> pytagoreanTriples;
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
		//TRvii (coins, c) {
		//	cout << c->first << "," << c->second << endl;
		//}
		vi closestTriangle;
		int maxDivisions = 0;
		TRvvi (pytagoreanTriples, triple) {
			vi tripleP = *triple;
			int c = tripleP[2];
			if(s % c == 0) {
				//cout << "Found a triangle! " << s << " is divisable of c " << c << ". " << s/c << " " << gcd(s,c) << endl;
				if((s / c) > maxDivisions) {
					maxDivisions = s / c;
					closestTriangle = tripleP;
				}
			}
		}
		int a = closestTriangle[0];
		int b = closestTriangle[1];

		cout << "We are looking for a=" << a << " and b=" << b << endl;

		queue<pair<ii, int> > q;
		mii searched;

		int gcdCoinA = a;
		int gcdCoinB = b;
		int gcdCoinA2 = b;
		int gcdCoinB2 = a;
		TRvii (coins, i) {
			ii p = *i;
			if(p.first > 1) {
				gcdCoinA = gcd(gcdCoinA, p.first);
				gcdCoinA2 = gcd(gcdCoinA2, p.first);
			}
			if(p.second > 1) {
				gcdCoinB = gcd(gcdCoinB, p.second);
				gcdCoinB2 = gcd(gcdCoinB2, p.second);
			}
			q.push(make_pair(*i, 1));
		}

		cout << "gcdA: " << gcdCoinA << ", gcdA2: " << gcdCoinA2 << ", " << " gcdB:" << gcdCoinB << " gcdB2:" << gcdCoinB2; 

		int foundAt = 0;
		while(!q.empty()) {
			pair<ii, int> queueItem = q.front();
			ii coinsSoFar = queueItem.first;
			int convSum = coinsSoFar.first;
			int eSum = coinsSoFar.second;
			int depth = queueItem.second;
			q.pop();
			//cout << "Popped: " << convSum << "," << coinsSoFar.second << " @ " << depth << endl;
			if(searched.count(coinsSoFar) != 0) {
				continue;
			}
			searched[coinsSoFar] = 1;
			if(convSum == a && eSum == b || convSum == b && eSum == a) {
				foundAt = depth;
				break;
			}
			if((convSum < a || convSum < b) && (eSum < a || eSum < b)) {
				TRvii(coins, i) {
					q.push(make_pair(make_pair(convSum + i->first, eSum + i->second), depth + 1));
				}
			}
		}
		cout << (foundAt == 0 ? "not possible" : to_string(foundAt)) << endl;
	}
	return 0;
}

/* 

2
2 5
0 2
2 0

3 20
0 2
2 0
2 1



1
3 200
0 2
2 0
2 1

3 299
0 2
2 0
2 1
*/