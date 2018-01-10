#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int numberOfAtBats, atBat, totalNumberOfBases = 0, numberOfAtBatsWithNoWalk = 0;
	cin >> numberOfAtBats;
	for (int i = 0; i < numberOfAtBats; ++i)
	{
		cin >> atBat;
		if(atBat > -1) {
			totalNumberOfBases += atBat;
			numberOfAtBatsWithNoWalk += 1;
		}
	}
	cout << (totalNumberOfBases / (float)numberOfAtBatsWithNoWalk) << endl;

	//std::cout << numberOfAtBats << std::endl;
    return 0;
}