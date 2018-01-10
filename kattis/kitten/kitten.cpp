#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)

vii AdjList[100];

bool dfs(int branch, int toFind, vi& result) {
	if(branch == toFind) {
		result.push_back(branch);
		return true;
	}
	TRvii (AdjList[branch], v) {
		if(dfs(v->first, toFind, result)) {
			result.push_back(branch);
			return true;
		}
	}
	return false;
}

int main(void) {
	int kittenAt;
	string line;
	bool first = true;
	vi branches;
	while(getline(cin, line)) {
		istringstream l(line);
		int branch;
		l >> branch;
		if(branch == -1) {
			break;
		}
		if(first) {
			kittenAt = branch;
			first = false;
			continue;
		}
		branches.push_back(branch);
		int edgeTo;
		vii adj;
		ii p;
		while(l >> edgeTo) {
			p = make_pair(edgeTo, 0);
			adj.push_back(p);
		}
		AdjList[branch] = adj;
	}

	int maxPathLength = 0;
	vi maxPath;
	REP(i, 0, branches.size()) {
		vi result;
		dfs(branches[i], kittenAt, result);
		if(result.size() > maxPathLength) {
			maxPathLength = result.size();
			maxPath = result;
		}
	}

	REP(j, 0, maxPath.size()) {
		cout << maxPath[j];
		if(j != maxPath.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}