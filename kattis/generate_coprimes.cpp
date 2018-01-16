#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)

/* 
Generate all coprime pairs
*/
void generateBranches(ii pair, int depth, vii& pairs) {
	pairs.push_back(pair);
	if(depth == 3) {
		return;
	}
	int m = pair.first;
	int n = pair.second;
	generateBranches(make_pair(2*m - n, m), depth + 1, pairs);
	generateBranches(make_pair(2*m + n, m), depth + 1, pairs);
	generateBranches(make_pair(m + 2*n, n), depth + 1, pairs);
}

int main(void) {
	long p, q, x, y;
	
	vii pairs;
	generateBranches(make_pair(2,1), 0, pairs);
	//generateBranches(make_pair(3,1), 0, pairs);
	cout << pairs.size() << endl;
	sort(pairs.begin(), pairs.end());
	TRvii (pairs, i) {
		int m = i->first;
		int n = i->second;
		int a = pow(m, 2) - pow(n,2);
		int b = 2*m*n;
		int c = pow(m, 2) + pow(n,2);
		cout << m << "," << n << " : " << a << " " << b << " " << c << endl;
	}

	return 0;
}