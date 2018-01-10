#include <iostream>
#include <algorithm>

using namespace std;

int findTheOneGoingAlone(int guestCodes[], long size) {

	for (int i = 0; i < size; ++i)
	{
		int guestCode = guestCodes[i];
		bool foundMatch = false;
		for (int j = 0; j < size; ++j)
		{
			if(i == j) {
				// this is the one getting checked
				continue;
			}

			if(guestCode == guestCodes[j]) {
				// we found a match
				foundMatch = true;
				break;
			}
		}
		if(!foundMatch) {
			return guestCode;
		}
	}
}

int main(void) {
	int n, g;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> g;
		int guestCodes[g];
		for (int j = 0; j < g; ++j)
		{
			cin >> guestCodes[j];
		}
		cout << "Case #" << (i+1) << ": " << findTheOneGoingAlone(guestCodes, g) << endl;
	}
	
	cout << endl;

	//std::cout << numberOfAtBats << std::endl;
    return 0;
}