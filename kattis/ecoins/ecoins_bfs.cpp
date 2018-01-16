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

#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)


/* 
1
3 200
0 2
2 0
2 1

*/

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
		queue<pair<ii, int> > q;
		mii searched;
		TRvii (coins, i) {
			q.push(make_pair(*i, 1));
		}
		int foundAt = 0;
		while(!q.empty()) {
			pair<ii, int> queueItem = q.front();
			ii coinsSoFar = queueItem.first;
			int depth = queueItem.second;
			q.pop();
			cout << "Popped: " << coinsSoFar.first << "," << coinsSoFar.second << " @ " << depth << endl;
			if(searched.count(coinsSoFar) != 0) {
				continue;
			}
			searched[coinsSoFar] = 1;
			float eMod = sqrt(pow(coinsSoFar.first, 2) + pow(coinsSoFar.second, 2));
			if(eMod == s) {
				foundAt = depth;
				break;
			}
			else if(eMod < s) {
				TRvii(coins, i) {
					ii newPair = make_pair(coinsSoFar.first + i->first, coinsSoFar.second + i->second);
					q.push(make_pair(newPair, depth + 1));
				}
			}
		}
		cout << (foundAt == 0 ? "not possible" : to_string(foundAt)) << endl;
	}
	return 0;
}
