#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct P {
	double x;
	double y;

	bool operator < (const P& p) const
	{
		return (x < p.x);
	}
};

int dist(P tsp[], int fromIndex, int toIndex) {
	double x = tsp[fromIndex].x - tsp[toIndex].x;
	double y = tsp[fromIndex].y - tsp[toIndex].y;
	double dist = round(sqrt(pow(x,2) + pow(y,2)));
	return dist;
}

void nearestNeighbourAlgorithm(P tsp[], int n) {
	int tour[n] = {0};
	bool used[n] = {true};

	cout << 0 << endl;

	for (int i = 1; i < n; i++)
	{
		int best = -1;
		for (int j = 0; j < n; j++)
		{
			if(!used[j] and (best == -1 or dist(tsp, tour[i-1], j) < dist(tsp, tour[i-1], best))) {
				best = j;
			}
		}
		tour[i] = best;
		used[best] = true;
		cout << best << endl;
	}
}

int main(void) {
	int n;
	cin >> n;
	P tsp[n];

	for (int i = 0; i < n; ++i)
	{
		double x, y;
		cin >> x >> y;
		tsp[i] = {x,y};
	}

	sort(tsp, tsp+n);
	nearestNeighbourAlgorithm(tsp, n);
    return 0;
}