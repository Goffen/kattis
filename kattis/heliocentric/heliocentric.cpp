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

int main(void) {
   string line;
   int caseNumber = 1;
	while(getline(cin, line)) {
      if(line.size()  == 0) {
         break;
      }
      istringstream l(line);
      int earth, mars, days = 0;
      l >> earth >> mars;

      while(!(earth == 0 && mars == 0)) {
         earth++;
         mars++;
         if(earth == 365) {
            earth = 0;
         }
         if(mars == 687) {
            mars = 0;
         }
         days++;
      }

      cout << "Case " << caseNumber << ": " << days << endl;
      caseNumber++;
   }
	return 0;
}