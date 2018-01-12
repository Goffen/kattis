#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<string, int> msi;

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)


bool dfs(ii& newCoin, int toFind, vii& result, vii& coins, int depth) {
	if(depth > 5) {
		return false;
	}
	int convSum = 0, iSum = 0;
	cout << "New coin: " << newCoin.first << ", " << newCoin.second << endl;
	TRvii (result, v) { 
		convSum += v->first;
		iSum += v->second;
		cout << convSum << ", " << iSum << endl;
	}
	int eMod = sqrt(pow(convSum, 2) + pow(iSum, 2));
	cout << " = Emod: " << eMod << endl;

	if(toFind == eMod) {
		cout << "OMG hittade den!";
		return true;
	}

	for (int i = 0; i < coins.size(); ++i) {
		result.push_back(coins[i]);
		if(dfs(coins[i], toFind, result, coins, depth + 1)) {
			
			return true;
		}
	}
	
	return false;
}

int main(void) {
	int m, s;
	cin >> m >> s;

	vii coins;
	while(m--) {
		int convVal, infoVal;
		cin >> convVal >> infoVal;
		coins.push_back(make_pair(convVal, infoVal));
	}

	TRvii (coins, i) {
		cout << "C: " << i->first << ", E: " << i->second << endl;
	}

	
	//vii adjList[nrCoins * 10];
	//for (int i = 0; i < 10; i++) {
	//	vii neighbours;
	//	for (int j = 0; j < nrCoins; ++j) {
	//		neighbours.push_back(coins[j]);
	//	}
	//	AdjList[i] = neighbours;
	//}
	int nrCoins = coins.size();
	for (int j = 0; j < nrCoins; ++j) {
		vii result;
		dfs(coins[j], s, result, coins, 0);
	}
	

	// BFS
	//queue<int> q;
	//map<int,int> dist;
	//int s = 0;
	//q.push(s);
	//dist[s] = 0;
	//
	//while(!q.empty()) {
	//	int u = q.front();
	//	q.pop();
	//	printf("Visit %d, Layer %d\n", u, dist[u]);
	//	TRvi (AdjList[u], v) {
	//		int mappedCoin = *v
	//		if(!dist.count(mappedCoin)) {
	//			ii actualCoin = coins[mappedCoin % nrCoins];
	//			cout << "Coin"
//
	//			dist[mappedCoin] = dist[u] + 1;
	//			q.push(mappedCoin);
	//		}
	//	}
	//}

	cout << endl;

	return 0;
}
