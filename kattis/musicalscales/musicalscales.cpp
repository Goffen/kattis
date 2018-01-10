#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

vector<string> c = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
int scales[12][8];
int scale[] = {0,2,4,5,7,9,11,12};

int strToI(string s) {
	for (int j = 0; j < c.size(); ++j) {
		if(c[j] == s) {
			return j;
		}
	}
	return -1;
}

void createScale(int note) {
	for (int i = 0; i < 7; ++i) {
		int adjustedNote = note + scale[i];
		if(adjustedNote > 11) {
			adjustedNote = adjustedNote - 12;
		}
		scales[note][i] = adjustedNote;
	}
}


bool addPresenseOfNote(int note, int presense[12]) {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 7; ++j) {
			if(scales[i][j] == note) {
				presense[i] = presense[i] + 1;
			}
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < 12; ++i) {
		createScale(i);
	}

	int presense[12] = {0};
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		addPresenseOfNote(strToI(s), presense);
	}

	vector<string> scalePresense;
	for (int i = 0; i < 12; ++i) {
		if(presense[i] == n) {
			scalePresense.push_back(c[i]);
		}
	}

	for (vector<string>::iterator it = scalePresense.begin() ; it != scalePresense.end(); ++it) {
		cout << *it;
		if(it != scalePresense.end() - 1) {
			cout << " ";
		}
	}

	if(scalePresense.empty()) {
		cout << "none";
	}

	cout << endl;

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
12 A = 12 - 12: 0
13 B = 13 - 12: 1

tone, tone, tone, semitone, tone, tone, tone, semitone
0, 2, 4, 5, 7, 9, 11, 12

[
	0, 2, 4, 5, 7, 9, 11, 12
	1, 3, 5, 6, 8, 10, 12, 13

]



*/