#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;


int main(void) {
	int n;
	cin >> n;
	vector<string> c = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c.size(); ++j) {
			if(c[j] == s) {
				cout << j << " ";
			}
		}
	}
	return 0;
}

/* 

0  A
1  A#
2  B
3  C
4  C#
5  D
6  D#
7  E
8  F
9  F#
10 G
11 G#

tone, tone, tone, semitone, tone, tone, tone, semitone
2, 2, 2, 1, 2, 2, 2, 1

*/