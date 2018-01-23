#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)

bool memo[301][301];

int main(void) {
	int n,m, s;
	cin >> n;
	while(n--) {
		cin >> m >> s;
		vii coins;
		while(m--) {
			int convVal, infoVal;
			cin >> convVal >> infoVal;
			coins.push_back(make_pair(convVal, infoVal));
		}
		memset(memo, false, sizeof(memo));
		queue<pair<ii, int> > q;
		TRvii (coins, i) {
			q.push(make_pair(*i, 1));
		}
		int foundAt = 0;
		while(!q.empty()) {
			pair<ii, int> queueItem = q.front();
			ii coinsSoFar = queueItem.first;
			int depth = queueItem.second;
			q.pop();
			int a = coinsSoFar.first;
			int b = coinsSoFar.second;
			if(a > 300 || b > 300) {
				continue;
			}
			if(memo[a][b]) {
				continue;
			}
			float eMod = sqrt(pow(a, 2) + pow(b, 2));
			if(eMod == s) {
				foundAt = depth;
				break;
			}
			else if(eMod < s) {
				memo[a][b] = true;
				TRvii(coins, i) {
					ii newPair = make_pair(a + i->first, b + i->second);
					q.push(make_pair(newPair, depth + 1));
				}
			}
		}
		cout << (foundAt == 0 ? "not possible" : to_string(foundAt)) << endl;
	}
	return 0;
}
