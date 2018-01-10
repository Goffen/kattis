#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

bool isMatch(map<char, vector<char>>& translations, char mapFrom, char to, int currentDepth, int maxDepth) {
	if(mapFrom == to) {
		return true;
	}
	if(maxDepth == currentDepth) {
		return false;
	}

	map<char, vector<char>>::iterator it = translations.find(mapFrom);
	if(it != translations.end()) {
		for(auto const& value: it->second) {
			if(value == '\0') {
				continue;
			}
			if(value == to || isMatch(translations, value, to, currentDepth + 1, maxDepth)) {
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	int m,n;
	cin >> m >> n;
	map<char, vector<char>> translationMap;

	for (int i = 0; i < m; ++i)
	{
		char from, to;
		cin >> from >> to;
		if(translationMap.find(from) == translationMap.end()) {
			vector<char> translations(1);
			translations.push_back(to);
			translationMap[from] = translations;
		}
		else {			
			translationMap[from].push_back(to);
		}
	}

	for (int i = 0; i < n; i++)
	{
		string char1, char2;
		cin >> char1 >> char2;
		if(char2.size() != char1.size()) {
			cout << "no" << endl;
			continue;
		}
		
		bool wordMatch = true;
		for (int j = 0; j < char2.size(); j++)
		{
			if(!isMatch(translationMap, char1[j], char2[j], 0, m)) {
				wordMatch = false;
			}			
		}
		cout << (wordMatch ? "yes" : "no") << endl;
	}
	return 0;
}


/* 

1 1
a b
aa ab

2 1
a b
b c
aa ac

4 1
a b
b c
c d
d h
aa af

1 1
a b
a c
aa bc

*/