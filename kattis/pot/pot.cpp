#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int main(void) {
	string i;
	int n, powN, numN, x = 0;
	cin >> n;

	while(n--) {
		cin >> i;
		powN = i[i.size() - 1] - '0';
		numN = stoi(i.substr(0, i.size() - 1),nullptr, 10);
		x += pow(numN, powN);
	}

	cout  << x << endl;
	return 0;
}