#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void balance(string &in) {
	char prevChar = '-';
	int i = -1;
	for(char& c : in) {
		i++;
		if(prevChar == '-') {
			prevChar = c;
			continue;
		}
		if(c == prevChar) {
			continue;
		}
		if(c != prevChar) {
			in.erase(i-1,2);
			break;
		}
	}
}

int main(void) {
	int lastLength;
	string in;
	cin >> in;

	do {
		lastLength = in.length();
		if(lastLength != 0) {
			balance(in);
		}
	}
	while(in.length() != lastLength);

	cout << (in.length() == 0 ? 1 : 0);
	return 0;
}
