#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;


int main(void) {
	
	string str;
	while(getline(cin, str)) {
		for(auto& x: str) {
			x = toupper(x);
		}
		cout << (str.find("PROBLEM") == string::npos ? "no" : "yes") << endl;
	}

	return 0;
}