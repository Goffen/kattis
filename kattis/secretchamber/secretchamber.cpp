#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

bool hasPossibleMultistepTranslation(int map[][26], int col) {
	for (int i = 0; i < 26; ++i) {
		if(map[i][col] == 1) {
			//cout << "multistep end found for [" << i << "][" << col << "]" << endl;
			return true;
		}
	}
	return false;
}

bool findTranslation(int map[][26], int row, int col) {
	if(row == col) {
		return true;
	}
	//cout << "[" << row << "][" << col << "] = " << map[row][col] << endl;
	if(map[row][col] == 1) {
		return true;
	}

	// check if any row has the col as an translation. Otherwise we dont have to look for it.
	if(!hasPossibleMultistepTranslation(map, col)) {
		return false;
	}

	vector<int> possibleRows(26);
	int size = 1;
	int searchedCols[26] = {-1};

	possibleRows.push_back(row);
	do {
		int possibleRow = possibleRows.back();
		//cout << "it: " << possibleRow << endl;
		possibleRows.pop_back();
		size--;
		if(searchedCols[possibleRow] == 1) {
			//cout << "we have already searched it: " << possibleRow << endl;
			continue;
		}
		for (int colIterator = 0; colIterator < 26; ++colIterator) {
			if(possibleRow != colIterator && map[possibleRow][colIterator]) {
				if(colIterator == col) {
					//cout << "i think i found it! [" << possibleRow << "][" << colIterator << "] is == " << col << endl;
					return true;
				}
				//cout << "push: new possible col: " << colIterator << endl;
				possibleRows.push_back(colIterator);
				size++;
			}
		}
		searchedCols[possibleRow] = 1;
		
	} while(size > 0);
	return false;
}

int main(void) {
	int m,n, offset = 97;
	cin >> m >> n;
	int map[26][26] = {0};

	for (int i = 0; i < m; ++i) {
		char from, to;
		cin >> from >> to;
		int fromI = from - offset, toI = to - offset;
		//cout << "[" << fromI << "][" << toI << "] = 1" << endl;
		map[fromI][toI] = 1;
	}

	//for (int col = 0; col < 26; ++col) {
	//	for (int row = 0; row < 26; ++row) {
	//		cout << (map[row][col] == 1 ? "1" : "0") << " ";
	//	}
	//	cout << endl;
	//}

	string words[n][2];

	for (int i = 0; i < n; i++) {
		string word1, word2;
		cin >> word1 >> word2;
		words[i][0] = word1;
		words[i][1] = word2;
	}

	for (int i = 0; i < n; ++i)
	{
		string word1 = words[i][0];
		string word2 = words[i][1];
		bool wordMatch = true;
		if(word1.size() != word2.size()) {
			cout << "no" << endl;
			continue;
		}

		for (int j = 0; j < word2.size(); j++) {
			if(!findTranslation(map, word1[j] - offset, word2[j] - offset)) {
				wordMatch = false;
			}
		}

		cout << (wordMatch ? "yes" : "no") << endl;
	}
	return 0;
}