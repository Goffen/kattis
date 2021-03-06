#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main(void) {
	string password, message;
	cin >> password >> message;

	vector<char> foundChars;
	int passwordExpectedOrder = 0;
	REP (i, 0, message.size()) {
		char c = message[i];
		bool found = false;
		bool foundPasswordOutOfOrder = false;
		REP (j, 0, password.size()) {
			char p = password[j];
			bool hasAlreadyBeenFound = false;
			REP (k, 0, foundChars.size()) {
				if(p == foundChars[k]) {
					hasAlreadyBeenFound = true;
					break;
				}
			}
			if(hasAlreadyBeenFound) {
				continue;
			}
			if(c == p) {
				if(j != passwordExpectedOrder) {
					foundPasswordOutOfOrder = true;
					break;
				}
				found = true;
				foundChars.push_back(p);
				passwordExpectedOrder++;
				break;
			}
		}
		if(foundPasswordOutOfOrder){
			break;
		}
	}

	if(passwordExpectedOrder != password.size()) {
		cout << "FAIL";
	}
	else {
		cout << "PASS";
	}

	cout << endl;
	return 0;
}