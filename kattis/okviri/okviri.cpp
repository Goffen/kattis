#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	int size = s.size();

	for (int j = 0; j < 5; ++j) {
		bool superSpecialMiddle = false;
		for (int i = 0; i < s.size(); ++i) {
			bool endLine = i == size - 1;
			bool third = (i+1) % 3 == 0;
			char frame = third ? '*' : '#';
			

			if(j == 0 || j == 4) {
				cout << ".." << frame << ".";
			}
			else if(j == 1 || j == 3) {
				cout << "." << frame << "." << frame;
			}
			else {
				if(superSpecialMiddle) {
					cout << "*." << s[i] << ".";
					superSpecialMiddle = false;
				}
				else {
					cout << frame << "." << s[i] << ".";
				}
				if(third) {
					superSpecialMiddle = true;
				}
			}

			if(endLine) {
				if(j == 0 || j == 1 || j == 3 || j == 4) {
					cout << ".";
				}
				else {
					cout << frame;
				}
				cout << endl;
			}
		}
	}

	return 0;
}

/* 

..#..
.#.#.
#.A.#
.#.#.
..#..

..#...#...*..
.#.#.#.#.*.*.
#.D.#.O.*.G.*
.#.#.#.#.*.*.
..#...#...*..

..#...#...*...#..
.#.#.#.#.*.*.#.#.
#.A.#.B.*.C.*.D.#
.#.#.#.#.*.*.#.#.
..#...#...*...#..


rad 0: 
	alla: '..#.'
	slut: '..#..'

rad 1:
	alla: '.#.#'
	slut: '.#.#.'

rad 2:
	alla: '#.C.'
	slut: '#.D.#'
*/